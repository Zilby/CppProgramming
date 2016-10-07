#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

/**
 * This program takes in 5 inputs ('l1'-'l5') and returns
 * them twice (as 'out') in reverse order. It does this 
 * using the standard library and requires input via
 * terminal or an ide to run properly.
 */

int main() {
  string l1, l2, l3, l4, l5;
  cin >> l1;
  cin >> l2;
  cin >> l3;
  cin >> l4;
  cin >> l5;
  string out(l5 + " " + l4 + " " + l3 + " "
	     + l2 + " " + l1);
  cout << out << endl << out << endl;
  return 0;
}
