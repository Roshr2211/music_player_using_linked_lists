# Music Player

This is a simple command-line music player written in C, organized into modular components. It allows you to manage a playlist of songs, play songs, add songs, and perform various playlist-related actions.

## Features

- Add songs to the playlist.
- Display the current playlist.
- Play the next song.
- Play a song from the queue.
- Insert a song into the queue.
- Reverse the playlist.
- Swap songs in the playlist.
- Shuffle the playlist.
- Basic error handling for invalid inputs.

## Usage

1. Compile the program:
   ```bash
   gcc -o music_player song.c playlist.c music_player.c
2 Run the complied program   
 ``` ./music_player ```



## File Structure
*song.h and song.c: Define and implement the Song structure and related functions.
*playlist.h and playlist.c: Define and implement the Playlist structure and related functions.
*music_player.c: The main program that uses the song and playlist functions to create the music player.

## Menu Options
1)Add a song: Add a song to the playlist.
2)Display playlist: View the current playlist.
3)Play the next song: Play the next song in the playlist.
4)Play a song from the queue: Play a specific song from the queue by its position.
5)Insert a song into the queue: Insert a song into the queue at a specified position.
6)Reverse the playlist: Reverse the order of songs in the playlist.
7)Swap songs: Swap the positions of two songs in the playlist.
8)Shuffle the playlist: Shuffle the songs in the playlist.
9)Exit: Quit the music player.

## Notes
The program initializes with an empty playlist.
When choosing to play the next song, the program will skip the current song and play the one following it.
Use the other options to manage your playlist and queue of songs.
