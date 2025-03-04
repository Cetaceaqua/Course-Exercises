#include <stdio.h>

int test(int condition, char* message) {
	if (!condition) {
		printf("Error: %s\n", message);
		return 1; 
	}
	return 0;
}

int first_occurrence(int arr[], int size, int element) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == element) {
			return i;
		}
	}
	return -1;
}

int main() {
	int arr[] = {6, 8, 1, 1, -5, 4, 3};
	test(first_occurrence(arr, 7, 1) == 2, "Error in test 1");

	int arr2[] = {6, 8, 9, -3, -5, 4, 3};
	test(first_occurrence(arr2, 7, 3) == 6, "Error in test 2");

	int arr3[] = {6, 8, 9, -3, -5, 4, 3};
	test(first_occurrence(arr3, 7, -10) == -1, "Error in test 3");

	int arr4[] = {6, 8, 9, -3, -5, 4, 3};
	test(first_occurrence(arr4, 7, 6) == 0, "Error in test 4");

	printf("All tests passed");
	return 0;
}
