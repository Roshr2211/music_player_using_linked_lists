#include "song.h"
#include <stdlib.h>
#include <string.h>

struct Song* createSong(char* title, char* artist) {
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->next = NULL;
    return newSong;
}
