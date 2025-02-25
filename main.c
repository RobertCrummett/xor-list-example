#include <stdio.h>

#include "list.h"

int main(void) {
	list_t head, prev, curr, next;

	head = next = list_append(NULL, NULL, 1);
	printf("%p\n", next);
	printf("data: %d, ptr: %p\n", next->data, next->ptr);
	prev = head;
	curr = next;
	next = list_append(prev, curr, 2);
	printf("%p\n", next);
	printf("data: %d, ptr: %p\n", next->data, next->ptr);
	prev = curr;
	curr = next;
	next = list_append(prev, curr, 3);
	printf("%p\n", next);
	printf("data: %d, ptr: %p\n", next->data, next->ptr);
	prev = curr;
	curr = next;
	next = list_append(prev, curr, 4);
	printf("%p\n", next);
	printf("data: %d, ptr: %p\n", next->data, next->ptr);
	prev = curr;
	curr = next;
	next = list_append(prev, curr, 5);
	printf("%p\n", next);
	printf("data: %d, ptr: %p\n", next->data, next->ptr);
	prev = curr;
	curr = next;
	next = list_append(prev, curr, 6);
	printf("%p\n", next);
	printf("data: %d, ptr: %p\n", next->data, next->ptr);

	printf("\n");
	printf("%p\n", head);
	printf("data: %d, ptr: %p\n", head->data, head->ptr);
	prev = curr = head;
	list_step(&prev, &curr);
	printf("%p\n", next);
	printf("data: %d, ptr: %p\n", curr->data, curr->ptr);
	list_step(&prev, &curr);
	printf("%p\n", next);
	printf("data: %d, ptr: %p\n", curr->data, curr->ptr);
	list_step(&prev, &curr);
	printf("%p\n", next);
	printf("data: %d, ptr: %p\n", curr->data, curr->ptr);
	list_step(&prev, &curr);
	printf("%p\n", next);
	printf("data: %d, ptr: %p\n", curr->data, curr->ptr);
	list_step(&prev, &curr);
	printf("%p\n", next);
	printf("data: %d, ptr: %p\n", curr->data, curr->ptr);
	list_step(&prev, &curr);
	printf("%p\n", next);
	printf("data: %d, ptr: %p\n", curr->data, curr->ptr);
	if (next == curr) printf("done\n");

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
	next = list_step(&prev, &curr);
	if (next == curr) {
		fprintf(stderr, "unexpected end of list!\n");
		return 1;
	}
	prev = curr;
	curr = next;
	printf("data: %d, ptr: %p\n", curr->data, curr->ptr);
	next = list_step(&prev, &curr);
	if (next == curr) {
		fprintf(stderr, "unexpected end of list!\n");
		return 1;
	}
	prev = curr;
	curr = next;
	printf("data: %d, ptr: %p\n", curr->data, curr->ptr);
	next = list_step(&prev, &curr);
	if (next == curr) {
		fprintf(stderr, "unexpected end of list!\n");
		return 1;
	}
	prev = curr;
	curr = next;
	printf("data: %d, ptr: %p\n", curr->data, curr->ptr);
	next = list_step(&prev, &curr);
	if (next != curr) {
		fprintf(stderr, "expected end of list\n");
		return 1;
	}
	*/
	return 0;
}
