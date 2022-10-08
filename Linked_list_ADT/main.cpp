#include <iostream>
#include "Node.h"
#include "SingledList.h"

using namespace std;

int main() {
  LinkedList<int> linkedList = LinkedList<int>();
  // 2 -> nullptr
  linkedList.InsertHead(2);
  // 3 -> 2 -> nullptr
  linkedList.InsertHead(3);
  // 5 -> 3 -> 2 -> nullptr
  linkedList.InsertHead(5);
  // 5 -> 3 -> 2 -> 7 -> nullptr
  linkedList.InsertTail(7);

  cout << "First printed: \n";
  linkedList.PrintList();
  cout << endl;

  // 5 -> 3 -> 2 -> 3 -> 7 -> nullptr
  linkedList.Insert(3, 3);
  // 5 -> 3 -> 2 -> 3 -> 5 -> 7 -> nullptr
  linkedList.Insert(4, 5);

  cout << "Second printed: \n";
  linkedList.PrintList();
  cout << endl;

  cout << "Get the value of first two elements: \n";
  cout << linkedList.Get(0)->Value << ", ";
  cout << linkedList.Get(1)->Value << "\n\n";

  cout << "Find the position of value 11 and 7: \n";
  cout << linkedList.Search(11) << ", ";
  cout << linkedList.Search(7) << "\n\n";

  // remove the second element
  linkedList.PrintList();
  cout << "Remove the second item: \n";
  linkedList.Remove(1);
  cout << endl;
  linkedList.PrintList();
  cout << endl;

  // remove the first element
  cout << "Remove the first item: \n";
  linkedList.Remove(0);
  cout << endl;
  linkedList.PrintList();
  cout << endl;

  // remove the first element
  cout << "Remove the last item: \n";
  linkedList.Remove(linkedList.Count()-1);
  cout << endl;
  linkedList.PrintList();
  cout << endl;

  return 0;
}