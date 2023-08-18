#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void insertEnd(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}


void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;


    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);


    printf("Linked List: ");
    display(head);

    return 0;
}

