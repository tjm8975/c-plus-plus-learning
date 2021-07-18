#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Returns a vector representing an empty board
vector<char> reset_board() {
    return {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
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

// Prompts the user for a rematch and returns true if yes, false otherwise
bool rematch() {
    string answer;
    cout << "Would you like to play again (y/n)? ";
    cin >> answer;
    cout << endl;  // Print a newline for readability in command line
    return (answer == "y") ? true : false;
}