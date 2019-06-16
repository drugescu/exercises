#include <stdio.h>

void func1() { printf("1\n"); }

void func2() { printf("2\n"); }

void CallFuncNumTimes(void (*function)(), int num) {
	int cnt;
	for (cnt = 0; cnt < num; cnt++) {
		(*function) ();
	}
}

int main() {
	CallFuncNumTimes(func1, 5);
	CallFuncNumTimes(func2, 5);

	return 0;
}