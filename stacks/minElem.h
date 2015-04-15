#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>

class auxStack
{
 private:
  std::stack<int> myStack;
  std::stack<int> minStack;
 public:
  int getMinimum();
  void push(int);
  int pop();
};
