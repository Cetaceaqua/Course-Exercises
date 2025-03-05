#include <stdio.h>

int test(int condition, char* message) {
	if(!condition) {
		printf("Error: %s\n", message);
		return 1;
	}
	return 0;
}

int is_even(int num) {
	return (num % 2 == 0) ? 1 : 0;
}

int is_positive(int num) {
	if(num < 0) {
		return -1;
	} else if (num == 0) {
		return 0;
	} else {
		return 1;
	}
}

int is_multiple_of_five(int num) {
	return (num % 5 == 0) ? 1 : 0;
}

int main() {
	test(is_even(5) == 0, "Error in test is_even(5)"); 
	test(is_even(42) == 1, "Error in test is_even(42)"); 
	test(is_even(0) == 1, "Error in test is_even(0)"); 
	test(is_even(-3) == 0, "Error in test is_even(-3)"); 
	test(is_positive(42) == 1, "Error in test is_positive (42)"); 
	test(is_positive(0) == 0, "Error in test is_positive (0)"); 
	test(is_positive(-429090) == -1, "Error in test is_positive (-429090)"); 
	test(is_multiple_of_five(25) == 1, "Error in test is_multiple_of_five (25)"); 
	test(is_multiple_of_five(26) == 0, "Error in test is_multiple_of_five (26)"); 
	test(is_multiple_of_five(-105) == 1, "Error in test is_multiple_of_five (105)");
	printf("All tests passed");
	return 0;
}
