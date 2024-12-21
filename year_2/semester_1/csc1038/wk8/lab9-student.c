#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Student Student;
void print_students(Student *students, int count);

struct Student
{
    char name[20];
    char programme[20];
    float grade;
};

void print_students(Student *students, int count){
    for (int i = 0;i<count;++i){
        printf("%s, ", (students+i)->name);
        printf("%s, ", (students+i)->programme);
        printf("%.2f\n", (students+i)->grade);
    }
}


int main(int argc, char *argv[]){
    //allocating memory//
    Student *students;
    students = (Student*)calloc(2, sizeof(Student));
    if(!students){
        printf("Not enough memory");
        exit(0);
    };
    //adding extra memroy if theres more than 2 students//
    if (argc-1>2){
        students = (Student*)realloc(students, argc*sizeof(Student));
    }
    //string copying//
    int students_index = 0;
    for (int i = 0;i*3<argc-1;++i){
        students_index = (3*i);
        strcpy((students+i)->name, argv[students_index+1]);
        strcpy((students+i)->programme, argv[students_index+2]);
        (students+i)->grade = atof(argv[students_index+3]);
    }
    print_students(students, (argc)/3);
    return 0;
}