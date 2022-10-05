// Project: List.cbp
// File: main.cpp
#include "List.h"

using namespace std;


int main() {
  // Initialize a list
  List list = List();

  // Add several items to the list
  list.Insert(0, 1);
  //list.Insert(1, 1);
  list.Insert(1, 2);
  list.Insert(2, 3);
  //list.Insert(4, 5);
  //list.Insert(5, 8);
  list.Insert(3, 13);

  // Print current list
  cout << "List element:" << endl;
  for (int i = 0; i < list.Count(); ++i) {
    cout << list.Get(i) << " ";
  }
  cout << "\n\n";

  // Insert several items in the middle of the List
  list.Insert(1, 1);
  list.Insert(4, 5);
  list.Insert(5, 8);

  // Print current list
  cout << "List element:" << endl;
  for (int i = 0; i < list.Count(); ++i) {
    cout << list.Get(i) << " ";
  }
  cout << "\n\n";

  // Search value 71
  int test_1 = 71;
  cout << "Search element " << test_1 << endl;
  int result = list.Search(test_1);
  if (result == -1) {
    cout << test_1 << " is not found\n";
  }
  else {
    cout << test_1 << " is found at index " << result;
  }
  cout << "\n\n";

  return 0;
}