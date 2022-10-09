// DoublyNode clasee
template <typename T>
class DoublyNode {
  public:
    T Value;
    DoublyNode<T> *Previous;
    DoublyNode<T> *Next;

    DoublyNode(T val)
      : Value{val}, Previous{nullptr}, Next{nullptr} {
        
      };
};