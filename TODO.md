## TODO notes:
- reexamine usage of shared pointer and object ownerships
- concept of automatic z levels for drawables instead of forced user defined draw orders per state (sort on every insertion to drawing list?)
- const correctness, pass by reference, inline where applicable
- ~fix namespacing and include guards~ DONE
- button construction is convoluted
- ~improve templating of initial state creation~ -DONE
- ~move input processing into states?~ DONE
- input handling needs a longer history of mouse and keyboard states to allow buffers of precision, like allowing a 5 frame buffer before an input is considered "held"
- dedicated resource loader? ~would be another annoying dependency to pass in~ not that annoying anymore
- ~this kinda needs a more robust event listener system. could write my own~ probably gonna just use sigslots
- input class was literally just ripped from old project and i want to overhaul it since it feels really clumsy to use. maybe shift sdl event processing to inputs and register to inputs as well? essentially make the input class responsible for acting on user input in addition to just observing it as it does now
- how should text be handled? feels like it shouldnt warrant its own class since plain text is functionally just a sprite
- fix cmake so it doesnt depend on my file system
- the entire drawing system is super clumsy; it should be easier to position objects relative to one another and defining destination rect size is a pain, maybe binding objects relative positions. might need CSTs or at least some linear algebra
- ~NEED a base drawable class holy shit~ ~need to reexamine the concept of drawable objects.~ IN PROGRESS

# game states
you should be able to inherit from state, write a constructor with only objects you actually want to pass in, write your draw and tick methods, and not have to worry about passing in game level dependencies like graphics or the state manager. solutions are a bit annoying.

1: separate construction and initialisation
you have to write a ctor that handles being passed whatever dependencies the game wants to give you, and then an Init function that actually has your setup. the game object will call your ctor with the right dependencies and then run the particular state's Init with the supplied arguments  
\+ you dont have to worry about what the game is actually injecting to your state  
\+ the "magic" injected parameters are separated from your own personal inputs to your state  
\- you have a bunch of magic parameters to your ctor that you need to boilerplate away  
\- the number of magic parameters might change as the base State needs more things  

2: no user construction  
your state is default constructed, its dependencies are set externally by the game, and then an Init method is called  
\+ you dont need to write an actual ctor, only supply an empty default one  
\+ there is no ambiguity between construction and initialisation, since the ctor will just always be empty  
\- the base State class will have to expose methods to set its dependencies after construction, either giving the user the ability to arbitrarily set (and therefore invalidate) any other State's dependencies they want, or requiring that the base State's setters for these dependencies are friends to the Game class  
\- you still have to write a bit more boilerplate than is absolutely necessary with the empty default ctor  

3: pass a fully constructed State object to the child state \<-- this for now  
you take a correctly constructed and initialised state created by the game class as an argument to your new state's ctor  
\+ you only need to implement a ctor and not a separate Init method, reducing boilerplate and ambiguity between construction and initialisation  
\+ i can add as many dependencies as i want for state, like a resource manager or if sound becomes non static, and you wont have to change the ctor of every single state to accept more arguments  
\+ doesnt require exposing base State fields that can be messed with as in 2  
\- you need a "magic" parameter to your ctor  
\- confusing when setting initial state as there will be a discrepancy between the parameters in the ctor and the parameters actually passed in, since the state that would be passed in would be created by the Game and would therefore be inaccessible to the user  

4: change the State model entirely?  
maybe separate fundamental state behaviour and user defined state behaviour, and connect the two by means other than inheritance?  
eg. Game.SetInitialState\<State\<InitialStateModel\>\>(InitialStateModelArgs...)  
\- the model wouldn't have enough information about its container State to do things like create textures without encountering the same types of problems surrounding passing dependencies like graphics and state management   
\- requires users to double template something which is slightly cringe  

# Drawing

## Drawables
what does it mean to be Drawable?  
if an object is Drawable, it can be drawn, and it occupies some space on the screen. for a simple sprite or piece of text this might be a single sdl_rect but maybe you will have a character sprite composed of several limbs. in that case strictly speaking the sprite will only occupy a shape on the screen defined by some contour rather than a rectangle. interfaces name behaviours of their implementors, so it doesnt really make sense to have some kind of GetDestinationRectangle method on the Drawable interface. i should instead consider the reasons you would need the destination rectangle, or need to know a Drawable's position or dimensions. two reasons i can think of are calculating overlaps and aligning two objects. therefore those behaviours should be potential behaviours should be added to Drawable. it would be nice to be able to write something like  

```if (MyDrawableImpl1.Overlaps(MyDrawableImpl2) {do something}```

but to pass a pointer to this method you would need a way to get space occupied on the screen from the Drawable interface. the solution will probably have to be to pass the space occupied as a shape. this can be an SDL_Rect temporarily.  
alignment will probably need to split into something like AlignHorizontal and AlignVertical  

```MyDrawableImpl1.AlignHorizontal(50)```  

then again, should an object being drawable on the screen imply that it can be aligned (moved)? i have a Translatable interface but is it meaningful to have? in practice, the Drawable interface will probably be used to programmatically Draw a collection of Drawable objects. a user shouldnt have to define what it means for their own implementation of a Drawable to be aligned with something if all they want to do is register it to some list of Drawables. I think therefore the Translatable interface makes sense. 

## Translatables
being Translatable is a lot easier to define than being Drawable. Translatables will require methods that set or increment their position on screen. alignment is technically different from just setting a position because you will typically require information about the visual size of some graphic in order to align it appropriately, so the alignment methods can go on it too.

## Rotatables
rotation is even simpler because alignment of rotation is just setting a rotation, and has nothing to do with a graphics dimensions. all it needs is the ability to set and increment an angle.

## Single-Texture Drawable Functionality
there was/is massive code redundancy between Text, Sprite/AnimatedSprite, and Button. i would like to take this redundancy out of text and sprite and maybe revise how buttons work.

### SimpleDrawableBase
a SimpleDrawableBase will be an abstract class with source and destination rectangles and convenience methods common to Text and Sprite. it will inherit from all of Drawable, Translatable, and Rotatable.

# Dependencies
there are no sdl distributions for windows/mingw or apple m1 but configuring the submodules in all of my cmakelists for all my subdirectories is hard and i get weird runtime issues. for now ill probably just use conan distributions. ~in this case i need a way of automatically copying the dlls and resources to the output directory.~ this is done for dlls and for resources in my current machine dependent configuration so i need to figure out how to actually use the sdl distribution from conan. there is no official sdl mixer package for conan.

# Testing
making a few quick and dirty test suites is not that hard but i would like to practice using industry standard testing libraries. i would also like to try to set up some kind of ci. travis seems like a popular ci thing. ive used teamcity before which apparently has free stuff? i could try compiling and running tests with docker on a local machine as well and docker would be a good thing to learn about