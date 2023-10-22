#include "playlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to play the next song
void playNext(struct Playlist* playlist) {
    if (playlist->head != NULL) {
        struct Song* current = playlist->head->next;
        if (current != NULL) {
            printf("Now playing: %s by %s\n", current->title, current->artist);
        } else {
            printf("No more songs in the playlist.\n");
        }
    } else {
        printf("Playlist is empty.\n");
    }
}

// Function to play the previous song
void playPrevious(struct Playlist* playlist) {
    if (playlist->head != NULL) {
        printf("Cannot play previous song in this basic player.\n");
    } else {
        printf("Playlist is empty.\n");
    }
}

// Function to play a song from the queue
void playFromQueue(struct Playlist* playlist, int position) {
    if (position < 1) {
        printf("Invalid position. Queue positions start at 1.\n");
        return;
    }

    struct Song* current = playlist->head;
    int currentPosition = 0;
    while (current != NULL) {
        currentPosition++;
        if (currentPosition == position) {
            printf("Now playing: %s by %s\n", current->title, current->artist);
            return;
        }
        current = current->next;
    }

    if (position > currentPosition) {
        printf("Position out of range. The queue has only %d songs.\n", currentPosition);
    }
}

// Function to insert a song into the queue
void insertToQueue(struct Playlist* playlist, char* title, char* artist) {
    char positionStr[10];
    int position;

    printf("Enter the position to insert the song (1 for the first, 0 to cancel): ");
    scanf("%s", positionStr);

    if (sscanf(positionStr, "%d", &position) != 1 || position < 1) {
        printf("Invalid position. Song not inserted.\n");
        return;
    }

    if (position == 1 || playlist->head == NULL) {
        addSong(playlist, title, artist);
    } else {
        struct Song* newSong = createSong(title, artist);
        struct Song* current = playlist->head;
        int currentPosition = 1;

        while (current != NULL && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }

        if (current != NULL) {
            newSong->next = current->next;
            current->next = newSong;
        } else {
            printf("Position out of range. Song not inserted.\n");
            free(newSong);
        }
    }
}

// Function to reverse the playlist
void reversePlaylist(struct Playlist* playlist) {
    struct Song* prev = NULL;
    struct Song* current = playlist->head;
    struct Song* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    playlist->head = prev;
}

// Function to swap two songs in the playlist
void swapSongs(struct Playlist* playlist, int position1, int position2) {
    if (position1 == position2) {
        return;  // No need to swap if positions are the same
    }

    struct Song* prev1 = NULL;
    struct Song* prev2 = NULL;
    struct Song* current1 = playlist->head;
    struct Song* current2 = playlist->head;
    int currentPosition = 1;

    while (current1 != NULL && currentPosition < position1) {
        prev1 = current1;
        current1 = current1->next;
        currentPosition++;
    }

    currentPosition = 1;

    while (current2 != NULL && currentPosition < position2) {
        prev2 = current2;
        current2 = current2->next;
        currentPosition++;
    }

    if (current1 == NULL || current2 == NULL) {
        printf("Invalid positions. Unable to swap songs.\n");
        return;
    }

    if (prev1 != NULL) {
        prev1->next = current2;
    } else {
        playlist->head = current2;
    }

    if (prev2 != NULL) {
        prev2->next = current1;
    } else {
        playlist->head = current1;
    }

    struct Song* temp = current1->next;
    current1->next = current2->next;
    current2->next = temp;
}

// Function to shuffle the playlist
void shufflePlaylist(struct Playlist* playlist) {
    int numSongs = 0;
    struct Song* current = playlist->head;
    while (current != NULL) {
        numSongs++;
        current = current->next;
    }

    if (numSongs <= 1) {
        printf("Insufficient songs to shuffle.\n");
        return;
    }

    // Create an array of pointers to the songs
    struct Song** songsArray = (struct Song**)malloc(numSongs * sizeof(struct Song*));
    current = playlist->head;
    for (int i = 0; i < numSongs; i++) {
        songsArray[i] = current;
        current = current->next;
    }

    // Use the Fisher-Yates shuffle algorithm to shuffle the array
    srand(time(NULL));
    for (int i = numSongs - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        struct Song* temp = songsArray[i];
        songsArray[i] = songsArray[j];
        songsArray[j] = temp;
    }

    // Reconstruct the shuffled playlist
    playlist->head = songsArray[0];
    current = playlist->head;
    for (int i = 1; i < numSongs; i++) {
        current->next = songsArray[i];
        current = current->next;
    }
    current->next = NULL;

    free(songsArray);
}

int main() {
    struct Playlist playlist;
    initPlaylist(&playlist);
    int choice;
    char title[100], artist[100];
    int position1, position2;

    do {
        printf("Music Player Menu:\n");
        printf("1. Add a song\n");
        printf("2. Display playlist\n");
        printf("3. Play the next song\n");
        printf("4. Play a song from the queue\n");
        printf("5. Insert a song into the queue\n");
        printf("6. Reverse the playlist\n");
        printf("7. Swap songs\n");
        printf("8. Shuffle the playlist\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the title of the song: ");
                scanf("%s", title);
                printf("Enter the artist: ");
                scanf("%s", artist);
                addSong(&playlist, title, artist);
                break;
            case 2:
                displayPlaylist(&playlist);
                break;
            case 3:
                playNext(&playlist);
                break;
            case 4:
                printf("Enter the position of the song to play: ");
                scanf("%d", &position1);
                playFromQueue(&playlist, position1);
                break;
            case 5:
                printf("Enter the title of the song: ");
                scanf("%s", title);
                printf("Enter the artist: ");
                scanf("%s", artist);
                insertToQueue(&playlist, title, artist);
                break;
            case 6:
                reversePlaylist(&playlist);
                printf("Playlist reversed.\n");
                break;
            case 7:
                printf("Enter the positions of two songs to swap: ");
                scanf("%d %d", &position1, &position2);
                swapSongs(&playlist, position1, position2);
                break;
            case 8:
                shufflePlaylist(&playlist);
                printf("Playlist shuffled.\n");
                break;
            case 9:
                freePlaylist(&playlist);
                printf("Exiting the music player.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);

    return 0;
}
