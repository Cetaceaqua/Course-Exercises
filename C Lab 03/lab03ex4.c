#include <stdio.h>

int operator_precedence(int a, int b, int c) {
	return a * b / c + a - b % c;
}

int main() {
	printf("%d", operator_precedence(3, 2, 1));
	return 0;
}
