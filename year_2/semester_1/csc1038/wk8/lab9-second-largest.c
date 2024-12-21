#include <stdio.h>
#include <stdlib.h>

float second_largest(float *num_list, int length);
void print_array(float num);


int main(int argc, char *argv[]){
    // Alocating memory 
    float *num_list = (float *)malloc((argc-1) * sizeof(float));
    if (num_list == NULL){
        printf("Memory allocation failed");
        return 1;
    }
    
    // parse command line arguments
    for (int i = 0;i<argc-1;++i){
        num_list[i] = atof(argv[i+1]);
    }

    //Calculating seconde largest number
    float second_largest_num = second_largest(num_list, argc-1);
    print_array(second_largest_num);
    
    // Free allocated memory
    free(num_list);
    return 0;
}

void print_array(float num){
    printf("%.1f\n",num); //printing second largest
}

float second_largest(float *num_list, int length){
    float largest = num_list[0];
    float largest_2 = -__FLT_MAX__; //set to smallest possible float value
    
    for (int i = 0;i<length;++i){
        if ((num_list[i]>largest)&&(num_list[i]!=largest)){
            largest_2 = largest;
            largest = num_list[i];
        } else if ((num_list[i] > largest_2) && (num_list[i] != largest)){
            largest_2 = num_list[i];
        }
    }
    return largest_2;
}