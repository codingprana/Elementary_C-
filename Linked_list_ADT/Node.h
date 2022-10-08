//#ifndef NODE_H
//#define NODE_H
//#include <iostream>

using namespace std;

template <typename T>
class Node {
  public:
    T Value;
    Node *Next;
    Node(T val) : Value{val}, Next{nullptr} {};
};
//#endif // NODE_H

template <typename T>
void PrintNode(Node<T> *node) {
  // it will print the initial node
  // until the last node that points
  // to a nullptr
  while (node != nullptr) {
    cout << node->Value << " -> ";
    node = node->Next;
  }
  cout << "nullptr" << endl;
}