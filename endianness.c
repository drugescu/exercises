#include <stdio.h>

void main() {
	char foo[8] = {1, 0, 2, 0, 3, 0, 4, 0};
	short int* bar = &foo;
	long int *derp = &foo;
	int i;

	for (i = 0; i < 8; i++) {
		printf("0x%x\n", foo[i]);
	}

	printf("\n");

	for (i = 0; i < 4; i++) {
		printf("0x%x\n", bar[i]);
	}

	printf("\n");

	for (i = 0; i < 2; i++) {
		printf("0x%lx\n", derp[i]);
	}
}