#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
};


void make_linked_list(Node *head, char *nums, int len_nums, int find_num, int insert_num);
void print_list(Node *head);

int main(int argc, char *argv[]){
    // original list
    char nums[10] = {8, 7, 3, 4, 5, 6, 9, 2, 14, 12};
    int len_nums = 10;

    // getting arguments from command line
    int find_num = atoi(argv[1]);
    int insert_num = atoi(argv[2]);
    
    
    Node *head = (Node *)calloc((1), sizeof(Node));
    make_linked_list(head, nums, len_nums, find_num, insert_num);
    print_list(head);

    // free allocated memory
    Node *current = head;
    while (current != NULL){
        Node *next = current->next;
        free(current);
        current = next;
    }


    return 0;
}


void make_linked_list(Node *head, char *nums, int len_nums, int find_num, int insert_num){
    Node *current = head;
    //looping through all nums
    for (int i = 0;i<len_nums;++i){
        current->value = nums[i];
        //alocating memory for the next node
        current->next = (Node *)calloc((1),sizeof(Node));
        current = current->next;
        //checking if the next node is the one we are looking for
        if (nums[i]==find_num){
            //inserting the node and going on with the rest of the linked list
            current->value = insert_num;
            current->next = (Node *)calloc((1), sizeof(Node));
            current = current->next;
        }
    }
    current = NULL;
}

void print_list(Node *head){
    //printing each node of the linked list until the last one
    while (head->next!= NULL){
        printf("%d\n",head->value);
        head = head->next;
    }
}