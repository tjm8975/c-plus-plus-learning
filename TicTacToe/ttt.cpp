#include <iostream>
#include <vector>
#include <string>
#include "ttt_functions.hpp"

using namespace std;

int main() {
    vector<char> board;
    bool play_again = true;
    bool game_over = false;

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