#include <iostream>
#include <vector>
#include <string>
#include "ttt_functions.hpp"

using namespace std;

int main() {
    // Initialize empty game board
    vector<char> board = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    display_board(board);
}