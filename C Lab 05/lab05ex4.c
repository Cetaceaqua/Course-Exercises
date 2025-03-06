#include <stdio.h>

int test(int condition, char* message) { 
	if (!condition) { 
		printf("Error: %s\n", message); 
		return 1; 
	} 
	return 0; 
}

int sum(int n) {
	if (n == 0) {
		return 0;
	}
	return n + sum(n - 1);
}

int main() {
	test(sum(5) == 15, "Error in sum function");
	
	printf("All tests passed");
	return 0;
}
