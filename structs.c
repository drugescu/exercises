#include <stdio.h>


struct a {
	int a;     /* 4 */
	short b;   /* 2 */
	char d;    /* 1 */
	char k;    /* 1 */
	char z[3]; /* 3 */
	/* padding 1 */
};

union b {
	int a;
	short b;
	char d;
	char k;
	char z[5];
	/* biggest size z (5) */
	/* padded to 8 with additional 3 */
};

struct c {
	int a : 16; /* 16 bits - 2 bytes */
	int d : 17; /* 17 bits - 2 bytes + 1 bit total */
	/* padding to multiple of 4 bytes */
	/* if d is 16 bits, sizeof(c) is 4, if d is 17, sizeof(c) is 8*/
};

void main()
{
	struct a alpha;
	union b beta;	
	struct c charlie;

	printf("sizeof(alpha) = %lu\n", sizeof(alpha));
	printf("sizeof(beta) = %lu\n", sizeof(beta));
	printf("sizeof(charlie) = %lu\n", sizeof(charlie));
}