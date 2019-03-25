#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

vector<string> dictionary;
bool check_word(string word);
void run_game();
int highScore = 0;
void run_game(int wordSize);
void game_choice();
int wordSize= 0;
ifstream the_words;

int main() {

  cout << "Welcome to the word-gap game!! " << endl;

  bool continueGame = true;
  while(continueGame)
  {
    game_choice();
    cout << "High score: " << highScore << endl;
    run_game(wordSize);
    cout << "Do you want to play again? (y or n)" << endl;
    string playAgain;
    cin >> playAgain;
    if (playAgain == "n")
    {
      continueGame = false;
    }
    else if (playAgain != "y")
    {
      cout << "invalid input... ending game" << endl;
      continueGame = false;
    }
    the_words.close();
  }
  // end of game

}

bool check_word(string word) {
  for(unsigned int i = 0; i < dictionary.size(); i++) {
    if(dictionary[i] == word) {
      return true;
    }
  }
  return false;
}

void game_choice() {
  cout << "Would you like to play the word game or the verb game? ('word' or 'verb')\n";
  string input;
  cin >> input;
  if (input == "word")
  {
    the_words.open("length3words");
    wordSize = 3;
  }
  else if (input == "verb")
  {
      the_words.open("length4verbs");
      wordSize = 4;
  }
  else {
    cout << "not a valid response... ending program\n";
    exit(1);
  }
  if (!the_words) {
    cout << "There was a problem opening the file\n";
    exit(1);
  }

  string word;
  while(the_words >> word) {
    dictionary.push_back(word);
  }

}

void run_game(int wordSize) {
  vector<string> test_words;
  for(int i = 0; i < 10; i++) {
    // pick random source;
    string source;
    source = dictionary[rand() % dictionary.size()];
    //    cout << "source is: " << source << endl;
    test_words.push_back(source);
  }

  /********************************************************************************/
  /* go thru these blanking one letter and asking for it to be filled,            */
  /* and for each check presence in dictionary keeping                      score */
  /********************************************************************************/

  int score = 0;

  for(int i = 0; i < 10; i++) {
    string testword;
    testword = test_words[i];
    // pick position
    // blank it
    // ask for fill and see if a possible word
    // add to running score;
    int word_pos;
    word_pos = rand() % wordSize; // so 0 1 2
    testword[word_pos] = '_';
    char c;
    cout << "fill the gap in: " << testword << endl;
    cin >> c;
    testword[word_pos] = c;
    if(check_word(testword)) {
      cout << "yep reckon " << testword << " is possible\n";
      score++;
    }
    else {
      cout << "nope reckon " << testword << " is not possible\n";
    }
  }
  cout << "you got " << score << " right\n";

    if(score > highScore) {
      cout << "You did better >_<" << endl;
      highScore = score;
    }
    else if(score < highScore)
      cout << "You did worse :)" << endl;
    else
      cout << "You made no improvement...  but didn't do worse either! ay!" << endl;

}
