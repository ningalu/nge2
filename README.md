# NGE2

NGE2 is my second attempt at a larger scale C++ project that tries to consider non-code elements like build systems, portability, distribution, etc. as well as slightly higher level design decisions like usability as a library, compilation/linking order, and module dependencies within the project. It is built with CMake and wraps the SDL2 libraries. It is designed to give structure and utilities to GUI projects and games I might want to make. 

## TODO notes:
reexamine usage of shared pointer and object ownerships
concept of automatic z levels for drawables instead of forced user defined draw orders per state (sort on every insertion to drawing list?)
const correctness, pass by reference, inline where applicable
fix namespacing and include guards
button construction is convoluted
improve templating of initial state creation
move input processing into states?
input handling needs a longer history of mouse and keyboard states to allow buffers of precision, like allowing a 5 frame buffer before an input is considered "held"
dedicated resource loader? would be another annoying dependency to pass in

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

3: pass a fully constructed State object to the child state
you take a correctly constructed and initialised state created by the game class as an argument to your new state's ctor
\+ you only need to implement a ctor and not a separate Init method, reducing boilerplate and ambiguity between construction and initialisation
\+ i can add as many dependencies as i want for state, like a resource manager or if sound becomes non static, and you wont have to change the ctor of every single state to accept more arguments
\+ doesnt require exposing base State fields that can be messed with as in 2
\- you need a "magic" parameter to your ctor
\- confusing when setting initial state as there will be a discrepancy between the parameters in the ctor and the parameters actually passed in, since the state that would be passed in would be created by the Game and would therefore be inaccessible to the user

4: change the State model entirely?
maybe separate fundamental state behaviour and user defined state behaviour, and connect the two by means other than inheritance?
eg. Game.SetInitialState\<State\<InitialStateModel\>\>(InitialStateModelArgs...)
\