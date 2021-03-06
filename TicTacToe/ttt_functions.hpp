#include <vector>

using namespace std;

void greet(vector<char> board);

void reset_vectors(vector<char> &board, vector<int> &open_tiles, vector<int> &player_tiles, vector<int> &cpu_tiles);

void display_board(vector<char> board);

bool rematch();

void player_move(vector<char> &board, vector<int> &open_tiles, vector<int> &player_tiles);

void test_vectors(vector<int> open_tiles, vector<int> player_tiles, vector<int> cpu_tiles);

void cpu_move(vector<char> &board, vector<int> &open_tiles, vector<int> &cpu_tiles);

bool check_win_conditions(vector<int> moves);

void general_player_move(vector<char> &board, vector<int> &open_tiles, vector<int> &player_tiles, int &move_count, bool cpu = false);

bool first_player_win(int &move_count, vector<int> player_tiles, bool &game_over, bool cpu = false);

void second_player_win(int &move_count, vector<int> player_tiles, bool &game_over, bool cpu = false);