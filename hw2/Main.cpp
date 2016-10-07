#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

/**
 * \namespace This program takes in words and returns the 
 * longest word and the shortest word. If no words are entered
 * it returns a status code of 1
 *
 * @author Alexander Zilbersher
 */

/**
 * The main program for our task. 
 * @return the exit status. Normal status is 0. 
 * If no words are entered will return status 1;
 */
int main() {
  // Read the input words into a vector.

  string word;
  vector<string> words;
  while (cin >> word) {
    words.push_back(word);
  }

  // See if there are no words.

  if (words.empty()) {
    
    // Status code is 1 in this case.

    return 1;
  }

  // Initialize variables.
  
  string longest = words[0];
  string shortest = words[0];
  unsigned int i = 0;

  // Iterate through vector to find longest
  // and shortest words.
  
  while (i < words.size()) {
    if (longest.length() < words[i].length()) {
      longest = words[i];
    }
    if (shortest.length() > words[i].length()) {
      shortest = words[i];
    }
    ++i;
  }

  // Output results.
  
  cout << "Shortest word is " + shortest << endl <<
    "Longest word is " + longest << endl;

  // Return normal status.
  
  return 0;
}
