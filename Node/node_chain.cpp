#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
class Node {
  public:
    T Value;
    Node *Next;
    // member-initializr  list
    Node(T val) : Value{val}, Next{nullptr} {

      }
};

template <typename T>
void PrintNode(Node<T> *node) {
  // it will print the initial node until
  // it finds the nullptr of the Next Node
  while (node != nullptr) {
    cout << "+------+------------+\n"; // 6 '-'  12 '-'
    cout << "|" << setw(6) << node->Value;
    cout << "|" << setw(12) << &(node->Next) << "|\n";
    cout << "+------+------------+\n";
    cout << setw(12) << "|\n"; 
    cout << setw(12) << "v\n"; 
    node = node->Next;
  }
  cout << "+------+------------+\n";
  cout << "|" << setw(16) << "Nullptr: " << node << "|";
}

int main() {
  Node<double> *node_1 = new Node<double>{1.2};
  Node<double> *node_2 = new Node<double>{10.2};
  Node<double> *node_3 = new Node<double>{100.2};
  Node<double> *node_4 = new Node<double>{200.2};
  Node<double> *node_5 = new Node<double>{300.2};
  Node<double> *node_6 = new Node<double>{400.2};
  Node<double> *node_7 = new Node<double>{500.2};
  node_1->Next = node_2;
  node_2->Next = node_3;
  node_3->Next = node_4;
  node_4->Next = node_5;
  node_5->Next = node_6;
  node_6->Next = node_7;
  PrintNode(node_1);
  
  return 0;
}