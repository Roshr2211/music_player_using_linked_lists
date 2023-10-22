#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "song.h"

struct Playlist {
    struct Song* head;
};

void initPlaylist(struct Playlist* playlist);
void addSong(struct Playlist* playlist, char* title, char* artist);
void displayPlaylist(struct Playlist* playlist);
void freePlaylist(struct Playlist* playlist);

#endif
