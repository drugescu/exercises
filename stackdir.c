#include <stdio.h>

void fun(int* main_local_addr) {
	int local;
	if (main_local_addr < &local)
		printf("Upward increase: %p < %p\n", main_local_addr, &local);
	else
		printf("Downward increase: %p > %p\n", main_local_addr, &local);
}

void main() {

	int main_local;
	fun(&main_local);
}