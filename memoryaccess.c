#include <stdio.h>

typedef struct {
	char foo;
	char bar;
} new_type;

typedef struct 
{
	char my_str[3];
	new_type dat;
} other_type;

void f1(void *in);

void main() {
	other_type stuff = {'a', 'b', 'c', {1,2}};

	f1((void *) &stuff);
}

void f1(void *in) {
	new_type *other_stuff = (new_type *) (in + 3);

	printf("%d %d\n", other_stuff->foo, other_stuff->bar);
}