/**Introduction
Author: Jack Mcmahon
description: This file find the degree of a list of numbers
            using a find degree function making a index and
            numbers list.
date 16/12/24

**/




#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
    Node *prev;
};


int find_diagonal(char *nums[], int width, int height, int count_of_nums);
void create_linked_list(char *argv[], int length, int count_of_nums, Node *zero_matrix, int width);
void print_matrix(Node *head, int height, int width);
void create_zero_matrix(Node *zero_matrix, int width, int height);

int main(int argc, char *argv[]){
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    int count_of_nums = atoi(argv[3]);

    Node *zero_matrix = (Node *)malloc(sizeof(Node));
    create_zero_matrix(zero_matrix, width, height);
    create_linked_list(argv, argc, count_of_nums, zero_matrix, height);
    print_matrix(zero_matrix, height, width);
    printf("Sum of main diagonal: ");





    int diagonal_sum = find_diagonal(argv, width, height, count_of_nums);
    printf("%d\n",diagonal_sum);
    return 0;
}

void create_zero_matrix(Node *zero_matrix, int width, int height){
    Node *prev;
    Node *current = zero_matrix;
    current->prev = NULL;
    int t = width*height;
    for (int i = 0;i<t;i++){
        current->next = (Node *)malloc(sizeof(Node));
        current->value = 0;
        prev = current;
        //printf("%d\n",current->value);
        current = current->next;
        current->prev = prev;
    }
    current = NULL;
}


void create_linked_list(char *argv[], int length, int count_of_nums, Node *zero_matrix, int width){
    Node *current = zero_matrix->next;
    //printf("\n%d\n\n", current->next->value);
    int i = 0;
    int index_skip = 0;
    int num;
    int x_cord;
    int y_cord;
    int skip = 0;
    int j;
    while (i<count_of_nums){
        index_skip = (3*i)+4;
        num = atoi(argv[index_skip]);
        y_cord = atoi(argv[index_skip+1]);
        x_cord = atoi(argv[index_skip+2]);
        //printf("%d %d %d %d\n", num, y_cord, x_cord, width);
        skip = x_cord + (width*y_cord);
        j = 0;
        current = zero_matrix;
        while (j<skip){
            current = current->next;
            j += 1;
        }
        current->value = num;
        i += 1;
    }

}

void print_matrix(Node *head, int width, int length){
    Node *current = head;
    for (int i = 1;current->next!=NULL;current=current->next){
        printf("%d", current->value);
        if (i%width==0&&i!=1){
            printf("\n");
        } else {
            printf(" ");
        }
        i+=1;
    }
    current = head;
        
}

int find_diagonal(char *nums[], int width, int height, int count_of_nums){
    int total = 0;
    
    
    if (width!=height){
        return total;
    } else {
        for (int i = 4;i<(3*count_of_nums)+4;i=i+3){
            total += atoi(nums[i]);
        }
    }
    return total;
}