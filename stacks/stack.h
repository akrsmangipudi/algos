#include <stdio.h>
#include <stdlib.h>
#include <iostream>

template<class T>

class Stack {
 public:
  Stack();
  Stack(size_t size);
  ~Stack();
  T pop();
  void push(T data);
  
 private:
  int     m_top;
  size_t  m_size;
  T      *m_array;
  bool    empty();
  bool    full();
  void    doubleSize();
  
};


template<class T>

Stack<T>::Stack() : m_top(-1), m_size(1)
{
  m_array = (T*) malloc( sizeof(T) * m_size );
}

template<class T>
Stack<T>::Stack(size_t size) : m_top(-1), m_size(size)
{
  m_array = (T*) malloc( sizeof(T) * m_size );
  if (!m_array) exit(1);
}

template<class T>
Stack<T>::~Stack()
{
  free(m_array);
}

template<class T>
bool
Stack<T>::empty()
{
  return ( m_top == -1 );
}

template<class T>
bool
Stack<T>::full()
{
  return ( m_top == m_size-1 );
}

template<class T>
void
Stack<T>::doubleSize()
{
  m_size *= 2;
  m_array = (T*)realloc( m_array, m_size );
}

template<class T>
void
Stack<T>::push(T data)
{
  if ( full() )
    doubleSize();
  m_array[++m_top] = data;
}

template<class T> 
T
Stack<T>::pop()
{
  if ( empty() )
    {
      std::cout<<"Stack Underflow!"<<std::endl;
      return NULL;
    }
  return m_array[m_top--];
}

