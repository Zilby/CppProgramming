#include <string>
#include <iostream>
#include <thread>
#include <vector>
#include "Action.h"
#include "Task.h"
#include "TaskFactory.h"
#include "SharedMap.h"

using namespace std;
using namespace asst06;

int main() {
  int codes, seed;

  // Read in number of codes and the seed
  cin >> codes;
  cin >> seed;

  // Construct shared map and task factory
  SharedMap s;
  TaskFactory f(codes, seed);
  vector<thread> threads;
  
  for(int i = 0; i < codes; ++i) {

    // Add initial tasks to the shared map, one per code
    s.map(Task(i, false));

    // Construct threads, one per code
    threads.push_back(thread(Action(i, s, f)));

    // Add quit tasks to the shared map, one per code
    s.map(Task(i, true));
  }

  // Wait for the threads to finish
  try {
    for(thread& t : threads) {
      t.join();
    }
  } catch (const exception& e) {
    cout << "The main thread could not wait because of "
         << e.what() << endl;
  }

  // Print the shared map
  cout << s.showMap();

  // Return normal status
  return 0;
}
