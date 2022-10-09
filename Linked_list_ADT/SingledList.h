//#include <iostream>

template <typename T>
class LinkedList {
  private:
    T m_count;
  
  public:
    // the first node in the list
    // or nill if empty
    Node<T> *Head;

    // the last node in the list
    // or nill if empty
    Node<T> *Tail;

    // constructor
    LinkedList() 
      : m_count{0}, Head{nullptr}, Tail{nullptr} {

      }

    // Get() operation
    Node<T> *Get(int index);

    // Insert() operation
    void InsertHead(T val);
    void InsertTail(T val);
    void Insert(int index, T val);

    // Search() operation
    int Search(T val);

    // Remove() operation
    void RemoveHead();
    void RemoveTail();
    void Remove(int index);

    // Additional operation
    int Count();
    void PrintList();
};

template <typename T>
Node<T> *LinkedList<T>::Get(int index) {
  // check if the index is out of bound
  if (index < 0 || index >= m_count)
    return nullptr;

  Node<T> *node = Head;
  for (int i = 0; i < index; ++i) {
    node = node->Next;
  }
  return node;
}

template <typename T>
void LinkedList<T>::InsertHead(T val) {
  // create a new node
  Node<T> *node = new Node<T>{val};
  
  // let the next pointer of the new node
  // point to the current head
  node->Next = Head;
  
  // set head the new node
  Head = node;

  // if the linked list is empty
  // the tail is also the head
  if (!m_count) {
    Tail = Head;
  }

  // one element is added
  m_count++;
}

template <typename T>
void LinkedList<T>::InsertTail(T val) {
  // if linked list is empty
  // invoke InsertHead()
  if (!m_count) {
    InsertHead(val);
    return;
  }

  Node<T> *node = new Node<T>(val);

  // let the next pointer of the tail
  // point to the new node
  Tail->Next = node;

  // set tail the new node
  Tail = node;

  ++m_count;
}

template <typename T>
void LinkedList<T>::Insert(int index, T val) {
  // check if out of bound
  if (index < 0 || index > m_count) return;
  if (!index) {
    InsertHead(val);
    return;
  }
  if (index == m_count) {
    InsertTail(val);
    return;
  }

  // start to find previous node
  // from the head
  Node<T> *prevNode = Head;

  // traverse the elements until 
  // the selected index is found
  // ex index = 3; prevnode is at 2
  for (int i = 0; i < index - 1; ++i) {
    prevNode = prevNode->Next;
  }

  // create the nest node which is the next 
  // node after the current previous node
  Node<T> *nextNode = prevNode->Next;

  // insert this new node between the 
  // previous and the next node
  Node<T> *node = new Node<T>{val};
  prevNode->Next = node;
  node->Next = nextNode;

  ++m_count;
}

template <typename T>
int LinkedList<T>::Search(T val) {
  if (!m_count) return -1;

  Node<T> *node = Head;
  int index{0};
  while (node->Value != val) {
    node = node->Next;
    if (node == nullptr) return -1;
    ++index;
  }
  return index;
}

template <typename T>
void LinkedList<T>::RemoveHead() {
  if (!m_count) return;
  Node<T> *node = Head;
  Head = Head->Next;
  delete node;
  --m_count;
}

template <typename T>
void LinkedList<T>::RemoveTail() {
  if (!m_count) return;
  if (m_count == 1) {
    RemoveHead();
    return;
  }

  Node<T> *prevNode = Head;
  Node<T> *node = Head->Next;
  while (node->Next != nullptr) {
    prevNode = prevNode->Next;
    node = node->Next;
  }
  prevNode->Next = nullptr;
  Tail = prevNode;

  delete node;
  
  --m_count;
}

template <typename T>
void LinkedList<T>::Remove(int index) {
  if (!m_count || index < 0 || index >= m_count) return;
  if (!index) {
    RemoveHead();
    return;
  }
  else if (index == m_count - 1) {
    RemoveTail();
    return;
  }

  // start to traverse the list
  // from the Head
  Node<T> *prevNode = Head;

  // find the element before the selected index
  for (int i = 0; i < index - 1; ++i) {
    prevNode = prevNode->Next;
  }

  // the removed itm is right after the prevNode
  Node<T> *node = prevNode->Next;
  
  // link the prevNode to the next node of 
  // the removed one
  prevNode->Next = node->Next;
  delete node;
  --m_count;
}

template <typename T>
int LinkedList<T>::Count() {
  return m_count;
}

template <typename T>
void LinkedList<T>::PrintList() {
  Node<T> *node = Head;
  while(node != nullptr) {
    cout << node->Value << " -> ";
    node = node->Next;
  }
  cout << "nullptr" << endl;
}