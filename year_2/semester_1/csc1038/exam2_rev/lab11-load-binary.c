#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name;
    char college;
    int age;
    float grade;
};

int main(int argc, char *argv[]){
    FILE *pfile = NULL;
    char *filename = "studentBinary.bin";
    pfile = fopen(filename, "rb");
    if (!pfile){
        printf("error");
    }
    Student s;

    int *namelength;
    int collegelength;

    fread(&namelength, sizeof(int), 1, pfile);
    fread(s.name, sizeof(char), namelength, pfile);
    fread(&collegelength, sizeof(int), 1, pfile);
    fread(s.college, sizeof(char), collegelength, pfile);
    fread(&s.age, sizeof(int), 1, pfile);
    fread(&s.grade, sizeof(float), 1, pfile);
    fclose(pfile);
    printf("Name: %s\n", s.name);
    printf("College: %s\n", s.college);
    printf("Age: %d\n", s.age);
    printf("Grade: %.2f\n", s.grade);


    return 0;
}