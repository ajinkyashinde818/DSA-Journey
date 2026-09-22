#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void display(struct Node *ptr){
    while (ptr!=NULL)
    {
        printf("The Original Elements is: %d\n",ptr->data);
        ptr=ptr->next;
    }
    
}

int main(){
    struct Node * head=(struct Node*)malloc(sizeof(struct Node));
    struct Node * second=(struct Node*)malloc(sizeof(struct Node));
    struct Node * third=(struct Node*)malloc(sizeof(struct Node));
    struct Node * fourth=(struct Node*)malloc(sizeof(struct Node));
    struct Node * fifth=(struct Node*)malloc(sizeof(struct Node));

    head->data=9;
    head->next=second;

    second->data=12;
    second->next=third;

    third->data=4;
    third->next=fourth;

    fourth->data=30;
    fourth->next=fifth;

    fifth->data=20;
    fifth->next=NULL;

    display(head);

    struct Node * previous;
    struct Node * current;
    struct Node * next;

    previous = NULL;
    current = head;

    while (current!=NULL)
    {
        next=current->next;
        current->next=previous;
        previous=current;
        current=next;
    }
    head = previous;
    printf("After Reversing The Elements:\n");
    display(head);


    return 0;
}