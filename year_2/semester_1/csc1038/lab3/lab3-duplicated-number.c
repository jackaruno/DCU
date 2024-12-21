#include <stdio.h>
#include <stdlib.h>

int duplicate(int nums[], int length);

int main(int argc, char *argv[]){
    int nums[50]; 
    int dup = 0;
    for (int i = 1; i < argc; ++i){
        nums[i-1] = atoi(argv[i]);
    }
    int length = argc-1;
    dup = duplicate(nums, length);
    if (dup == 0){
        printf ("no duplicated number\n");
    } else {
        printf("%d\n", dup);
    }
    return 0;
}

int duplicate(int nums[], int length){
    for (int i = 0; i < length; ++i){
        for (int j = i+1; j < length+1; ++j){
            if (nums[i]==nums[j]){
                return nums[i];
            }
        }
        
    }
    return 0;
}