// 🧠 Day 22 — Detect a Cycle in a Singly Linked List

// Consider:

// 1 → 2 → 3 → 4 → 5
//         ↑         ↓
//         ← ← ← ← ←

// Here, 5 points back to 3, so the list contains a cycle.



#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

void traversing(struct Node *ptr){
    while(ptr!=NULL){
        printf("The Elements is:%d\n",ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    struct Node*head=(struct Node*)malloc(sizeof(struct Node));
    struct Node*two=(struct Node*)malloc(sizeof(struct Node));
    struct Node*three=(struct Node*)malloc(sizeof(struct Node));
    struct Node*four=(struct Node*)malloc(sizeof(struct Node));
    struct Node*five=(struct Node*)malloc(sizeof(struct Node));

    head->data=1;
    head->next=two;

    two->data=2;
    two->next=three;

    three->data=3;
    three->next=four;

    four->data=4;
    four->next=five;

    five->data=5;
    five->next=three;

    struct Node* slow=head;
    struct Node* fast=head;
    int cycleFound = 0;


    while (fast!=NULL && fast->next!=NULL)
    {
        
        slow=slow->next;
        fast=fast->next->next;

        if (slow==fast){
            printf("The Cycle is Found");
            cycleFound=1;
            break;
        }
    }

    if (cycleFound == 1){
        printf("The Cycle is Found");
    }else{
        printf("The Cycle is Not Found");
    }
    
    return 0;
}