//🧠 Day 21 Problem: Find the Middle Element of a Singly Linked List

// Given:

// 10 → 20 → 30 → 40 → 50 → NULL

// Find the middle element.

// Expected output
// Middle Element = 30


#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void display(struct Node *ptr){
    while (ptr!=NULL)
    {
        printf("The Elements is: %d\n",ptr->data);
        ptr=ptr->next;
    }
    
}

int main(){
    struct Node * head=(struct Node*)malloc(sizeof(struct Node));
    struct Node * second=(struct Node*)malloc(sizeof(struct Node));
    struct Node * third=(struct Node*)malloc(sizeof(struct Node));
    struct Node * fourth=(struct Node*)malloc(sizeof(struct Node));
    struct Node * fifth=(struct Node*)malloc(sizeof(struct Node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=fifth;

    fifth->data=50;
    fifth->next=NULL;

    
    display(head);

    struct Node *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    
    int num=count/2;
    temp=head;
    int position=0;
    while (position<num)
    {
       temp=temp->next;
       position++;
    }
    
    printf("The Middle Element is:%d\n",temp->data);

    return 0;
}