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

// Function to insert a node after a given position key
void insertAfterKey(struct Node* head, int key, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = head;

    // Traverse the circular doubly linked list to find the node with the given key
    do {
        if (current->data == key) {
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
            return;
        }
        current = current->next;
    } while (current != head);

    // If the key is not found, print an error message
    printf("Key not found in the circular doubly linked list.\n");
    free(newNode); // Free the memory allocated for the new node
}

// Function to print circular doubly linked list
void printCircularDoublyLinkedList(struct Node* head) {
    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    // Creating a circular doubly linked list with 5 elements
    struct Node* head = createNode(1);
    insertAfterKey(head, 1, 2);
    insertAfterKey(head, 2, 30);
    insertAfterKey(head, 30, 4);
    insertAfterKey(head, 4, 5);

    printf("Circular Doubly Linked List: ");
    printCircularDoublyLinkedList(head);

    // Inserting a node after a given key
    int key = 30;
    int dataToInsert = 6;
    insertAfterKey(head, key, dataToInsert);

    printf("Circular Doubly Linked List after insertion: ");
    printCircularDoublyLinkedList(head);

    // Free the memory allocated for the circular doubly linked list nodes
    struct Node* current = head->next;
    while (current != head) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
    printf("Circular Doubly Linked List deleted.\n");

    return 0;
}
