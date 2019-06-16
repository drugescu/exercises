#include <stdio.h>

void main() {
	int a = 0x05;
	if (a & 0xF0 > 3) { printf("true\n"); }
	else { printf("false\n"); }
	if ((a & 0xF0) > 3) { printf("true\n"); }
	else { printf("false\n"); }
	if (a & (0xF0 > 3)) { printf("true\n"); }
	else { printf("false\n"); }
}