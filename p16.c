#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue (insert at the rear) a new element
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
        newNode->next = newNode->prev = newNode; // Make it circular
    } else {
        newNode->next = queue->front;
        newNode->prev = queue->rear;
        queue->rear->next = newNode;
        queue->rear = newNode;
        queue->front->prev = newNode;
    }
}

// Function to dequeue (remove from the front) an element
void dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    if (queue->front == queue->rear) {
        free(queue->front);
        queue->front = queue->rear = NULL;
    } else {
        struct Node* temp = queue->front;
        queue->front = queue->front->next;
        queue->front->prev = queue->rear;
        queue->rear->next = queue->front;
        free(temp);
    }
}

// Function to display the elements in the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = queue->front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != queue->front);
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    display(queue);

    dequeue(queue);
    display(queue);

    enqueue(queue, 4);
    display(queue);

    return 0;
}