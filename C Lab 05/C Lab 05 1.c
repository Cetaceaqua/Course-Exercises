#include <stdio.h>

int test(int condition, char* message) { 
	if (!condition) { 
		printf("Error: %s\n", message); 
		return 1; 
	} 
	return 0; 
} 

void reverse(char arr[], int size) {
	int left = 0;
	int right = size - 1;
	while (left < right) {
		char temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}
}

int main() {
	char arr[] = {'a', 'b', 'c', 'd'};
	reverse(arr, 4);
	test(arr[0] == 'd' && arr[1] == 'c' && arr[2] == 'b' && arr[3] == 'a', "Error in test 1");
	
	char arr2[] = {'z'};
	reverse(arr2, 1);
	test(arr2[0] == 'z', "Error in test 2");
	
	printf("All tests passed");
	return 0;
} 
