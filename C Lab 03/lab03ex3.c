#include <stdio.h>
#include <ctype.h>

int test(int condition, char* message) {
	if(!condition) {
		printf("Error: %s\n", message);
		return 1;
	}
	return 0;
}

int count_vowels(const char str[]) {
	int count = 0;
	int length = 0;
	while (str[length] != '\0') {
		length++;
		char character = tolower(str[length]);
		if(character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u') {
			count++;
		}
		if(length > 10) {
			return -999;
		}
	}
	return count;
} 

int main() { 
	test(count_vowels("hello") == 2, "Error in test count_vowels(\"hello\")");
	test(count_vowels("HELLO") == 2, "Error in test count_vowels(\"HELLO\")");
	test(count_vowels(" ") == 0, "Error in test count_vowels(\" \")");
	test(count_vowels("H E L L O") == 2, "Error in test count_vowels(\"H E L L O\")"); 
	
	printf("All tests passed"); 
	return 0; 
} 
