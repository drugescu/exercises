#include <stdio.h>

void func1(int var) {
	static int foo;
	printf("%d\n", foo);
	foo = var;
}

void main() {
	func1(1);
	func1(2);
	func1(3);
	func1(1);
	func1(1);
}