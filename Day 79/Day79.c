#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertbegin(struct Node** ptr) {
    struct Node* begin = (struct Node*)malloc(sizeof(struct Node));
    begin->data = 0;
    begin->next = *ptr;
    *ptr = begin;
}

void insertend(struct Node** ptr) {
    struct Node* end = (struct Node*)malloc(sizeof(struct Node));
    end->data = 5;
    end->next = NULL;

    if (*ptr == NULL) {
        *ptr = end;
        return;
    }

    struct Node* temp = *ptr;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = end;
}

void insertatspecific(struct Node** ptr) {
    struct Node* spec = (struct Node*)malloc(sizeof(struct Node));
    spec->data = 44;
    int pos = 4;
    struct Node* temp = *ptr;

    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp != NULL) {
        spec->next = temp->next;
        temp->next = spec;
    }
}

void deletefrombegin(struct Node** ptr) {
    if (*ptr == NULL) {
        printf("The LL is Empty\n");
        return;
    }

    struct Node* temp = *ptr;
    *ptr = (*ptr)->next;
    free(temp);
}

void deletefromend(struct Node** ptr) {
    if (*ptr == NULL) {
        printf("The LL is Empty\n");
        return;
    }

    if ((*ptr)->next == NULL) {
        free(*ptr);
        *ptr = NULL;
        return;
    }

    struct Node* temp = *ptr;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void deleteatspecific(struct Node** ptr, int pos) {
    if (*ptr == NULL) {
        printf("The LL is Empty\n");
        return;
    }

    if (pos == 0) {
        struct Node* temp = *ptr;
        *ptr = (*ptr)->next;
        free(temp);
        return;
    }

    struct Node* temp = *ptr;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* one = (struct Node*)malloc(sizeof(struct Node));
    struct Node* two = (struct Node*)malloc(sizeof(struct Node));
    struct Node* three = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = one;

    one->data = 2;
    one->next = two;

    two->data = 3;
    two->next = three;

    three->data = 4;
    three->next = NULL;

    struct Node* ptr = head;
    printf("Original list:\n");
    while (ptr != NULL) {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }

    insertbegin(&head);
    insertend(&head);
    insertatspecific(&head);
    deletefrombegin(&head);
    deletefromend(&head);
    deleteatspecific(&head, 3);

    printf("After all insertions and deletions:\n");
    ptr = head;
    while (ptr != NULL) {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}