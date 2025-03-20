#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void initializeQueue(Queue* q_ptr) {
    q_ptr->front = NULL;
    q_ptr->rear = NULL;
}

void printQueue(Queue* q_ptr) {
    if (q_ptr->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node* current = q_ptr->front;
    printf("Queue contents: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void enqueue(Queue* q_ptr, int value) {
    Node* new_node = createNode(value);
    if (q_ptr->rear == NULL) {
        q_ptr->front = q_ptr->rear = new_node;
        return;
    }
    q_ptr->rear->next = new_node;
    q_ptr->rear = new_node;
}

int isEmpty(Queue* q_ptr) {
    return (q_ptr->front == NULL);
}

int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    return q->front->data;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return INT_MIN;
    }
    Node* temp = q->front;
    int removed_data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return removed_data;
}

int main() {
    Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);

    printQueue(&queue);
    printf("Front element: %d\n", peek(&queue));

    printf("Dequeued: %d\n", dequeue(&queue));
    printQueue(&queue);

    printf("Dequeued: %d\n", dequeue(&queue));
    printQueue(&queue);

    return 0;
}