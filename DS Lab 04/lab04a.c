#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

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

typedef struct Stack {
	Node* head;
} Stack;

void initializeStack(Stack* stack) {
	stack->head = NULL;
}

int isEmpty(Stack* stack) {
	return stack->head == NULL;
}

void push(Stack* stack, int new_data) {
	Node* new_node = createNode(new_data);
	if (!new_node) {
		printf("\nStack Overflow");
		return;
	}
	new_node->next = stack->head;
	stack->head = new_node;
}

int pop(Stack* stack) {
	if (isEmpty(stack)) {
		printf("\nStack Underflow\n");
		return INT_MIN;
	} else {
		Node* temp = stack->head;
		int popped_data = stack->head->data;
		stack->head = stack->head->next;
		free(temp);
		return popped_data;
	}
}

int peek(Stack* stack) {
	if (!isEmpty(stack))
		return stack->head->data;
	else {
		printf("\nStack is empty");
		return INT_MIN;
	}
}

void displayStack(Stack* stack) {
	if (isEmpty(stack)) {
		printf("Stack is empty\n");
		return;
	}
	Node* current = stack->head;
	printf("Stack contents: ");
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

int countElements(Stack* stack) {
	int count = 0;
	Node* current = stack->head;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}

Node* find(Stack* stack, int data) {
	Node* current = stack->head;
	while (current != NULL) {
		if (current->data == data) {
			return current;
		}
		current = current->next;
	}
	return NULL;
}

int main() {
	Stack stack;
	initializeStack(&stack);
	push(&stack, 11);
	push(&stack, 22);
	push(&stack, 33);
	push(&stack, 44);
	
	printf("Top element is %d\n", peek(&stack));
	
	displayStack(&stack);
	
	printf("Removing two elements...\n");
	pop(&stack);
	pop(&stack);
	
	printf("Top element is %d\n", peek(&stack));
	
	displayStack(&stack);
	
	printf("Number of elements in the stack: %d\n", countElements(&stack));
	
	Node* foundNode = find(&stack, 11);
	if (foundNode) {
		printf("Node with data %d found in stack\n", foundNode->data);
	} else {
		printf("Node with data 11 not found in stack\n");
	}
	
	return 0;
}

