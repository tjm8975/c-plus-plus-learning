#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <ctime>
#include "ufo_functions.hpp"

/*
Improvements Made:
1. Random word picked from vector of strings
2. Codewords can now be phrases (include spaces)
3. Display codeword at end if player wins or loses
4. Guessed letters are case-insensitive
5. Player can play more than once
6. Prevents player from guessing a previously guessed letter
*/

int main() {

  const std::vector<std::string> codewords = {"codecademy", "arduino", "putz", "otto", "jazz", "dog", "antidisestablishmentarianism", "aquifer", "hydroponics", "draco"};
  const int num_codewords = codewords.size();

  // Display intro text
  greet();

  srand(time(NULL));  // Seeds generator

  bool play_again = true;
  // Start game loop until player quits
  while (play_again) {
    int word_num = rand() % num_codewords;  // Gets random number in the range of indexes of codewords
    std::string codeword = codewords[word_num];  // Gets the word to guess

    // Create the blank word based on number of letters in the word
    std::string answer = "";
    for (int i = 0; i < codeword.length(); i++) {
      if (codeword[i] == ' ') {  // Allows for codewords to have spaces
        answer += " ";
      } else {answer += "_";}
    }

    int misses = 0;

    std::vector<char> incorrect;  // Tracks incorrect letters guessed
    bool guess = false;  // Tracks whether the player guessed a correct letter
    char letter;  // The player's guessed letter

    // Run the round until the word is guessed or the player runs out of guesses
    while (answer != codeword && misses < 7) {
      display_misses(misses);  // Display updated UFO image

      display_status(incorrect, answer);  // Display incorrect guesses and answer so far

      // Capture player's guessed letter
      std::cout << "Please enter your guess: ";
      std::cin >> letter;
      letter = tolower(letter);  // Makes guesses case-insensitive

      // Check if player already guessed that letter
      if (!already_guessed(incorrect, answer, letter)) {

        // Check if guessed letter is correct
        for (int i = 0; i < codeword.length(); i++) {
          if (letter == codeword[i]) {
            answer[i] = letter;
            guess = true;
          }
        }

        // Notify player if the guess was correct or not
        if (guess) {
          std::cout << "Correct!\n";
        } else {
          std::cout << "Incorrect! The tractor beam pulls the person in further.\n";
          incorrect.push_back(letter);  // Add letter to incorrect guesses so far
          misses++;  // Add another miss
        }
      }

      guess = false;  // Reset for next guess
    }

    // Check if player won or not
    end_game(answer, codeword);

    // Confirm what the codeword was if the player wins or loses
    std::cout << "Codeword was " << codeword << "\n";
    
    // Ask player if they want to play again
    std::cout << "\nWould you like to play again (y/n)? ";
    std::string yes_no;
    std::cin >> yes_no;
    play_again = (yes_no == "y") ? true : false;

    if (play_again) {
      std::cout << "Great! Picking another word for you to guess.\n";
      Sleep(3000);
    } else {
      std::cout << "See you next time!\n";
    }
  }
}
