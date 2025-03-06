#include <stdio.h>

int test(int condition, char* message) {
	if (!condition) {
		printf("Error: %s\n", message);
		return 1; 
	}
	return 0;
}

int find_largest(int arr[], int size) {
	if (size <= 0) {
		return -1;
	}
	
	int max_value = arr[0];
	
	for (int i = 1; i < size; i++) {
		if (arr[i] > max_value) {
			max_value = arr[i];
		}
	}
	
	for (int i = 0; i < size; i++) {
		arr[i] = max_value;
	}
	
	return max_value;
}

int main() {
	int arr[] = {6, 8, 1, 1, -5, 4, 3};
	test(find_largest(arr, 7) == 8 && arr[0] == 8 && arr[6] == 8, "Error in test 1");
	
	int arr2[] = {10, 20, 30, 5, 2};
	test(find_largest(arr2, 5) == 30 && arr2[0] == 30 && arr2[4] == 30, "Error in test 2");

	printf("All tests passed");
	return 0;
}
