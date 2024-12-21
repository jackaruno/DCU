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
    int val;
    Node *next;
};


int find_degree(int length, char *nums[]);
void print_degree(int highest_degree);
int search_nums_list(Node *head, int num);
void add_to_index_list(int *index_list, int index_num);
int find_highest_degree(int *index_list);

int main(int argc, char *argv[]){
    int highest_degree = find_degree(argc, argv);
    print_degree(highest_degree);
    
    return 0;
}

int find_degree(int length, char *nums[]){
    //a list of index that the nums will that we find will be stored
    int index_list[length];
    // make the head of a linked list for the nums
    Node *head_nums_linked_list = (Node *)malloc(sizeof(Node));
    int index_num = 0;
    //search through the list finding the index of the num and if its allready looked at increase the count of that number at the index
    for (int i = 1;i<length;++i){
        index_num = search_nums_list(head_nums_linked_list, atoi(nums[i]));
        add_to_index_list(index_list, index_num);
    }
    int highest_degree = find_highest_degree(index_list);
    //return highest degree number
    return highest_degree;
}

int search_nums_list(Node *head, int num){
    //check if num is in the list allready
    int index = 0;
    Node *current = head;
    for (index = 0;current->next!=NULL;index++){
        if (current->val == num){
            return index; //if it is return the index of it in the list
        }
        current = current->next;
    }
    //if it isnt add another num to the list
    current->next = (Node *)malloc(sizeof(Node *));
    current->val = num;
    
    
    return index;
}

void add_to_index_list(int *index_list, int index_num){
    // increase count of the num at that index
    index_list[index_num] += 1;
}

int find_highest_degree(int *index_list){
    // find max of all the index list
    int max = index_list[0];
    for (int j = 1;index_list[j]!=0;j++){
        if (index_list[j]>max){
            max = index_list[j];
        }
    }
    return max;
}

void print_degree(int highest_degree){
    //print list
    printf("%d\n", highest_degree);
}