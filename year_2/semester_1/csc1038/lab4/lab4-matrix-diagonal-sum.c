#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    int matrix = atoi(argv[1]);
    int total = 0;
    for (int i = 2;i<argc+2;i=i+matrix){
        total+=atoi(argv[i]);
        //printf("%d\n", atoi(argv[i]));
        ++i;
    }
    printf("%d\n", total);
    return 0;
}