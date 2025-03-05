#include <stdio.h>

int test(int condition, char* message) {
	if(!condition) {
		printf("Error: %s\n", message);
		return 1;
	}
	return 0;
}

int string_length(const char str[]) {
	int length = 0;
	while (str[length] != '\0') {
		length++;
		
		if(length > 10) {
			return -999;
		}
	}
	return length;
} 

int main() { 
	test(string_length("hello") == 5, "Error in test string_length(\"hello\")"); 
	test(string_length("") == 0, "Error in test string_length(\"\")");
	test(string_length("h e l l o\n") == 10, "Error in test string_length(\"h e l l o\n \")"); 
	test(string_length("this string is too long") == -999, "Error in test string_length(\"this string is too long \")"); 
	
	printf("All tests passed"); 
	return 0; 
} 
