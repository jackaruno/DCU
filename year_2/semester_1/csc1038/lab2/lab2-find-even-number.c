#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    int length = argc - 1;
    int nums[length];
    int j = 1;
    char ans = 'F';
    for (int i = 0; i < length; ++i){
        nums[i] = atoi(argv[i+1]);
        if ((nums[i] % 2)==0){
            ans = 'T';
            printf("%d - ", i);
            printf("%d\n", atoi(argv[j]));
        }
        j += 1;
    }
    if (ans!='T'){
        printf("Not found!\n");
    }
    return 0;
}