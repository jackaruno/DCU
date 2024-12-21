#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_it_twice_as_big(int *num_list, int num, int length);
int largest_num_twice_as_big(int *num_list, int length);
void print_array(int num);


void print_array(int num){
    printf("%d\n",num); //printing second largest
}

bool is_it_twice_as_big(int *num_list, int num, int length){
    // checking through all nums to see the number is twice as big as one of the numbers
    for (int i = 0;i<length;++i){
        if ( (num_list[i]*2) == num){
            return true;
        }
    }
    return false; // if the number is not twice as big as any of the numbers it return false
}

int largest_num_twice_as_big(int *num_list, int length){
    int largest = -__INT_MAX__;
    for (int i = 0;i<length;++i){
        if (largest<num_list[i]){
            if (is_it_twice_as_big(num_list, num_list[i], length)){
                largest = num_list[i]; 
            }
        } 
    }
    if (largest == -__INT_MAX__){
        return 0;
    }
    return largest;
}

int main(int argc, char *argv[]){
    // Allocating memory dynamically based on the input size
    int *num_list = (int *)malloc((argc -1) * sizeof(int));
    if (num_list == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    //parsing command line arguments
    for (int i = 0;i<argc-1;++i){
        num_list[i] = atoi(argv[i+1]);
    }
    //calling largest number function
    int num = largest_num_twice_as_big(num_list, argc-1);
    print_array(num);

    free(num_list);
    return 0;
}