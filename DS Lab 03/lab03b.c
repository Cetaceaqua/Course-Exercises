#include <stdio.h>
#define MAX_SIZE 6

typedef struct {
	int items[MAX_SIZE];
	int front;
	int rear;
	int capacity;
} Queue;

void initializeQueue(Queue* q) {
	q->front = -1;
	q->rear = -1;
	q->capacity = 0;
}

int isEmpty(Queue* q) { 
	return (q->capacity == 0); 
}

int isFull(Queue* q) { 
	return (q->capacity == MAX_SIZE); 
}

void enqueue(Queue* q, int value) {
	if (isFull(q)) {
		printf("Queue is full, cannot enqueue %d\n", value);
		return;
	}
	if (q->front == -1) q->front = 0;
	q->rear = (q->rear + 1) % MAX_SIZE;  // Circular increment of rear
	q->items[q->rear] = value;
	q->capacity++; 
}

int dequeue(Queue* q) {
	if (isEmpty(q)) {
		printf("Queue is empty\n");
		return -999;
	}
	
	int frontValue = q->items[q->front];
	if (q->front == q->rear) {
		q->front = -1;  // Reset queue when it becomes empty
		q->rear = -1;
	} else {
		q->front = (q->front + 1) % MAX_SIZE;  // Circular increment of front
	}
	q->capacity--;  
	return frontValue;
}

int peek(Queue* q) {
	if (isEmpty(q)) {
		printf("Queue is empty\n");
		return -999;
	}
	return q->items[q->front];
}

void printQueue(Queue* q) {
	printf("Capacity is %d, Front index is %d, rear index is %d. ", q->capacity, q->front, q->rear);   
	if (isEmpty(q)) {
		printf("Queue is empty\n");
		return;
	}
	
	printf("Current Queue: ");
	int i;
	for (i = 0; i < MAX_SIZE; i++) {
		// If the queue is not wrapped, print elements from front to rear
		if ((q->front <= q->rear && i >= q->front && i <= q->rear) || 
			// If the queue is wrapped (front > rear), print elements from front to end and from start to rear
			(q->front > q->rear && (i >= q->front || i <= q->rear))) {
			printf("%d ", q->items[i]);  // Element
		} else {
			printf("%d ", q->items[i]);  // Empty slot
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

