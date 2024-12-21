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

float find_average_csce(Student *students, int count){
    float total = 0.00;
    float csce_count = 0;
    for (int i = 0;i<count;++i){
        if (strcmp((students+i)->programme, "CSCE") == 0){
            total += ((students+i)->grade);
            csce_count += 1;
        }
    }
    return total/csce_count;
}

float find_average(Student *students, int count){
    float total = 0.00;
    for (int i = 0;i<count;++i){
        total += ((students+i)->grade);
    }
    return total/count;
}

void print_top_students(Student *students, int count, float average){
    for (int i = 0;i<count;++i){
        if (strcmp((students+i)->programme, "CSCE") == 0){
            if (((students+i)->grade)>=average){
                printf("%s, ", (students+i)->name);
                printf("%.2f\n", (students+i)->grade);
            }
        }
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
    float average_csce = find_average_csce(students, (argc)/3);
    float average = find_average(students, (argc/3));
    print_top_students(students, (argc/3), average);
    printf("Average grade: %.2f\n", average);
    //print_students(students, (argc)/3);
    return 0;
}