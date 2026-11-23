#include <stdio.h>
#define max 5

int queue[max];
int front = -1;
int rear = -1;

void enqueue(int val) {
    if (rear == max - 1) {
        printf("The Queue is Full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = val;
        printf("The Inserted Element is: %d\n", val);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("The Queue is Empty\n");
    } else {
        printf("The Deleted Element is: %d\n", queue[front]);
        front++;
    }
}

void peek() {
    if (front == -1 || front > rear) {
        printf("The Queue is Empty\n");
    } else {
        printf("The Front Element is: %d\n", queue[front]);
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("The Queue is Empty\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("The Element is: %d\n", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);

    printf("\nQueue Elements:\n");
    display();
    peek();

    dequeue();
    dequeue();

    printf("\nAfter Deletion:\n");
    display();
    peek();

    return 0;
}