#include <stack>
#include <iostream>
using namespace std;

/**
 * \namespace stacker Word stacker task.  This program reads words from the
 * standard input, eliminating repeats.  Then the words are printed in reverse
 * order.  The total number of words and average size of a word is then printed
 * as the last line of output.
 *
 * @author Ken Baclawski
 */

/**
 * Main program for the word stacker task.
 * @return The exit status.  Normal status is 0.
 */
int main() {

  // Push all of the words on a stack of words.

  string word;
  stack<string> words;
  while (cin >> word) {

    // If no words are on the stack or the new word is different,
    // then push the new word on the stack.

    if (words.empty() || words.top() != word) {
      words.push(word);
    }
  }

  // Extract the words from the stack.  This reverses their order.

  double totalLength = 0.0;
  const auto wordCount = words.size();

  // Loop invariant: 
  // totalLength is the sum of the lengths of the words that
  // have been popped from the words stack.  Therefore, when the words stack is
  // emptied, totalLength is the sum of the lengths of all words that were
  // originally on the stack.

  while (!words.empty()) {

    // Pop a word from the stack

    const string poppedWord(words.top());
    words.pop();

    // Update the total length

    totalLength += poppedWord.length();

    // Print the word

    cout << word << endl;
  }

  // Print the number of words and the average length.  Division by zero is
  // defined for floating-point to be "Not a Number" or "nan" for short.

  const string conclusion = to_string(wordCount) + " " + to_string(totalLength / wordCount);
  cout << conclusion << endl;

  // More commonly, this would have been programmed like this:
  // cout << wordCount << " " << totalLength / wordCount << endl;
  
  // Normal completion.

  return 0;
}
