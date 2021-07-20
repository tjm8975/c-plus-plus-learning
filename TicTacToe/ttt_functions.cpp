#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

// Returns a vector representing an empty board
void reset_vectors(vector<char> &board, vector<int> &open_tiles, vector<int> &player_tiles, vector<int> &cpu_tiles) {
    board = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    open_tiles = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    player_tiles.clear();
    cpu_tiles.clear();
}

// Helper function to print out a row of the game board.
// Takes in int start to determine which row is being printed.
void display_spaces(vector<char> board, int start) {
    cout << " " << board[start]  << " | "  << board[start + 1] << " | " \
    << board[start + 2] << " \n";
}

// Helper function to print out the horizontal dividing lines of the board.
void display_lines() {
    cout << "---|---|---\n";
}

// "Pretty prints" the game board based on the values held in the vector.
void display_board(vector<char> board) {
    display_spaces(board, 0);
    display_lines();
    display_spaces(board, 3);
    display_lines();
    display_spaces(board, 6);
}

// Displays the intro and instructions for the game.
// The passed board will always have values 1 through 9.
// Waits for the player to start the game.
void greet(vector<char> board) {
    cout << "===========\n";
    cout << "Tic-Tac-Toe\n";
    cout << "===========\n";
    cout << "Instructions: Each tile on the board is represented by a number as shown below.\nEnter a number to mark an X on the board in that position.\n";
    display_board(board);
    cout << endl;
    // Prompt user to begin when ready
    string answer = "";
    while (answer != "y") {
        cout << "Press 'y' to begin: ";
        cin >> answer;
    }
    cout << endl;
}

// Prompts the user for a rematch and returns true if yes, false otherwise.
bool rematch() {
    string answer;
    cout << "Would you like to play again (y/n)? ";
    cin >> answer;
    cout << endl;
    return answer == "y";
}

// Helper function to determine if the provided tile is open.
// Removes the tile from the vector of open tiles if true.
bool is_open_tile(int tile, vector<int> &open_tiles) {
    for (int i = 0; i < open_tiles.size(); i++) {
        if (tile == open_tiles[i]) {
            // Remove selected tile from open tiles
            open_tiles.erase(open_tiles.begin() + i);
            return true;
        }
    }
    return false;
}

// Prompts the user to enter their move.
// Input is an int that represents the tile which the player wishes to mark.
// Vectors passed by reference to allow updates.
// Tile number is added to vector tracking player tiles.
// Tile is marked in board vector.
void player_move(vector<char> &board, vector<int> &open_tiles, vector<int> &player_tiles) {
    int move;
    cout << "Please enter your move: ";
    cin >> move;
    // Check if valid move
    while (!is_open_tile(move, open_tiles)) {
        cout << endl;
        cout << "Invalid move.\nPlease enter a different move: ";
        cin >> move;
    }
    // Updated tracking vectors
    player_tiles.push_back(move);
    board[move - 1] = 'X';
}

// Simulates the computer choosing a move.
// Randomly picks an open tile and marks it.
void cpu_move(vector<char> &board, vector<int> &open_tiles, vector<int> &cpu_tiles) {
    int num_open_tiles = open_tiles.size();
    int move;
    srand(time(NULL));
    move = rand() % num_open_tiles;
    cpu_tiles.push_back(open_tiles[move]);
    board[open_tiles[move] - 1] = 'O';
}

// Helper function to print out any vector<int>
void vector_print(vector<int> vect) {
    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i] << " ";
    }
    cout << endl;
}

// Prints out each vector for testing purposes
void test_vectors(vector<char> board, vector<int> open_tiles, vector<int> player_tiles, vector<int> cpu_tiles) {
    display_board(board);
    vector_print(open_tiles);
    vector_print(player_tiles);
    vector_print(cpu_tiles);
}

// Helper function that finds out if a player has marked a specific tile
// Returns true if the player has that tile marked
bool has_tile(int tile, vector<int> moves) {
    return find(moves.begin(), moves.end(), tile) != moves.end();
}

// Checks all 3 vertical win conditions for a given vector of moves
bool check_vertical(vector<int> moves) {
    // Needs to have tiles 1, 4, 7 to win in first column
    if (has_tile(1, moves)) {
        if (has_tile(4, moves)) {
            if (has_tile(7, moves)) {
                return true;
            }
        }
    } else if (has_tile(2, moves)) {
        if (has_tile(5, moves)) {
            if (has_tile(8, moves)) {
                return true;
            }
        }
    } else if (has_tile(3, moves)) {
        if (has_tile(6, moves)) {
            if (has_tile(9, moves)) {
                return true;
            }
        }
    }
    // Player doesn't have any column filled with 3 marks
    return false;
}

// Checks all win conditions for a given player
bool check_win_conditions(vector<int> moves) {
    //if (check_vertical(moves)) {
        //return true;
    //}
    return true;
}