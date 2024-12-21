#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    char *str = argv[1];
    int i;
    char ch;
    int max = 0;
    while(*str!='\0'){
        char *poi = str+1;
        i = 0;
        int sum = 0;
        while(*poi!='\0'){
            if (*poi==*str){
                ++i;
            }
            ++poi;
        }
        if (i>max){
            max=i;
            ch=*str;
        }
        ++str;
    }
    printf("%d\n", max+1);
    printf("%c\n", ch);

    return 0;
}