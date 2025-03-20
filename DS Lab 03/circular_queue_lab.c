#include <stdio.h>
#define MAX_SIZE 6

// Defining the Queue structure
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
    int capacity;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
    q->capacity = 0;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) { 
	return (q->capacity == 0); 
}

// Function to check if the queue is full
int isFull(Queue* q) { 
	return (q->capacity == MAX_SIZE); 
}

// Function to add an element to the queue (Enqueue operation)
void enqueue(Queue* q, int value) {
	if (isFull(q)) {
        printf("Queue is full, cannot enqueue %d\n", value);
        return;
    }
    if (q->front==-1) q->front = 0;	//this is needed from initialisation only
	q->rear = (q->rear+1) % MAX_SIZE;
    q->items[q->rear] = value;
    q->capacity++; 
}

// Function to remove an element from the queue (Dequeue operation)
int dequeue(Queue* q) {
   ;
}

// Function to get the element at the front of the queue (Peek operation)
int peek(Queue* q) {
	;
}

// Function to print the current queue
void printQueue(Queue* q) {
	printf("Capacity is %d, Front index is %d, rear index is %d. ", q->capacity, q->front, q->rear);   
	if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
	printf("Current Queue: ");
	int i;
	for (i = 0; i < MAX_SIZE; i++) {
		if ((q->front <= q->rear && i >= q->front && i <= q->rear) ||			//not easy!
            (q->front > q->rear && (i >= q->front || i <= q->rear))) {
            printf("%d ", q->items[i]);
		} else {
			printf("__ ");
		}
		
	}
    printf("\n");
}

int main() {
    Queue q;
    initializeQueue(&q);
    printQueue(&q);

    enqueue(&q, 10);    
	printf("Enqueued 10 ");
    printQueue(&q);

	enqueue(&q, 20);
	printf("Enqueued 20 ");
    printQueue(&q);

	enqueue(&q, 30);
	printf("Enqueued 30 ");
    printQueue(&q);

    // Peek front element
    printf("Front element is: %d\n", peek(&q));

    printf("Dequeued, got %d ", dequeue(&q));
    printQueue(&q);
    printf("Dequeued, got %d ", dequeue(&q));
    printQueue(&q);
    printf("Dequeued, got %d ", dequeue(&q));
    printQueue(&q);

	enqueue(&q, 40);
	printf("Enqueued 40 ");
    printQueue(&q);
    
    enqueue(&q, 50);
    printf("Enqueued 50 ");
    printQueue(&q);
    
    enqueue(&q, 60);
    printf("Enqueued 60 ");
    printQueue(&q);
    
    enqueue(&q, 70);
    printf("Enqueued 70 ");
    printQueue(&q);
    
    enqueue(&q, 80);
    printf("Enqueued 80 ");
    printQueue(&q);
    
    enqueue(&q, 90);
    printf("Enqueued 90 ");
    printQueue(&q);
    
    enqueue(&q, 100);
    printf("Enqueued 100 ");
    printQueue(&q);
    
    printf("Dequeuing, got %d ", dequeue(&q));
    printQueue(&q);

    return 0;
}
