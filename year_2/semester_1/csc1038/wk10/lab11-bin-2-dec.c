#include <stdio.h>
#include <stdlib.h>

typedef struct Binary Binary;

struct Binary
{   
    Binary *prev;
    int val;
    Binary *next;
};

Binary *form_binary_ll(char *nums[], int length, Binary *head);
void get_total(Binary *tail, int *ans);



int main(int argc, char *argv[]){
    Binary *head = (Binary *)malloc(sizeof(Binary));
    Binary *tail = (Binary *)malloc(sizeof(Binary));
    tail = form_binary_ll(argv, argc, head);
    if (tail==NULL){
        return 0;
    }
    int ans = 0;
    get_total(tail, &ans);
    printf("%d\n",ans);

    return 0;
}

Binary *form_binary_ll(char *nums[], int length, Binary *head){
    Binary *current = head;
    current->prev = NULL;
    current->next = (Binary *)malloc(sizeof(Binary));
    for (int i = 1;nums[i]!=NULL;current=current->next){
        if (i>8){
            printf("Too many binary digits entered.\n");
            return NULL;
        }
        else if (nums[i][0] != '1' && nums[i][0] != '0'){
            printf("Only digits 1 and 0 are permitted.\n");
            return NULL;
        }
        current->val = atoi(nums[i]);
        current->next = (Binary *)malloc(sizeof(Binary));
        current->next->prev = current;
        i+=1;
    }
    current->next = NULL;
    return current->prev;

}

void get_total(Binary *tail, int *ans){
    int total = 0;
    int i = 1;
    while (tail){
        total += tail->val * i;
        i *= 2;
        tail = tail->prev;
    }
    *ans = total;
}