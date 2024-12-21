#include <stdio.h>
#include <stdlib.h>

char longest_string(char **strings, int length);
int max_length_of_words(char **strings, int length);
void print_longest_words(char **strings, int string_count, int max_length);

int main(int argc, char *argv[]){
    int max = max_length_of_words(argv, argc);
    print_longest_words(argv, argc, max);
    return 0;
}

int max_length_of_words(char **strings, int length){
    int max = 0;
    for (int i = 1;i<length;++i){
        for (int j = 0;strings[i][j]!='\0';++j){
            if (j>max){
                max=j;
            }
        }
    }
    return max;
}

void print_longest_words(char **strings, int string_count, int max_length){
    for (int i = 1;i<string_count;++i){
        for (int length = 0;strings[i][length]!='\0';++length){
            if (length==max_length){
                printf("%s\n", strings[i]);
            }
        }
    }
}