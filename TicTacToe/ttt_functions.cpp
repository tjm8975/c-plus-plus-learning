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
    cout << "\nPlease enter your move: ";
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
    int move_index;
    srand(time(NULL));
    move_index = rand() % num_open_tiles;
    int move = open_tiles[move_index];
    cpu_tiles.push_back(move);
    board[move - 1] = 'O';
    open_tiles.erase(open_tiles.begin() + move_index);
}

// Helper function to print out any vector<int>
void vector_print(vector<int> vect) {
    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i] << " ";
    }
    cout << endl;
}

// Prints out each vector for testing purposes
void test_vectors(vector<int> open_tiles, vector<int> player_tiles, vector<int> cpu_tiles) {
    cout << "\nOpen Tiles: ";
    vector_print(open_tiles);
    cout << "\nPlayer Tiles: ";
    vector_print(player_tiles);
    cout << "\nComputer Tiles: ";
    vector_print(cpu_tiles);
    cout << endl;
}

// Helper function that finds out if a player has marked a specific tile
// Returns true if the player has that tile marked
bool has_tile(int tile, vector<int> moves) {
    return find(moves.begin(), moves.end(), tile) != moves.end();
}

// Helper function to check any column for a win
bool check_vertical(int column, vector<int> moves) {
    if (has_tile(column, moves)) {
        if (has_tile(column + 3, moves)) {
            if (has_tile(column + 6, moves)) {
                return true;
            }
        }
    }
    return false;
}

// Checks all 3 vertical win conditions for a given vector of moves
bool check_all_verticals(vector<int> moves) {
    if (check_vertical(1, moves)) {  // Check first column
        return true;
    } else if (check_vertical(2, moves)) {  // Check second column
        return true;
    } else if (check_vertical(3, moves)) {  // Check third column
        return true;
    }
    // Player doesn't have any column filled with 3 marks
    return false;
}

// Helper function to check any row for a win
// int row == 1 for row 1, 4 for row 2, and 7 for row 3
bool check_horizontal(int row, vector<int> moves) {
    if (has_tile(row, moves)) {
        if (has_tile(row + 1, moves)) {
            if (has_tile(row + 2, moves)) {
                return true;
            }
        }
    }
    return false;
}

// Checks all 3 horizontal win conditions for a given vector of moves
bool check_all_horizontals(vector<int> moves) {
    if (check_horizontal(1, moves)) {  // Check first row
        return true;
    } else if (check_horizontal(4, moves)) {  // Check second row
        return true;
    } else if (check_horizontal(7, moves)) {  // Check third row
        return true;
    }
    // Player doesn't have any column filled with 3 marks
    return false;
}

// Checks both diagonal win conditions for a given vector of moves
bool check_diagonals(vector<int> moves) {
    if (has_tile(5, moves)) {  // Check 5 first as both diagonals need tile 5
        if (has_tile(1, moves)) {
            if (has_tile(9, moves)) {
                return true;
            }
        } else if (has_tile(3, moves)) {
            if (has_tile(7, moves)) {
                return true;
            }
        } 
    }
    return false;
}

// Checks all win conditions for a given player
bool check_win_conditions(vector<int> moves) {
    if (check_all_verticals(moves)) {
        return true;
    } else if (check_all_horizontals(moves)) {
        return true;
    } else if (check_diagonals(moves)) {
        return true;
    }
    return false;
}