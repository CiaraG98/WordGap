#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;


vector<string> dictionary; // global var so visible to check_word(..) and main(..)

bool check_word(string word);
void run_game();
int currentScore = -1;

main() {

  /*************************/
  /* set up the dictionary */
  /*************************/
  ifstream the_words;
  the_words.open("length3words");
  if(!the_words) {
    cout << "prob opening words\n";
    exit(1);
  }

  string word;
  while(the_words >> word) {
    dictionary.push_back(word);
  }
  cout << "Welcome to the word-gap game!! " << endl;
  //  cout << "by the way max random is " << RAND_MAX << endl;
  //  srand(time(0));

  /*********************************************************************/
  /* set up a vector of 10 test words randomly chosen from the dictionary */
  /*********************************************************************/
  // start game
  bool continueGame = true;
  while(continueGame)
    {
      run_game();
      cout << "Do you want to play again? (y or n)" << endl;
      string playAgain;
      cin >> playAgain;
      if(playAgain=="n")
	{
	  continueGame=false;
	}
      else if(playAgain!="y")
	{
	  cout << "invalid input... ending game" << endl;
	  continueGame = false;
	}

    }
  // end of game


}

bool check_word(string word) {
  //TODO: done
  for(unsigned int i=0; i < dictionary.size(); i++) {
    if(dictionary[i] == word) {
      return true;
    }
  }
  return false;
}

void run_game() {
   vector<string> test_words;
  //TODO: done
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
  //TODO: done
  for(int i = 0; i < 10; i++) {
    string testword;
    testword = test_words[i];
    // pick position
    // blank it
    // ask for fill and see if a possible word
    // add to running score;
    int word_pos;
    word_pos = rand() % 3; // so 0 1 2
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
  int prevScore = currentScore;
  currentScore = score;
  if(prevScore!=-1)
    {
      if(prevScore > currentScore)
	{
	  cout << "You did worse :)" << endl;
	}
      else if(prevScore < currentScore)
	{
	  cout << "You did better >_<" << endl;
	}
      else
	{
	  cout << "You made no improvement...  but didn't do worse either! ay!" << endl;
	}
    }
}
