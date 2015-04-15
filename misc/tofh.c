#include <stdio.h>
#include <stdlib.h>

void TowersOfH( int disks, char source, char dest, char aux );

void TowersOfH( int disks, char source, char dest, char aux )
{
  if ( disks == 1)
    {
      printf( "Move disk 1 from tower %c to tower %c\n",source,dest );
      return;
    }
  TowersOfH( disks-1, source, aux, dest );
  printf( "Move disk %d from tower %c to tower %c\n", disks, source, dest );
  TowersOfH( disks-1, aux, dest, source );
}

void usage()
{
  printf("tofh <disks>\n");
}
int main ( int argc, char** argv )
{
  if ( argc < 2 )
    {
      usage();
      exit(1);
    }
  int disks = atoi(argv[1]);
  TowersOfH(disks,'S', 'D', 'A');
}
