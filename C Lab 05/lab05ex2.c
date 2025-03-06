#include <stdio.h>
#include <string.h>

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

void reverse_sentence(char sentence[]) {
	int len = strlen(sentence);
	int start = 0;
	for (int i = 0; i <= len; i++) {
		if (sentence[i] == ' ' || sentence[i] == '\0') {
			reverse(sentence + start, i - start);
			/*
				"sentence + start" is equivalent to "&sentence[start]",
				since an array name acts as a pointer to its first element.
			*/
			start = i + 1;
		}
	}
}

int main() {
	char sentence[] = "The quick brown fox jumped over the lazy dogs"; 
	reverse_sentence(sentence); 
	test(!strcmp(sentence, "ehT kciuq nworb xof depmuj revo eht yzal sgod"), "Error in reverse_sentence");
	
	printf("All tests passed");
	return 0;
}
