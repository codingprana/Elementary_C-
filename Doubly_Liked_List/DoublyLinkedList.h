// DoublyLinkedList class
template <typename T> 
class DoublyLinkedList {
  private:
    int m_count;

  public:
    DoublyNode<T> *Head;
    DoublyNode<T> *Tail;
    DoublyLinkedList()
      : m_count{0}, Head{nullptr}, Tail{nullptr} {

      }
    DoublyNode<T> *Get(int index);

    void InsertHead(T val);
    void InsertTail(T val);
    void Insert(int index, T val);

    int Search(T val);

    void RemoveHead();
    void RemoveTail();
    void Remove(int index);

    int Count();
    void PrintList();
    void PrintListBackward();
};


template <typename T>
DoublyNode<T> *DoublyLinkedList<T>::Get(int index) {
  if (index < 0 || index >= m_count) return nullptr;
  DoublyNode<T> *node = Head;
  for (int i = 0; i < index; ++i) {
    node = node->Next;
  }
  return node;
}

template <typename T>
void DoublyLinkedList<T>::InsertHead(T val) {
  DoublyNode<T> *node = new DoublyNode<T>{val};
  node->Next = Head;
  if (Head != nullptr) {
    Head->Previous = node;
  }
  Head = node;
  if (!m_count) {
    Tail = Head;
  }
  ++m_count;
}

template <typename T>
void DoublyLinkedList<T>::InsertTail(T val) {
  if (!m_count) {
    InsertHead(val);
    return;
  }
  DoublyNode<T> *node = new DoublyNode<T>{val};
  node->Previous = Tail;
  Tail->Next = node;
  Tail = node;
  ++m_count;
}

template <typename T>
void DoublyLinkedList<T>::Insert(int index, T val) {
  if (index < 0 || index > m_count) return;
  if (!index) {
    InsertHead(val);
    return;
  }
  if (index == m_count) {
    InsertTail(val);
    return;
  }

  DoublyNode<T> *prevNode{nullptr};
  DoublyNode<T> *nextNode{nullptr};
  DoublyNode<T> *node = new DoublyNode<T>{val};
  if (index < m_count / 2) {
    prevNode = Head;
    // 0[head] 1 2 3[prev] 4[index=4; next] 5 6 7 8 9
    for (int i = 0; i < index - 1; ++i) {
      prevNode = prevNode->Next;
    }
    nextNode = prevNode->Next;
  }
  else {
    nextNode = Tail;
    // 0[head] 1 2 3 4 5[prev] 6[index=6; next] 7 8 9[tail]
    for (int i = m_count - 1; i > index; --i) {
      nextNode = nextNode->Previous;
    }
    prevNode = nextNode->Previous;
  }
  node->Previous = prevNode;
  node->Next = nextNode;
  prevNode->Next = node;
  nextNode->Previous = node;
  ++m_count;
}

template <typename T>
void DoublyLinkedList<T>::PrintList() {
  DoublyNode<T> *node = Head;
  for (int i = 0; i < m_count; ++i) {
    std::cout << node->Value << " -> ";
    node = node->Next;
  }
  std::cout << "nullptr" << std::endl;
}
