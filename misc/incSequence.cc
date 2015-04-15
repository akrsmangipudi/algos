#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>
void printSequence( int, int );
void printSequence( int n, int k, int &len, int* array );


// A utility function to print contents of arr[0..k-1]
void printArr(int arr[], int k)
{
  for (int i=0; i<k; i++)
    std::cout << arr[i] << " ";
  std::cout << std::endl;
}
void printSequence( int n, int k, int &len, int* array )
{
  // int j;
  static int frNum = 0;
  if ( len == k )
    {
      // std::cout<<"Level:"<<frNum<<" "<<array[0]<<" "<<array[1]<<" "<<array[2]<<std::endl;
      printArr(array, k);
      return;
    }
  // else
  //   {
  int j = ( len == 0 ) ? 1 : array[len-1]+1;
  len++;
        for ( ; j <= n ; j++ )
	// while ( j<= n )
  	{
  	  array[len-1] = j;
  	  frNum++;
  	  printSequence(n, k, len, array);
  	  frNum--;
	  //  j++;
  	}
	 len--;
    // }

}

void printSequence(int n, int k)
{
  //std::string str(k, '0');
  int* array = (int*) malloc(sizeof(int)*k);
  if ( !array )
    {
      std::cout<<"Out of Memory"<<std::endl;
      exit(1);
    }
  std::memset(array, 0, sizeof array);
  // int array[k];
  int len = 0;
  printSequence(n, k, len, array);
}
void usage(char** argv)
{
  std::cerr<<argv[0]<<" <Number of elements> "<<" <sequence size> "<<std::endl;
}
int main(int argc, char** argv)
{
  if ( argc < 3 )
    {
      usage(argv);
      exit(1);
    }
  int n = atoi(argv[1]);
  int k = atoi(argv[2]);
  std::cout<<"Size: "<<n<<" Length: "<<k<<std::endl;
  printSequence(n,k);
}
