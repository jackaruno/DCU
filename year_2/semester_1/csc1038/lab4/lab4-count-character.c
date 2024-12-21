#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    char *str = argv[2];
    int result = 0;
    while(*str!='\0'){
        if (*str==*argv[1]){
            ++result;
        }
        ++str;
    }
    printf("%d\n", result);
    return 0;
}