#include "playlist.h"
#include<stdlib.h>
#include <stdio.h>

void initPlaylist(struct Playlist* playlist) {
    playlist->head = NULL;
}

void addSong(struct Playlist* playlist, char* title, char* artist) {
    struct Song* newSong = createSong(title, artist);

    if (playlist->head == NULL) {
        playlist->head = newSong;
    } else {
        struct Song* current = playlist->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newSong;
    }
}

void displayPlaylist(struct Playlist* playlist) {
    struct Song* current = playlist->head;

    if (current == NULL) {
        printf("Playlist is empty.\n");
    } else {
        printf("Playlist:\n");
        while (current != NULL) {
            printf("Title: %s, Artist: %s\n", current->title, current->artist);
            current = current->next;
        }
    }
}

void freePlaylist(struct Playlist* playlist) {
    while (playlist->head != NULL) {
        struct Song* temp = playlist->head;
        playlist->head = playlist->head->next;
        free(temp);
    }
}
