#include <assert.h>
#include <stdio.h>

#include "list.h"

void list_info(list_t *prev, list_t *curr) {
	printf("%p, %p\n", prev, curr);
	printf("data: %d, ptr: %p\n", prev->data, prev->ptr);
	printf("data: %d, ptr: %p\n", curr->data, curr->ptr);
}

int main(void) {
	int i, L = 0, N = 10;
	list_t *head, *prev, *curr;

	head = prev = curr = NULL;
	for (i = 0; i < N; i++) {
		list_append(&prev, &curr, i);
		if (i == 0) head = curr;
		list_info(prev, curr);
	}
	printf("\n");
	prev = curr = head;
	do {
		list_info(prev, curr);
		list_step(&prev, &curr);
	} while (prev != curr && ++L < N);
	assert(L != N && "This should not happen!\n");

	return 0;
}
