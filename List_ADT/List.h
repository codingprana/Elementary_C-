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

List::List() : m_count(0) {
  m_items = nullptr;
}

List::~List() {
  delete[] m_items;
}

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
  int *oldArray = m_items;

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
      m_items[i] = oldArray[j];
      ++j;
    }
  }

  // Remove copied array
  delete[] oldArray;
  oldArray = nullptr;
}

int List::Search(int value) {
  // Looping through the array elements
  // return the array index if value is found
  for (int i = 0; i < m_count; ++i) {
    if (m_items[i] == value) {
      return i;
    }
  }
  return -1;
}

void List::Remove(int index) {
  // Check if the index is out of bound
  if (index < 0 || index > m_count)
    return;
  
  // Copy the current array
  int *oldArray = m_items;

  // Decrease the array length
  --m_count;

  // Initialize a new array
  m_items = new int[m_count];

  // Fill the new array and
  // remove the selected index
  for (int i = 0, j = 0; i < m_count; ++i, ++j) {
    if (j == index) ++j;
    m_items[i] = oldArray[j];
  }

  // Remove the copied array
  delete[] oldArray;
  oldArray = nullptr;
}

int List::Count() {
  return m_count;
}

