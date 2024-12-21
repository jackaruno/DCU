#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
//declaring what a node is
struct Node
{
    int value;
    Node *next;
};

void make_linked_list(char *nums[], int length, Node *linked_list);
void print_linked_list(Node *linked_list);
void free_linked_list(Node *linked_list);

int main(int argc, char *argv[]){
    //allocating memory to the head node
    Node *linked_list = (Node *)malloc(sizeof(Node));

    //creating the linked list
    make_linked_list(argv, argc, linked_list);

    //printing the linked list
    print_linked_list(linked_list->next);

    //free the linked list
    free_linked_list(linked_list);

    return 0;
}

void make_linked_list(char *nums[], int length, Node *linked_list){
    //creating current node
    Node *current = linked_list;

    //looping through the nums and creating the linked list
    for (int i = 1;i<length;++i){
        current->value = atoi(nums[i]); 
        current->next = (Node *)malloc(sizeof(Node));
        current = current->next;  
    }
    current->next = NULL;
}

void print_linked_list(Node *linked_list){
    while (linked_list->next){
        printf("%d\n", linked_list->value);
        linked_list = linked_list->next;
    }
}

void free_linked_list(Node *linked_list){
    Node *temp;
    while (linked_list){
        temp = linked_list;
        linked_list = linked_list->next;
        free(temp);
    }
}