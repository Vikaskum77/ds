 #include <stdio.h>
#include <stdlib.h>

// Node structure for circular doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

// Function to traverse and print circular doubly linked list in forward direction
void traverseForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Function to traverse and print circular doubly linked list in backward direction
void traverseBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = head->prev; // Start from the last node
    do {
        printf("%d ", current->data);
        current = current->prev;
    } while (current != head->prev);
    printf("\n");
}

int main() {
    // Creating a circular doubly linked list with 5 elements
    struct Node* head = createNode(1);
    struct Node* second = createNode(2);
    struct Node* third = createNode(3);
    struct Node* fourth = createNode(4);
    struct Node* fifth = createNode(5);

    // Connecting nodes to form a circular doubly linked list
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;
    fifth->next = head;
    head->prev = fifth;

    // Traversing and printing the circular doubly linked list in forward direction
    printf("Circular Doubly Linked List (Forward): ");
    traverseForward(head);

    // Traversing and printing the circular doubly linked list in backward direction
    printf("Circular Doubly Linked List (Backward): ");
    traverseBackward(head);

    // Freeing allocated memory for nodes (deleting the circular doubly linked list)
    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);

    return 0;
}
