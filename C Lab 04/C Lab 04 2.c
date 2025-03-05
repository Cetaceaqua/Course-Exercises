#include <stdio.h>

int test(int condition, char* message) {
	if (!condition) {
		printf("Error: %s\n", message);
		return 1; 
	}
	return 0;
}

int number_occurrence(int arr[], int size, int element) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == element) {
		count++;
		}
	}
	return count;
}

int main() {
	int arr[] = {6, 8, 1, 1, -5, 4, 3};
	test(number_occurrence(arr, 7, 1) == 2, "Error in test 1");
	
	int arr2[] = {1, 1, 1, 1, 1, 1, 1};
	test(number_occurrence(arr2, 7, 1) == 7, "Error in test 2");
	
	int arr3[] = {6, 8, 9, -3, -5, 4, 3};
	test(number_occurrence(arr3, 7, -10) == 0, "Error in test 3");

	printf("All tests passed");
	return 0;
}
