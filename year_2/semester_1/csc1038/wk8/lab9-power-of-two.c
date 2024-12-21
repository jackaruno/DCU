#include <stdio.h>
#include <stdlib.h>

int is_power_of_two(int n){
    return (n & (n-1)) == 0;
}

int main(int argc, char *argv[]){
    //converts input into interger
    int n = atoi(argv[1]);

    //checks if the interger is a power of two
    if (is_power_of_two(n)){
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}