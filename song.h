#ifndef SONG_H
#define SONG_H

struct Song {
    char title[100];
    char artist[100];
    struct Song* next;
};

struct Song* createSong(char* title, char* artist);

#endif
