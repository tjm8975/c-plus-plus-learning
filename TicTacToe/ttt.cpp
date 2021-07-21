#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <ctime>
#include "ttt_functions.hpp"

using namespace std;

int main() {
    // Initialized with numbers for printing the intro
    vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    vector<int> open_tiles = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> player_tiles, cpu_tiles;
    bool play_again = true;
    bool game_over = false;

    srand(time(NULL));

    greet(board);  // Displays intro and instructions

    // Main loop that allows multiple games to be played
    while (play_again) {
        reset_vectors(board, open_tiles, player_tiles, cpu_tiles);

        // Randomly pick which player goes first (human or computer)
        cout << "Randomly picking who will go first ..." << endl;
        Sleep(1000);
        bool human_first = rand() % 2;
        human_first ? cout << "You get to go first." << endl : cout << "Computer gets to go first." << endl;
        
        display_board(board);
        int move_count = 0;

        // Inner loop that runs a single game
        while (!game_over && !open_tiles.empty()) {
            if (human_first) {
                general_player_move(board, open_tiles, player_tiles, move_count);  // Human player goes first
                if (first_player_win(move_count, player_tiles, game_over)) {
                    break;  // Second player can't make another move if first player won
                }
                general_player_move(board, open_tiles, cpu_tiles, move_count, true);  // Computer player goes second
                second_player_win(move_count, cpu_tiles, game_over, true);
            } else {
                general_player_move(board, open_tiles, cpu_tiles, move_count, true);  // Computer player goes first
                if (first_player_win(move_count, cpu_tiles, game_over, true)) {
                    break;  // Second player can't make another move if first player won
                }
                general_player_move(board, open_tiles, player_tiles, move_count);  // Human player goes second
                second_player_win(move_count, player_tiles, game_over);
            }
        }
        // Prompt user for a rematch
        play_again = rematch();
        game_over = false;  // Allow inner loop to run again
    }
}