#include <stdio.h>
#include <stdlib.h>

typedef struct Countries Countries;

struct Countries
{
    char name[30];
    char capital[40];
    int size;
    float pop;
};

void strcopy(char *dest, const char *source){
    int i;
    for (i = 0;source[i]!='\0';++i){
        dest[i] = source[i];
    }
    dest[i] = '\0';
}

float pop_avg(Countries *country, int length){
    float total = 0.00;
    for (int i = 0;i<length;++i){
        total += country[i].pop;
    }
    total = total / length;
    return total;
}




int main(int argc, char *argv[]){
    Countries country[50];
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
    int j = 0;
    int i = 0;
    for(i = 1;i<argc;i+=4){
        strcopy(country[j].name, argv[i]);
        strcopy(country[j].capital, argv[i+1]);
        country[j].size = atoi(argv[i+3]);
        country[j].pop = atof(argv[i+2]);
        printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", country[j].name, country[j].capital, country[j].size, country[j].pop);
        ++j;
    }
    printf("Population average: %.2f\n", pop_avg(country, j));

}