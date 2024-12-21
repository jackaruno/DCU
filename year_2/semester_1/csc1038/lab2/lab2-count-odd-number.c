#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    int length = argc - 1;
    int nums[length];
    int j = 0;
    for (int i = 0; i < length; ++i){
        if ((atoi(argv[i+1]) % 2)==1){
            j += 1;
        }
    }
    printf("%d\n", j);
    return 0;

}