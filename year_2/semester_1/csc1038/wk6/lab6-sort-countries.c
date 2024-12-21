#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Countries Countries;
struct Countries
{
    char* name;
    char* capital;
    int size;
    float pop;
};

void swap(Countries *country_1, Countries *country_2){
    Countries temp;
    temp = *country_1;
    *country_1 = *country_2;
    *country_2 = temp;
}

void bubblesort(Countries country[50], int country_count){
    bool swapped;
    for (int i = 0;i<country_count-1;++i){
        swapped = false;
        for (int j = 0;j<country_count-i-1;++j){
            if (country[j].pop<country[j+1].pop){
                //printf("%.2f %.2f\n", country[j].pop, country[j+1].pop);
                swap(&country[j], &country[j+1]);
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
    }
}

void print_small_countries(int country_count, Countries *countries){
    for (int i = 0;i<country_count;++i){
        printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", countries[i].name, countries[i].capital, countries[i].size, countries[i].pop);
    }
}

void print_array(){
    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
}


int main(int argc, char *argv[]){
    int country_count = (argc-1)/4;
    Countries country[country_count];
    //int j = 0;
    for (int i = 0;i<country_count;i++){
        // strcopy(argv[i], country[j].name);
        // strcopy(argv[i+1], country[j].capital);
        int country_index = 1+(i*4);
        country[i].name = (argv[country_index]);
        country[i].capital = (argv[country_index+1]);
        country[i].size = atoi(argv[country_index+3]);
        country[i].pop = atof(argv[country_index+2]);
    }
    print_array();
    bubblesort(country, country_count);
    print_small_countries(country_count, country);
    return 0;
}
