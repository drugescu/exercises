/* 1*2*3*4*17*18*19*20
  5*6*7* 14*15*16
    8*9*12*13
      10*11 */

#include <stdio.h>

void main() {
	int i,j, k = 1, l = 20;

	for (j = 0; j < 4; j++)	{
		for(i = k; i < k + 4 - j; i++) {
			printf("%d*", i);
		}

		k = i;

		for(i = l - (4 - j) + 1; i < l; i++) {
			printf("%d*", i);
		}
		printf("%d", i);

		l = l - (4 - j);

		printf("\n");
	}
}