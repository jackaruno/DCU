#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
    Node *prev;
};

Node *create_doubly_linked_list(char *nums[], int length, Node *head);
void print_list(Node *head);
int pop(Node **tail);
void push(Node **tail, int num);
void free_list(Node *head);

int main(int argc, char *argv[]){
    Node *head = (Node *)malloc(sizeof(Node));
    Node *tail = head;
    tail = create_doubly_linked_list(argv, argc, head);
    
    //poping the list
    int num_1 = pop(&tail);
    int num_2 = pop(&tail);
    int num_3 = pop(&tail);
    int num_4 = pop(&tail);

    //pushing nums onto list
    push(&tail, num_2);
    push(&tail, num_1);
    
    //printing the list
    print_list(head->next);

    //free allocated memory
    free_list(head);
    return 0;
}

Node *create_doubly_linked_list(char *nums[], int length, Node *head){
    //creating the linked list
    Node *current = head;
    current->prev = NULL;
    for (int i = 1;i<length;i++){
        current->value = atoi(nums[i]);
        //assigning what the next node on the list is
        current->next = (Node *)malloc(sizeof(Node));
        //assigning what the previous node on the list is
        current->next->prev = current;
        current = current->next;

    }
    current->next = NULL;
    return current->prev;
}

void print_list(Node *head){
    //printing the list
    while (head){
        printf("%d\n",head->value);
        head = head->next;
    }
}

int pop(Node **tail){
    //popping the last node of the list
    int temp = (*tail)->value;
    Node *prev_node = (*tail)->prev;
    //free the last node when it is popped
    free(*tail);
    *tail = prev_node;
    (*tail)->next = NULL;
    //returning the num of the last node
    return temp;
}

void push(Node **tail, int num){
    //pushing a ned node to the end of the list
    (*tail)->next = (Node *)calloc((1),sizeof(Node));
    (*tail)->next->value = num;
    (*tail)->next->prev = (*tail);
    (*tail)->next->next = NULL;
    (*tail) = (*tail)->next;
}

void free_list(Node *head){
    //free allocated memory when finished
    while (head){
        Node *next = head->next;
        free(head);
        head = next;
    }
}
