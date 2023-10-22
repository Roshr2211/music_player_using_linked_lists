// #include "audio_player.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <mpg123.h>
// #include <portaudio.h>

// #define SAMPLE_RATE 44100
// #define FRAMES_PER_BUFFER 256

// mpg123_handle *mpg123;
// PaStream *stream;

// // Initialize the audio player
// void init_audio_player() {
//     mpg123_init();
//     mpg123 = mpg123_new(NULL, NULL);
//     mpg123_open(mpg123);
//     mpg123_format_none(mpg123);
//     mpg123_format(mpg123, SAMPLE_RATE, MPG123_MONO, MPG123_ENC_SIGNED_16);

//     Pa_Initialize();
//     Pa_OpenDefaultStream(&stream, 0, 1, paInt16, SAMPLE_RATE, FRAMES_PER_BUFFER, NULL, NULL);
//     Pa_StartStream(stream);
// }

// // Play audio from an MP3 file
// void play_audio(const char* audioFile) {
//     int error;
//     size_t bufferSize;
//     unsigned char buffer[FRAMES_PER_BUFFER * 2]; // Stereo

//     FILE *file = fopen(audioFile, "rb");
//     if (file == NULL) {
//         fprintf(stderr, "Failed to open audio file: %s\n", audioFile);
//         return;
//     }

//     while (1) {
//         error = mpg123_read(mpg123, buffer, sizeof(buffer), &bufferSize);
//         if (error == MPG123_DONE) {
//             break;
//         }
//         Pa_WriteStream(stream, buffer, bufferSize / 2); // Divide by 2 for stereo to mono conversion
//     }

//     fclose(file);
// }

// // Clean up and close the audio player
// void shutdown_audio_player() {
//     mpg123_close(mpg123);
//     mpg123_delete(mpg123);
//     mpg123_exit();

//     Pa_StopStream(stream);
//     Pa_CloseStream(stream);
//     Pa_Terminate();
// }
