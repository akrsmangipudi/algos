#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>
void createArray(std::vector<int> &elements)
{
  elements.push_back(1);
  elements.push_back(2);
  elements.push_back(1);
  elements.push_back(3);
  elements.push_back(2);
  elements.push_back(5);
  elements.push_back(6);
  elements.push_back(6);
  elements.push_back(3);
  elements.push_back(4);
  elements.push_back(4);
  return;
}
void printDuplicates(std::vector<int> arr)
{
  for ( std::vector<int>::iterator itr = arr.begin(); itr != arr.end(); ++itr )
    {
      if ( arr[std::abs(*itr)] >= 0 )
	arr[std::abs(*itr)] = -arr[std::abs(*itr)];
      else
	std::cout << std::abs(*itr) << std::endl;
    }
  return;
}
int main(int argc, char* argv[])
{
  std::vector<int> elements;
  createArray(elements);
  printDuplicates(elements);
  return EXIT_SUCCESS;
}
