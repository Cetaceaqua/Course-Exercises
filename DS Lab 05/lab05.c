#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
	int *arr;
	int front;
	int rear;
	int capacity;
} Queue;

void initializeQueue(Queue* q, int capacity) {
	q->capacity = capacity;
	q->arr = (int*)malloc(capacity * sizeof(int));
	q->front = -1;
	q->rear = -1;
}

void printQueue(Queue* q) {
	if (q->front == -1) {
		printf("Queue is empty\n");
		return;
	}
	
	printf("Queue elements: ");
	for (int i = q->front; i != q->rear; i = (i + 1) % q->capacity) {
		printf("%d ", q->arr[i]);
	}
	printf("%d\n", q->arr[q->rear]);
}

void enqueue(Queue* q, int value) {
	if ((q->rear + 1) % q->capacity == q->front) {
		printf("Queue is full, cannot enqueue %d\n", value);
		return;
	}
	
	if (q->front == -1) {
		q->front = 0;
	}
	
	q->rear = (q->rear + 1) % q->capacity;
	q->arr[q->rear] = value;
}

int isEmpty(Queue* q) {
	return q->front == -1;
}

int peek(Queue* q) {
	if (isEmpty(q)) {
		printf("Queue is empty\n");
		return -1;
	}
	return q->arr[q->front];
}

int dequeue(Queue* q) {
	if (isEmpty(q)) {
		printf("Queue is empty, cannot dequeue\n");
		return -1;
	}
	
	int dequeuedValue = q->arr[q->front];
	
	if (q->front == q->rear) {
		q->front = q->rear = -1;
	} else {
		q->front = (q->front + 1) % q->capacity;
	}
	
	return dequeuedValue;
}

int main() {
	Queue q;
	initializeQueue(&q, 5);
	
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);
	enqueue(&q, 50);
	
	printQueue(&q);
	
	printf("Dequeued value: %d\n", dequeue(&q));
	printQueue(&q);
	
	printf("Front element is: %d\n", peek(&q));
	
	enqueue(&q, 60);
	printQueue(&q);
	
	return 0;
}

