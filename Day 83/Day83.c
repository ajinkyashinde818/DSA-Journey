#include <stdio.h>
#include <stdlib.h>

struct queue {
    int data;
    struct queue* next;
};

void enqueue(struct queue** front, struct queue** rear, int val) {
    struct queue* new = (struct queue*)malloc(sizeof(struct queue));
    if (new == NULL) {
        printf("The Queue is Full\n");
    } else {
        new->data = val;
        new->next = NULL;

        if (*front == NULL && *rear == NULL) {
            *front = *rear = new;
        } else {
            (*rear)->next = new;
            *rear = new;
        }
        printf("The Inserted Element is: %d\n", val);
    }
}

void dequeue(struct queue** front, struct queue** rear) {
    if (*front == NULL) {
        printf("The Queue is Empty\n");
    } else {
        struct queue* temp = *front;
        printf("The Deleted Element is: %d\n", temp->data);
        *front = (*front)->next;

        if (*front == NULL) {
            *rear = NULL;
        }
        free(temp);
    }
}

void peek(struct queue* front) {
    if (front == NULL) {
        printf("The Queue is Empty\n");
    } else {
        printf("The Front Element is: %d\n", front->data);
    }
}

void display(struct queue* traverse) {
    if (traverse == NULL) {
        printf("The Queue is Empty\n");
        return;
    }
    while (traverse != NULL) {
        printf("The Element is: %d\n", traverse->data);
        traverse = traverse->next;
    }
    printf("\n");
}

int main() {
    struct queue* front = NULL;
    struct queue* rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 40);

    printf("\nQueue Elements:\n");
    display(front);
    peek(front);

    dequeue(&front, &rear);
    dequeue(&front, &rear);

    printf("\nAfter Deletion:\n");
    display(front);
    peek(front);

    return 0;
}