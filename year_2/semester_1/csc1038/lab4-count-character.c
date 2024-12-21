#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int result = 0;
    char *str = argv[2];
    while (*str!='\0'){
        if (*str==*argv[1]){
            ++result;
        }
        ++str; 
    }
    printf("%d\n", result);
    return 0;
}
