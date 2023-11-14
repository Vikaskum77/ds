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
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Function to traverse and print elements of the circular doubly linked list
void traverseCircularDoublyLinkedList(struct Node* head) {
    if (head == NULL) {
        printf("Empty circular doubly linked list\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Function to insert a node after a given position
void insertAfterPosition(struct Node* head, int position, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = head;
    int count = 1;

    // Traverse to the given position
    while (count < position && current->next != head) {
        current = current->next;
        count++;
    }

    if (count < position) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

// Function to delete the entire circular doubly linked list
void deleteCircularDoublyLinkedList(struct Node* head) {
    if (head == NULL) {
        return; // Nothing to delete
    }

    struct Node* current = head;
    do {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    } while (current != head);
}

int main() {
    // Creating a circular doubly linked list
    struct Node* head = createNode(10);
    head->next = head->prev = head;

    // Inserting nodes after given positions
    insertAfterPosition(head, 1, 25);
    insertAfterPosition(head, 2, 33);
    insertAfterPosition(head, 2, 45);
        insertAfterPosition(head, 3, 85);


    // Traversing and printing the circular doubly linked list
    printf("Circular Doubly Linked List elements: ");
    traverseCircularDoublyLinkedList(head);

    // Deleting the entire circular doubly linked list
    deleteCircularDoublyLinkedList(head);
    printf("Circular Doubly Linked List deleted.\n");

    return 0;
}
