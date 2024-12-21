#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    char *sen = argv[1];
    char *word = argv[2];
    int i = 0;
    while (*sen!='\0'){
        if (*sen==*word){
            printf("%d ", i);
            int j = i-1;
            while ((*word!=' ')||(*word!='\0')){

                if (*word!=*sen){
                    break;
                } else {
                    ++word;
                    ++sen;
                    ++i;
                    ++j;
                }
                if ((*word==' ')||(*word==0)){
                    printf("%d\n", j);
                }
            }
        }
        ++sen;
        ++i;
    }

    return 0;
}
