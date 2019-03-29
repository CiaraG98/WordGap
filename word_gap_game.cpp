#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

vector<string> dictionaryVerbs;
vector<string> dictionaryEnglish;
vector<string> dictionarySpanish;
vector<string> dictionaryGerman;

bool check_word(string word);
void run_game();
int run_verb_game(vector<string> test_words);
int highScore = 0;
void run_game();
void game_choice();
ifstream the_words;
vector<string> current;

int main() {

  the_words.open("words");
  string word;
  while(the_words >> word) {
    dictionaryEnglish.push_back(word);
  }
  the_words.close();

  the_words.open("verbs");
  while(the_words >> word) {
    dictionaryVerbs.push_back(word);
  }
  the_words.close();

  the_words.open("spanish_words");
  while(the_words >> word) {
    dictionarySpanish.push_back(word);
  }
  the_words.close();

  the_words.open("german_words");
  while(the_words >> word) {
    dictionaryGerman.push_back(word);
  }
  the_words.close();
  cout << "Welcome to the word-gap game!! " << endl;

  bool continueGame = true;
  while(continueGame)
  {
    game_choice();
    cout << "High score: " << highScore << endl;
    run_game();
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
}


bool check_word(string word) {
  for(unsigned int i = 0; i < current.size(); i++) {
    if(current[i] == word) {
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
    cout << "Would you like to play this in 'spanish', 'english', or 'german'?\n";
    string language;
    cin >> language;
    if(language=="spanish")
    {
      current = dictionarySpanish;
    }
    else if(language=="english")
    {
      current = dictionaryEnglish;
    }
    else if(language=="german")
    {
      current = dictionaryGerman;
    }
  }
  else if (input == "verb")
  {
      current = dictionaryVerbs;
  }
  else {
    cout << "not a valid response...try again\n";
    game_choice();
    //exit(1);
  }

}

int run_verb_game(vector<string> test_words)
{
  int score = 0;
  string person;
  string conjugation;
  string verb;
  size_t verbPos;
  size_t personPos;
  string current;
  for(int i = 0; i < 10; i++) {
    current = test_words[i];
    verbPos = current.find('/');
    verb = current.substr(0, verbPos);
    personPos = current.find('/', verbPos+1);
    person = current.substr(verbPos+1,personPos-verbPos-1);
    conjugation = current.substr(personPos+1);
    int word_pos;
    word_pos = rand() % conjugation.size(); // so 0 1 2
    conjugation[word_pos] = '_';
    cout << "The verb is " << verb << endl;
    cout << "Fill in the gap:" << person << " " << conjugation << endl;
    char c;
    string input;
    cin >> input;
    if(input.length()==1)
    {
      c = input[0];
    }
    else
    {
      c = -1;
    }
    conjugation[word_pos] = c;
    if(conjugation==current.substr(personPos+1)) {
      cout << "Valid answer\n";
      score++;
    }
    else {
      cout << "Invalid answer\n";
    }
  }
  return score;
}
void run_game() {
  vector<string> test_words;
  for(int i = 0; i < 10; i++) {
    string source;
    source = current[rand() % current.size()];
    test_words.push_back(source);
  }
  int score = 0;
  if(current==dictionaryVerbs)
  {
    score = run_verb_game(test_words);
  }
  else
  {
    for(int i = 0; i < 10; i++) {
      string testword;
      testword = test_words[i];
      int word_pos;
      word_pos = rand() % testword.size(); // so 0 1 2
      testword[word_pos] = '_';
      string input;
      char c;
      cout << "fill the gap in: " << testword << endl;
      cin >> input;
      if(input.length()==1)
      {
        c = input[0];
      }
      else
      {
        c = -1;
      }
      testword[word_pos] = c;
      if(check_word(testword)) {
        cout << "Valid answer\n";
        score++;
      }
      else {
        cout << "Invalid answer\n";
      }
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

      test_words.clear();
}
