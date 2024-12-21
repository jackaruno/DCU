#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    int height_1 = atoi(argv[1]);
    int width_1 = atoi(argv[2]);
    int matrix_1 = width_1*height_1;
    int start_2 = matrix_1+5;
    int height_2 = atoi(argv[(matrix_1)+3]);
    int width_2 = atoi(argv[(matrix_1)+4]);
    int matrix_2 = width_2*height_2;
    int matrix_3 = (0,0,0,0,0,0);
    //printf("%d %d %d %d %d %d %d\n\n", height_1, width_1, matrix_1, start_2, height_2, width_2, matrix_2);
    int sum = 0;
    int l = 0;
    int matrix_1_array[matrix_1*width_2];
    for (int k = 0;k<height_1;++k){
        for (int j = (k*width_1);j<width_2+(k*width_1);++j){
            for (int i = 3+(k*width_1);i<width_1+3+(k*width_1);++i){
                //printf("%d ", atoi(argv[i]));
                matrix_1_array[l] = atoi(argv[i]);
                ++l;
            }   
        }
    }
    int matrix_2_array[matrix_2*height_1];
    int k = 0;
    for (int l = 0; l<height_1;++l){
        for (int i = 0;i<width_2;++i){
            int j = i;
            while (j<(matrix_2)){
                matrix_2_array[k] = atoi(argv[start_2+j]);
                ++k;
                j = j+(width_2);
            }
        }
    }
    
    for (int i = 0;i<k;++i){
        //printf("%d\n", matrix_2_array[i]);
    }
    
    int i = 0;
    int total = 0;
    while(i<k){
        //printf("%d\n", matrix_1_array[i]*matrix_2_array[i]);
        total = total + matrix_1_array[i]*matrix_2_array[i];
        if (i%height_2==height_2-1){
            printf("%d", total);
            total = 0;
            if (i%width_2==width_2-1){
                printf("\n");
            } else {
                printf(" ");
            }
        }
        ++i;
    }
    
    




    return 0;
}