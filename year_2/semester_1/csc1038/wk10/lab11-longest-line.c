#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

int main(int argc, char *argv[]){
    FILE *pfile = NULL;
    char *filename = "paragraph.txt";
    pfile = fopen(filename, "r");
    if (!pfile){
        printf("failed to open\n");
        return 1;
    }

    char sentence[MAX];
    char longest_sentence[MAX];
    int longest_length = 0;
    int number = 0;
    
    while (fgets(sentence, MAX, pfile) != NULL){
        int length = strlen(sentence);
        if (length > longest_length){
            longest_length = length;
            strcpy(longest_sentence, sentence);
        }
    }
    fclose(pfile);
    pfile = NULL;
    printf("%d\n", longest_length);
    printf("%s\n", longest_sentence);
    return 0;
}