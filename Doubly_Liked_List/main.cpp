#include <iostream>
#include "DoublyNode.h"
#include "DoublyLinkedList.h"

using namespace std;

int main() {
  DoublyLinkedList<int> linkedlist =  DoublyLinkedList<int>();
  for (int i = 0; i < 11; ++i) {
    linkedlist.InsertHead(i);
    linkedlist.PrintList();
  }
  linkedlist.Insert(3, 30);
  linkedlist.PrintList();
  linkedlist.Insert(8, 70);
  linkedlist.PrintList();

  return 0;
}