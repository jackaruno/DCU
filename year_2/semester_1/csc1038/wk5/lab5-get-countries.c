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
    Countries country[50];
    int j = 0;
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
    for (int i = 0;i<argc-1;i+=4){
        country[j].pop = atof(argv[i+3]);
        country[j].size = atoi(argv[i+4]);
        strcopy(country[j].name, argv[i+1]);
        strcopy(country[j].capital, argv[i+2]);
        printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country[j].name, country[j].capital, country[j].size, country[j].pop);
        ++j;
    }
    return 0;
}