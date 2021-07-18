#include <iostream>
#include <vector>
#include <string>
#include "ttt_functions.hpp"

using namespace std;

int main() {
    // Initialized with numbers for printing the intro
    vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool play_again = true;
    bool game_over = false;

    greet(board);  // Displays intro and instructions

    // Main loop that allows multiple rounds to be played
    while (play_again) {
        board = reset_board();  // Makes an empty board
        // Inner loop that runs a single round
        while (!game_over) {
            display_board(board);
            game_over = true;  // Terminate loop for inital testing
        }
        // Prompt user for a rematch
        play_again = rematch();
        game_over = false;  // Allow inner loop to run again
    }
}