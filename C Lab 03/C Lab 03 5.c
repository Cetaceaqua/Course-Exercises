#include <stdio.h>

int print_pattern(int max) {
	if(!(max > 0 && max < 26)) {
		return 1;
	}
	for(int i = 1; i < max; i++) {
		for(int j = 1; j <= i; j++) {
			printf("A");
		}
		printf("\n");
	}
	for(int i = max; i > 0; i--) {
		for(int j = 1; j <= i; j++) {
			printf("A");
		}
		printf("\n");
	}
	return 0;
}


int main() {
	print_pattern(10);
}
