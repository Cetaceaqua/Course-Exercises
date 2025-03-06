#include <stdio.h>

int test(int condition, char* message) {
	if (!condition) {
		printf("Error: %s\n", message);
		return 1; 
	}
	return 0;
}

int delete_from_array(int arr[], int size, int pos) {
	if (pos < 0 || pos >= size) {
		return 0;
	}
	
	for (int i = pos; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	
	return 1;
}

int main() {
	int arr[] = {6, 8, 9, -3, -5, 4, 3}; 
	test(delete_from_array(arr, 7, 2) == 1 && arr[0] == 6 && arr[1] == 8 && arr[2] == -3 && arr[3] == -5 && arr[4] == 4 && arr[5] == 3, "Error in test 1"); 
	
	int arr2[] = {6, 8, 9, -3, -5, 4, 3}; 
	test(delete_from_array(arr2, 7, 0) == 1 && arr2[0] == 8 && arr2[1] == 9 && arr2[2] == -3 && arr2[3] == -5 && arr2[4] == 4 && arr2[5] == 3, "Error in test 2"); 
	
	int arr3[] = {6, 8, 9, -3, -5, 4, 3}; 
	test(delete_from_array(arr3, 7, 6) == 1 && arr3[0] == 6 && arr3[1] == 8 && arr3[2] == 9 && arr3[3] == -3 && arr3[4] == -5 && arr3[5] == 4, "Error in test 3"); 
	
	int arr4[] = {6, 8, 9, -3, -5, 4, 3}; 
	test(delete_from_array(arr4, 7, 7) == 0, "Error in test 4"); 
	
	int arr5[] = {6, 8, 9, -3, -5, 4, 3}; 
	test(delete_from_array(arr5, 7, -1) == 0, "Error in test 5"); 

	printf("All tests passed");
	return 0;
}
