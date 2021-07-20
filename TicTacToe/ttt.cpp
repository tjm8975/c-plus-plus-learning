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

    // Main loop that allows multiple games to be played
    while (play_again) {
        reset_vectors(board, open_tiles, player_tiles, cpu_tiles);
        display_board(board);
        int move_count = 0;
        // Inner loop that runs a single game
        while (!game_over && !open_tiles.empty()) {
            // Player turn
            player_move(board, open_tiles, player_tiles);
            display_board(board);
            move_count++;
            //test_vectors(open_tiles, player_tiles, cpu_tiles); For testing, remove before final revision
            // Check if player won
            if (move_count >= 5) {  // 5 total moves needed before player can win
                if (check_win_conditions(player_tiles)) {
                    game_over = true;
                    cout << "You won!" << endl;
                    break;  // Computer can't make any more moves
                }
                // Check for tie
                if (move_count == 9) {
                    cout << "It's a tie!" << endl;
                    break;  // Computer can't make any more moves
                }
            }
            // Computer turn
            cout << "\nComputer is picking a move ..." << endl;
            Sleep(1000);
            cpu_move(board, open_tiles, cpu_tiles);
            display_board(board);
            move_count++;
            //test_vectors(open_tiles, player_tiles, cpu_tiles); For testing, remove before final revision
            // Check if computer won
            if (move_count >= 6) {  // 6 total moves needed before cpu can win
                if (check_win_conditions(cpu_tiles)) {
                    game_over = true;
                    cout << "You lost! Better luck next time." << endl;
                }
            }
        }
        // Prompt user for a rematch
        play_again = rematch();
        game_over = false;  // Allow inner loop to run again
    }
}