#include <stdio.h>
#include <stdlib.h>



int search_ans(){
}

int main(int argc, char *argv[]){
    int num = atoi(argv[1]);
    int check = 1;
    for (int i = 2; i < argc; ++i){
        if (num == atoi(argv[i])){
            printf("Found %d at %d\n", num, i-2);
            check = 0;
            break;
        }
    }
    if (check == 1 ){
        printf("%d not found\n", num);
    }
    return 0;
}