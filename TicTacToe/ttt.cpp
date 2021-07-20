#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "ttt_functions.hpp"

using namespace std;

int main() {
    // Initialized with numbers for printing the intro
    vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    vector<int> open_tiles = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> player_tiles, cpu_tiles;
    bool play_again = true;
    bool game_over = false;

    greet(board);  // Displays intro and instructions

    // Main loop that allows multiple rounds to be played
    while (play_again) {
        reset_vectors(board, open_tiles, player_tiles, cpu_tiles);
        display_board(board);
        int move_count = 0;
        // Inner loop that runs a single round
        while (!game_over) {
            // Player turn
            cout << "Your turn." << endl;
            player_move(board, open_tiles, player_tiles);
            display_board(board);
            move_count++;
            // Computer turn
            cout << "\nComputer is picking a move ..." << endl;
            Sleep(1000);
            cpu_move(board, open_tiles, cpu_tiles);
            display_board(board);
            move_count++;
            // Test print vectors to check for updates
            //test_vectors(board, open_tiles, player_tiles, cpu_tiles);
            game_over = true;  // Terminate loop for inital testing
        }
        // Prompt user for a rematch
        play_again = rematch();
        game_over = false;  // Allow inner loop to run again
    }
}