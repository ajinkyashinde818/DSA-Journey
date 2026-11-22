#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int data;
    struct Stack* next;
};

void push(struct Stack** check, int value) {
    struct Stack* new = (struct Stack*)malloc(sizeof(struct Stack));
    if (new == NULL) {
        printf("The Stack is Full\n");
    } else {
        new->data = value;
        new->next = *check;
        *check = new;
    }
}

void pop(struct Stack** check) {
    if (*check == NULL) {
        printf("Stack is Empty\n");
    } else {
        struct Stack* temp = *check;
        printf("Popped element: %d\n", temp->data);
        *check = (*check)->next;
        free(temp);
    }
}

void peek(struct Stack* top) {
    if (top == NULL) {
        printf("Stack is Empty\n");
    } else {
        printf("Top element is: %d\n", top->data);
    }
}

void display(struct Stack* traverse) {
    if (traverse == NULL) {
        printf("Stack is Empty\n");
        return;
    }
    while (traverse != NULL) {
        printf("%d ", traverse->data);
        traverse = traverse->next;
    }
    printf("\n");
}

int main() {
    struct Stack* top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    push(&top, 40);
    push(&top, 50);
    push(&top, 60);

    printf("The Inserted Elements:\n");
    display(top);
    peek(top);

    pop(&top);
    pop(&top);

    printf("After Deletion:\n");
    display(top);
    peek(top);

    return 0;
}