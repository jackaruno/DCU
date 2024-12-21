#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    float value;
    Node *next;
    Node *prev;
};

Node *create_doubly_linked_list(char *nums[], int length, Node *head);
void print_list(Node *head);

int main(int argc, char *argv[]){
    Node *head, *tail;
    head = (Node *)calloc((1),sizeof(Node));
    tail = (Node *)calloc((1),sizeof(Node));
    tail = create_doubly_linked_list(argv, argc, head);
    print_list(tail);
    return 0;
}

Node *create_doubly_linked_list(char *nums[], int length, Node *head){
    Node *current = head;
    current->prev = NULL;
    for (int i = 1;i<length;i++){
        current->value = atoi(nums[i]);
        current->next = (Node *)calloc(1,sizeof(Node));
        current->next->prev = current;
        current = current->next;

    }
    current->next = NULL;
    return current->prev;
}

void print_list(Node *tail){
    for (int i = 0;tail->prev!=NULL;tail=tail->prev){
        printf("%.2f\n",tail->value);
    }
}
