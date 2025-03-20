#include <stdio.h>
#define MAX_SIZE 6

// Defining the Queue structure
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) { 
	return (q->front == -1 || q->front > q->rear); 
}

// Function to check if the queue is full
int isFull(Queue* q) { 
	return (q->rear == MAX_SIZE-1); 
}

// Function to add an element to the queue (Enqueue operation)
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full, cannot enqueue %d\n", value);
        return;
    }
    if (q->front==-1) q->front = 0;	//this is needed from initialisation only
	q->rear++;
    q->items[q->rear] = value;
}

// Function to remove an element from the queue (Dequeue operation)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -999;
    }
    int front = q->items[q->front];
    q->front++;
    return front;
}

// Function to get the element at the front of the queue (Peek operation)
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -999; // return some default value or handle error differently
    }
    return q->items[q->front];
}

// Function to print the current queue
void printQueue(Queue* q) {
	printf("Front index is %d, rear index is %d. ", q->front, q->rear);
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Current Queue: ");
    int i;
    for (i=0; i<q->front; i++) {
    	printf("__ ");
	}
    for (; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    for (; i < MAX_SIZE; i++) {
    	printf("__ ");
	}
    printf("\n");
}

int main() {
    Queue q;
    initializeQueue(&q);
    printQueue(&q);

    printf("Enqueuing 10 ");
    enqueue(&q, 10);
    printQueue(&q);

    printf("Enqueuing 20 ");
	enqueue(&q, 20);
    printQueue(&q);

    printf("Enqueuing 30 ");
	enqueue(&q, 30);
    printQueue(&q);

    // Peek front element
    printf("Front element is: %d\n", peek(&q));

    printf("Dequeuing, got %d ", dequeue(&q));
    printQueue(&q);
    printf("Dequeuing, got %d ", dequeue(&q));
    printQueue(&q);
    printf("Dequeuing, got %d ", dequeue(&q));
    printQueue(&q);

	enqueue(&q, 40);
    printQueue(&q);
    enqueue(&q, 50);
    printQueue(&q);
    enqueue(&q, 60);
    printQueue(&q);
    enqueue(&q, 70);
    printQueue(&q);
    printf("Dequeuing, got %d ", dequeue(&q));
    printQueue(&q);

    return 0;
}
