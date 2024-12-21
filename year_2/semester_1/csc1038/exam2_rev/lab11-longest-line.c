#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 200


int main(int argc, char *argv[]){
    FILE *pfile = NULL;
    char *filename = "paragraph.txt";
    pfile = fread(filename, "r");
    if (!pfile){
        printf("error");
        exit(1);
    }

    char strings[200][200];
    int max = 0;
    int max_line = 0;
    int curr = 0;
    int curr_line = 0;

    while(fgets(para[0], MAX, pfile)){
        curr = strlen(para[curr_line]);
        if (cur>max){
            max = cur;
            max_line = curr_line;
        }
        curr_line++;
    }

    printf("%d\n", max);
    printf("%s\n", para[max_line]);


    return 0;
}