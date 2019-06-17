#include <stdio.h>

/*

 			2   8   5   3   7   1   6   4
split 1		2   8   5   3 | 7   1   6   4
split 2		2   8 | 5   3 | 7   1 | 6   4
sort		K   K |   X   |   X   |   X
			2   8 | 3   5 | 1   7 | 4   6
merge 1 	2   3   5   8 | 1   4   6   7
merge 2		1   2   3   4   5   6   7   8

output 		1   2   3   4   5   6   7   8

*/

#define 	MAX_SIZE		8

/* Function to print an array */
void printArray(int A[], int startCount, int size) 
{ 
    int i; 
    for (i = startCount; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
}

void merge(int a[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];

	/* merge temp arrays */
	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}

	/* copy remaining elements if L size != R size */
	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		a[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(int a[], int l, int r) {
	int m;
	if (r > l) {
		m = (l + r) / 2;
		printf("Step: \n  " );
		printArray(a, l, m + 1);
		printf("  " );
		printArray(a, m + 1, r + 1);
		
		merge_sort(a, l, m);
		merge_sort(a, m + 1, r);
		merge(a, l, m, r);

		printf("Merged: ");
		printArray(a, l, r + 1);
	}
}

void main() {
	int a[MAX_SIZE] = {2, 8, 5, 3, 7, 1, 6, 4};

	printf("Given array is: ");
	printArray(a, 0, MAX_SIZE);

	merge_sort(a, 0, MAX_SIZE - 1);

	printf("Sorted array is: ");
	printArray(a, 0, MAX_SIZE);
}