#ifndef AUDIO_PLAYER_H
#define AUDIO_PLAYER_H

// Initialize the audio player
void init_audio_player();

// Play audio from an MP3 file
void play_audio(const char* audioFile);

// Clean up and close the audio player
void shutdown_audio_player();

#endif
