#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    char width;
    for (int i = 0; i < n; ++i){
        printf("*");
    }
    printf("\n");
    for (int i = 0; i < (n-2); ++i){
        printf("*");
        for (int j = 0; j < (n-2); ++j  ){
            printf(" ");
        }
        printf("*\n");
    }
    for (int i = 0; i < n; ++i){
        printf("*");
    }
    printf("\n");
    return 0;
}