#include <stdio.h>

#include "list.h"

int main(void) {
	// list_t head, prev, curr, next;
	list_t prev = {0};
	list_t curr = {0};
	// Node 1
	list_append(&prev, &curr, 1);
	printf("%p\n", curr);
	list_append(&prev, &curr, 2);

	/*
	// Node 1
	head = prev = curr = list_append(NULL, NULL, 1);
	// Node 2
	curr = list_append(prev, curr, 2);
	// Node 3
	next = list_append(prev, curr, 3);
	// Node 4
	prev = curr;
	curr = next;
	next = list_append(prev, curr, 4);
	*/


	/*
	prev = curr = head;
	printf("data: %d, ptr: %p\n", curr->data, curr->ptr);
	next = list_step(prev, curr);
	if (next == curr) {
		fprintf(stderr, "unexpected end of list!\n");
		return 1;
	}
	prev = curr;
	curr = next;
	printf("data: %d, ptr: %p\n", curr->data, curr->ptr);
	next = list_step(prev, curr);
	if (next == curr) {
		fprintf(stderr, "unexpected end of list!\n");
		return 1;
	}
	prev = curr;
	curr = next;
	printf("data: %d, ptr: %p\n", curr->data, curr->ptr);
	next = list_step(prev, curr);
	if (next == curr) {
		fprintf(stderr, "unexpected end of list!\n");
		return 1;
	}
	prev = curr;
	curr = next;
	printf("data: %d, ptr: %p\n", curr->data, curr->ptr);
	next = list_step(prev, curr);
	if (next != curr) {
		fprintf(stderr, "expected end of list\n");
		return 1;
	}
	*/
	return 0;
}
