#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int nums[], int l, int order){
    bool swapped;
    for (int i = 0;i<l;++i){
        swapped = false;
        if (order){
            for (int j = 0;j<l-i-1;++j){
                if (nums[j]>nums[j+1]){
                    swap(&nums[j], &nums[j+1]);
                    swapped = true;
                }
            }
            if (!swapped){
                break;
            }
        } else {
            for (int j = 0;j<l-i-1;++j){
                if (nums[j]<nums[j+1]){
                    swap(&nums[j], &nums[j+1]);
                    swapped = true;
                }
            }
            if (!swapped){
                break;
            }
        }
    }
}

void printarray(int nums[], int l){
    printf("Sorted numbers:");
    for (int i = 0;i<l;++i){
        printf(" %d", nums[i]);
    }
    printf("\n");
}



int main(int argc, char * argv[]){
    int i = 2;
    bool order;
    if (*argv[argc-1]=='a'){
        order = true;
    } else {
        order = false;
    }
    int nums[argc];
    while (i<argc-1){
        nums[i-2] = atoi(argv[i]);
        ++i;
    }
    bubblesort(nums, i-2, order);

    printarray(nums, i-2);
    return 0;
}