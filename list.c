#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "list.h"

void list_swap(list_t *a, list_t *b) {
	list_t t = *a;
	*a = *b;
	*b = t;
}

list_t list_xor(list_t a, list_t b) {
	return (list_t)((uintptr_t)a ^ (uintptr_t)b);
}

list_t list_append(list_t prev, list_t curr, int value) {
	list_t next;
	next = malloc(sizeof(*next));
	if (next == NULL) {
		fprintf(stderr, "[ERROR]: list_append: failed to allocate list node\n");
		return NULL;
	}

	next->data = value;
	next->ptr = list_xor(curr, next);

	if (curr) curr->ptr = list_xor(prev, next);
	return next;
}

void list_step(list_t *prev, list_t *curr) {
	list_t temp = list_xor(*prev, (*curr)->ptr);
	*prev = *curr;
	*curr = temp;
}

// list_t list_step(list_t prev, list_t curr) {
// 	return list_xor(prev, curr->ptr);
// }
