#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct list {
	int current;
	struct list* next;
};

typedef struct list list_t;

void insert_begin(list_t** l, int n) {
	printf("Adding element %d to list.\n", n);

	if ((*l) == NULL) {
		printf("List NULL. Malloccing first.\n");
		*l = malloc(sizeof(list_t));
        assert((*l) != NULL);

		(*l)->current = n;
		(*l)->next = NULL;
		printf("Made current %d.\n", (*l)->current);
	}
	else {
		list_t* new = malloc(sizeof(list_t));
		new->current = n;
		new->next = *l;
		*l = new;
	}
};

void insert_end(list_t** l, int n) {
	printf("Adding element %d at end of list.\n", n);

	if ((*l) == NULL) {
		printf("List NULL. Malloccing first.\n");
		*l = malloc(sizeof(list_t));
        assert((*l) != NULL);

		(*l)->current = n;
		(*l)->next = NULL;
		printf("Made current %d.\n", (*l)->current);
	}
	else {
		/* iterate through nodes till the end and add it there */
		list_t* new = malloc(sizeof(list_t));
		new->current = n;
		list_t* current = *l;

		while (current->next != NULL) {
			current = current->next;
		}

		current->next = new;
	}
}

void delete(list_t** l, int n) {
	list_t* p = *l;
	list_t* prev = NULL;

	while ((p->next != NULL) && (p->current != n)) {
		prev = p;
		p = p->next;
	}

	if (p->current == n) {
		/* three cases, beginning , middle and end */
		if ((prev != NULL) && (p->next != NULL)) {
			prev->next = p->next;
			free(p);
			return;
		}
		if (prev == NULL) {
			/* at beginning, just delete node */
			(*l) = p->next;
			free(p);
			return;
		}
		if (p->next == NULL) {
			prev->next = NULL;
			free(p);
			return;
		}
	}
}

void delete_list(list_t** l) {

	list_t* p = *l;
	list_t* next;

	while(p != NULL) {
		next = p->next;
		free(p);
		p = next;
	}

	*l = NULL;
}

void merge(list_t** l, int left, int mid, int right) {

	int margin1 = mid - left + 1;
	int margin2 = right - mid;

	list_t* temp = *l;
	list_t* temp2 = *l;

	int i, j, k;

	int L[margin1];
	int R[margin2];

	printf("\n\n");

	for (i = 0; i < left; i++)
		temp = temp->next;
	for (i = 0; i < margin1; i++) {
		L[i] = temp->current; // a[l+i]
		printf("L(%d)=%d,", i, L[i]);
		temp = temp->next;
	}

	temp = *l;
	for (j = 0; j <= mid; j++)
		temp2 = temp2->next;
	for (j = 0; j < margin2; j++) {
		R[j] = temp2->current;// a[m+1+j]
		printf("R(%d)=%d,", j, R[j]);
		temp2 = temp2->next;
	}

	i = 0;
	j = 0;
	k = left;

	temp = *l;
	for (j = 0; j < left; j++)
		temp = temp->next;
	printf("\nstarting from temp = %d\nL[i]=", temp->current);
	for (i = 0; i < margin1; i++) {
		printf("%d ", L[i]);
	}
	printf("\nR[i]=");
	for (j = 0; j < margin2; j++) {
		printf("%d ", R[j]);
	}

	while ((i < margin1) && (j < margin2)) {
		if (L[i] <= R[j]) {
			temp->current = L[i];
			i++;
		}
		else {
			temp->current = R[j];
			j++;
		}
		temp = temp->next; // k++

	}

	printf("done to here \n");

	/* copy remaining elements if L size != R size */
	while (i < margin1)
	{
		temp->current = L[i];
		i++;
		temp = temp->next; // k++
	}
	while (j < margin2) {
		temp->current = R[j];
		j++;
		temp = temp->next; // k++
	}

}

void merge_sort(list_t** l, int left, int right) {
	if (right > left) {
		int mid = (left + right) / 2;

		merge_sort(l, left, mid);
		merge_sort(l, mid + 1, right);

		merge(l, left, mid, right);
	}
}

int list_size(list_t* l) {
	int count = 0;

	while ((l != NULL)) {
		count++;
		l = l->next;
	}

	return count;
}

void sort_list(list_t** l) {
	int size = list_size(*l);
	printf("List size is: %d\n", size);
	merge_sort(l, 0, size - 1);
}

/* prints copy of list */
void printList(list_t* l) {

	printf("List is: ( ");

	while (l != NULL) {
		printf("%d ", l->current);
		l = l->next;
	}

	printf(")\n");
}

void main() {
	/* Build simple linked list */
	/* Reverse linked list */
	/* Detect loop linked list */
	/* Add, delete elements from list */
	list_t* nlist = NULL;

	printList(nlist);

	insert_begin(&nlist, 1);
	insert_begin(&nlist, 2);
	insert_begin(&nlist, 3);
	insert_begin(&nlist, 5);

	/* should show 5,3,2,1*/
	printList(nlist);

	insert_end(&nlist, 10);
	insert_end(&nlist, 20);
	insert_end(&nlist, 30);

	/* should show 5,3,2,1,10,20,30 */
	printList(nlist);

	delete(&nlist, 20);

	/* should show 5,3,2,1,10,30 */
	printList(nlist);

	delete(&nlist, 30);

	/* should show 5,3,2,1,10 */
	printList(nlist);

	delete(&nlist, 5);

	/* should show 3,2,1,10 */
	printList(nlist);

	insert_begin(&nlist, 5);
	insert_begin(&nlist, 20);
	insert_begin(&nlist, 30);

	/* should show 30,20,5,3,2,1,10 */
	printList(nlist);

	printf("List size is: %d\n", list_size(nlist));
	sort_list(&nlist);

	/* should show 1,2,3,5,10,20,30 */
	printList(nlist);

	delete_list(&nlist);

	printf("Deleted list.\n");
	printList(nlist);
}