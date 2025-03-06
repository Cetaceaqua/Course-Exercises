#include <stdio.h>

int test(int condition, char* message) { 
	if (!condition) { 
		printf("Error: %s\n", message); 
		return 1; 
	} 
	return 0; 
}

int f(int n) {
	if (n < 0) {
		return 0;	
	}
	if (n == 0) {
		return 1;
	}
	return n * f(n - 1);
}

int main() {
	test(f(5) == 120, "Error in function f");
	test(f(-1) == 0, "Error in function f for negative input");
	
	printf("All tests passed");
	return 0;
}
