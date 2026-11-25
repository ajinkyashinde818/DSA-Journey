#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insert(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

void search(struct Node *head, int key) {
    while (head != NULL) {
        if (head->data == key) {
            printf("Element Found\n");
            return;
        }

        head = head->next;
    }

    printf("Element Not Found\n");
}

void update(struct Node *head, int oldValue, int newValue) {
    while (head != NULL) {
        if (head->data == oldValue) {
            head->data = newValue;
            printf("Element Updated\n");
            return;
        }

        head = head->next;
    }

    printf("Element Not Found\n");
}

void sortList(struct Node *head) {
    struct Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("List Sorted\n");
}

void deleteNode(struct Node **head, int key) {
    struct Node *temp;
    struct Node *del;

    if (*head == NULL) {
        printf("List is Empty\n");
        return;
    }

    if ((*head)->data == key) {
        temp = *head;
        *head = (*head)->next;
        free(temp);

        printf("Element Deleted\n");
        return;
    }

    temp = *head;

    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        del = temp->next;
        temp->next = del->next;
        free(del);

        printf("Element Deleted\n");
    } else {
        printf("Element Not Found\n");
    }
}

int main() {
    struct Node *head = NULL;
    int choice, value, oldValue, newValue;

    do {
        printf("\n--- SINGLY LINKED LIST ---\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Update\n");
        printf("5. Sort\n");
        printf("6. Delete\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(&head, value);
                break;

            case 2:
                display(head);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(head, value);
                break;

            case 4:
                printf("Enter old value: ");
                scanf("%d", &oldValue);

                printf("Enter new value: ");
                scanf("%d", &newValue);

                update(head, oldValue, newValue);
                break;

            case 5:
                sortList(head);
                break;

            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;

            case 7:
                printf("Program Ended\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while (choice != 7);

    return 0;
}