#ifndef _FRAMEWORK_CORE_AUDIO_H
#define _FRAMEWORK_CORE_AUDIO_H

#include <memory>
#include <string>

#include "SDL2/SDL_mixer.h"

namespace nge {

    struct ChunkDeleter {
        void operator()(Mix_Chunk* chunk);
    };

    struct MusicDeleter {
        void operator()(Mix_Music* music);
    };

    using SoundPtr = std::unique_ptr<Mix_Chunk, ChunkDeleter>;
    using SongPtr = std::unique_ptr<Mix_Music, MusicDeleter>;
                                                                        
    //                     ██████████                                  
    //                   ██░░░░░░░░░░██                                
    //                 ██░░░░░░░░░░░░░░██                              
    //                 ██░░░░░░░░████░░██████████                      
    //     ██          ██░░░░░░░░████░░██▒▒▒▒▒▒██                      
    //   ██░░██        ██░░░░░░░░░░░░░░██▒▒▒▒▒▒██                      
    //   ██░░░░██      ██░░░░░░░░░░░░░░████████                        
    // ██░░░░░░░░██      ██░░░░░░░░░░░░██                              
    // ██░░░░░░░░████████████░░░░░░░░██                                
    // ██░░░░░░░░██░░░░░░░░░░░░░░░░░░░░██                              
    // ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██                            
    // ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██                            
    // ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██                            
    // ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██                            
    // ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██                            
    // ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██                              
    //   ██░░░░░░░░░░░░░░░░░░░░░░░░░░██                                
    //     ██████░░░░░░░░░░░░░░░░████                                  
    //           ████████████████                                                     
    // This class doesn't have a specific audio context like graphics has a rendering context or window
    // That means hypothetically everything here could be static
    // That would conflict stylistically with the graphics but would be really convenient
    // Why not just make everything in graphics static?
    // It needs a specific instance of a renderer and window
    // Why not make it a singleton?
    // Formally it might be useful to be able to switch windows and renderers
    // Informally I tried making graphics a singleton once and didn't really like it
    // It doesnt actually matter much
    class Audio {
        public:
            // Leave these in case I want to make this not totally static for some reason
            Audio();

            static void Init();

            static SoundPtr LoadSound(std::string path);
            static SongPtr LoadSong(std::string path);

            static void PlaySound(Mix_Chunk* sound, int loops = 0, int channel = 0);

            static void PlaySong(Mix_Music* song, int loops = -1);
            static void PauseSong();
            static void ResumeSong();

            ~Audio();

        private:

    };
}

#endif