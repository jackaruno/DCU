#include <stdio.h>
#include <stdlib.h>


typedef struct Countries Countries;
struct Countries
{
    char name[30];
    char capital[40];
    float pop;
    int size;
};

void strcopy(char *dest, char *source){
    int i;
    for (i = 0;source[i]!='\0';++i){
        dest[i] = source[i];
    }
    dest[i] = '\0';
}

int main(int argc, char *argv[]){
    Countries c1 = {.pop = atof(argv[3]), .size = atoi(argv[4])};
    strcopy(c1.name, argv[1]);
    strcopy(c1.capital, argv[2]);
    printf("%s\n%s\n%.2f million people\n%d km2\n", c1.name, c1.capital, c1.pop, c1.size);
    return 0;
    
}
