#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415
int main(int argc, char * argv[])
{
    if (argv[1]){
        if (argv[1]&&argv[2]){
            float rad = atoi(argv[1]);
            float height = atoi(argv[2]);
            if ((rad>=0)&&(height>=0)){
                float area = (((2*PI) * (rad)) * (height)) + ((2*PI) * ((rad)*(rad)));
                printf("%.2f\n", area);
            } 
            else {
                printf("The radious or height cannot be negative!\n");
            }
        }
        else {
            printf("Two arguments needed!\n");
        }
    }
    else {
        printf("No input given!\n");
    }
    return 0;
}