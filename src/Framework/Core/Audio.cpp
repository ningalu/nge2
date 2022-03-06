#include "Audio.h"

#include <iostream>

namespace nge {
    // void ChunkDeleter::operator()(Mix_Chunk* chunk) {
    //     Mix_FreeChunk(chunk);
    // }

    // void MusicDeleter::operator()(Mix_Music* music) {
    //     Mix_FreeMusic(music);
    // }

    Audio::Audio() {
        Init();
    }

    void Audio::Init() {
        // int flags = MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG;
        // int initState = Mix_Init(flags);
        // if ((initState & flags) != flags) {
        //     std::cout << "Audio: Failed to initialise SDL_Mixer with compressed audio format support: " << Mix_GetError() << std::endl;
        // }
        // if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) != 0) {
        //     std::cout << "Audio: Failed to open audio: " << Mix_GetError() << std::endl;
        // }
    }

    // SoundPtr Audio::LoadSound(std::string path) {
    //     SoundPtr s;
    //     Mix_Chunk* chunk = Mix_LoadWAV(path.c_str());
    //     if (chunk == nullptr) {
    //         std::cout << "LoadEffect: Chunk could not be created from " << path << " :" << Mix_GetError() << std::endl;
    //         return s;
    //     }
    //     return SoundPtr(chunk);
    // }

    // SongPtr Audio::LoadSong(std::string path) {
    //     SongPtr s;
    //     Mix_Music* music = Mix_LoadMUS(path.c_str());
    //     if (music == nullptr) {
    //         std::cout << "LoadSong: Music could not be created from " << path << " :" << Mix_GetError() << std::endl;
    //         return s;
    //     }
    //     return SongPtr(music);
    // }

    // void Audio::PlaySound(Mix_Chunk* effect, int loops, int channel) {
    //     Mix_PlayChannel(channel, effect, loops);
    // }

    // void Audio::PlaySong(Mix_Music* song, int loops) {
    //     Mix_PlayMusic(song, loops);
    // }

    // void Audio::PauseSong() {
    //     if (Mix_PlayingMusic() != 0) {
    //         Mix_PauseMusic();
    //     }
    // }

    // void Audio::ResumeSong(){
    //     if (Mix_PausedMusic() != 0) {
    //         Mix_ResumeMusic();
    //     }
    // }
}