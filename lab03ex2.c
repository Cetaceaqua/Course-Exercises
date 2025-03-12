#include <stdio.h>
#define MAX_SIZE 6

typedef struct {
	int items[MAX_SIZE];
	int front;
	int rear;
} Queue;

void initializeQueue(Queue* q) {
	q->front = -1;
	q->rear = -1;
}

int isEmpty(Queue* q) { 
	return (q->front == -1 || q->front > q->rear); 
}

int isFull(Queue* q) { 
	return (q->rear == MAX_SIZE-1); 
}

void enqueue(Queue* q, int value) {
	if (isFull(q)) {
		printf("Queue is full, cannot enqueue %d\n", value);
		return;
	}
	if (q->front == -1) q->front = 0;
	q->rear++;
	q->items[q->rear] = value;
}

int dequeue(Queue* q) {
	if (isEmpty(q)) {
		printf("Queue is empty\n");
		return -999;
	}
	int front = q->items[q->front];
	q->front++;
	return front;
}

int peek(Queue* q) {
	if (isEmpty(q)) {
		printf("Queue is empty\n");
		return -999;
	}
	return q->items[q->front];
}

void printQueue(Queue* q) {
	printf("Front index is %d, rear index is %d. ", q->front, q->rear);
	if (isEmpty(q)) {
		printf("Queue is empty\n");
		return;
	}
	printf("Current Queue: ");
	int i;
	for (i = 0; i < q->front; i++) {
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
	
	for (int i = 1; i <= MAX_SIZE; i++) {
		printf("Enqueuing %d ", i);
		enqueue(&q, i);
		printQueue(&q);
	}
	
	printf("Enqueuing 100 ");
	enqueue(&q, 100);
	printQueue(&q);
	
	return 0;
}



