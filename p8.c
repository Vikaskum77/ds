 #include <stdio.h>
#include <stdlib.h>

 
struct Node {
    int data;
    struct Node* next;
};

 
void traverse(struct Node* head) {
    struct Node* current = head;

    printf("Linked List elements: ");
     
    while (current != NULL) {
        printf("%d-> ", current->data);
        current = current->next;
    }
    printf("\n");
}

 
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = head;
    return newNode;  
}

 
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return NULL;
    }

    if (head->next == NULL) {
        
        free(head);
        return NULL;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

     
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    
    free(current);
    prev->next = NULL;  
    return head;
}

int main() {
    struct Node* head = NULL;  

     
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

     
    //printf("Initial ");
    traverse(head);

    // Delete node at the end
    head = deleteAtEnd(head);
    printf("After deleting node at the end: ");
    traverse(head);

    

    return 0;
}
