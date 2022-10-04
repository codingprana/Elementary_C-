// Project: List.cbp
// File : List.h
#ifndef LIST_H
#define LIST_H

#include <iostream>

class List
{
  private:
    int m_count;
    int *m_items;

  public:
    List();
    ~List();
    int Get(int index);
    void Insert(int index, int val);
    int Search(int val);
    void Remove(int index);
    int Count();
};
#endif // LIST_H

int List::Get(int index)
{
  // Check if the index is out of bound
  if (index < 0 || index > m_count)
    return -1;

  return m_items[index];
}

void List::Insert( int index, int value)
{
  // Check if the index is out of bound
  if (index < 0 || index > m_count)
    return;
  
  // Copy the current array
  int *OldArray = m_items;

  // Increase the array length
  ++m_count;

  // Initialize a new array
  m_items = new int[m_count];

  // Fill the new array with inserted data
  for (int i=0, j=0; i < m_count; ++i) {
    if (i == index) {
      m_items[i] = value;
    }
    else {
      m_items[i] = OldArray[j];
      ++j;
    }
  }

  // Remove copied array
  delete [] OldArray;
  
}