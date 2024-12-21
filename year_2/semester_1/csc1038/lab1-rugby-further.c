#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argv[1]&&argv[2]&&argv[3]&&argv[4]){
        int t = abs(atoi(argv[1]));
        int con = abs(atoi(argv[2]));
        int pen = abs(atoi(argv[3]));
        int dg = abs(atoi(argv[4]));
        int total = t*5 + con*2 + pen*3 + dg*3;
        printf ("%i\n",total);
    } else {
        printf ("put in all values\n");
    }
}