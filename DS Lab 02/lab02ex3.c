#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
	int arr[MAX_SIZE];  
	int top;        
} Stack;

void initialize(Stack *stack) {
	stack->top = -1;  
}

int isEmpty(Stack *stack) {
	return stack->top == -1;  
}

int isFull(Stack *stack) {
	return stack->top == MAX_SIZE - 1;  
}

void push(Stack *stack, int value) {
	if (isFull(stack)) {
		printf("Stack Overflow\n");
		return;
	}
	stack->arr[++stack->top] = value;
	printf("Pushed %d onto the stack\n", value);
}

int pop(Stack *stack) {
	if (isEmpty(stack)) {
		printf("Stack Underflow\n");
		return -1;
	}
	int popped = stack->arr[stack->top];
	stack->top--;
	printf("Popped %d from the stack\n", popped);
	return popped;
}

int peek(Stack *stack) {
	if (isEmpty(stack)) {
		printf("Stack is empty\n");
		return -1;
	}
	return stack->arr[stack->top];
}

void printStack(Stack *stack) {
	if (isEmpty(stack)) {
		printf("Stack is empty\n");
		return;
	}
	for (int i = stack->top; i >= 0; i--) {
		printf("%d\n", stack->arr[i]);
	}
}

int main() {
	Stack stack;
	initialize(&stack);  
	
	push(&stack, 8);
	push(&stack, 10);
	push(&stack, 16);
	push(&stack, 17);

	printf("Stack content:\n");
	printStack(&stack);
	
	return 0;
}

