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

void main()
{
	struct a alpha;
	union b beta;	

	printf("sizeof(alpha) = %lu\n", sizeof(alpha));
	printf("sizeof(beta) = %lu\n", sizeof(beta));
}