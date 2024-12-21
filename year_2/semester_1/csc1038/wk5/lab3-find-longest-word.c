#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    char sentence[1];
    sentence[1] = *argv[1];
    int max = 0;
    char *max_word = "";
    int total = 0;
    char total_word[20];
    printf("%c   okay",sentence[1]);
    while (sentence!='\0'){
        printf("%p   lsfdjl",sentence);
        if (sentence==" "){
            if (max<total){
                total = max;
                max_word = total_word;
            }
            free(total_word);
            total = 0;
        } else {
            total_word[total] = *sentence;
        }
        *sentence += 1;
        total += 1;
    }
    printf("%s\n\n", max_word);
    return 0;
}