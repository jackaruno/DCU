#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  int t = atoi(argv[1]);
  int con = atoi(argv[2]);
  int pen = atoi(argv[3]);
  int dg = atoi(argv[4]);
  int total = t*5 + con*2 + pen*3 + dg*3 ;
  printf ("%i\n",total);
  return 0;
}
