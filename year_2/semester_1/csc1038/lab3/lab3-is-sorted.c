#include <stdio.h>
#include <stdlib.h>

void bubblesort(int num_list[], int n){
    int temp = 0;
    for (int i = 0; i < n-1; ++i){
        for (int j = 0; j < n-1; ++j){
            if (num_list[j]>num_list[j+1]){
                temp = num_list[j];
                num_list[j] = num_list[j+1];
                num_list[j+1] = temp;
            }
        }
    }   
}


int main(int argc, char *argv[]){
    int num_list[argc];
    for (int i = 0; i < argc-1; ++i){
        num_list[i] = atoi(argv[i+1]);
    }
    bubblesort(num_list, argc-1);
    for (int i = 0; i < argc-1; ++i){
        printf("%d\n", num_list[i]);
    }
    return 0;
}