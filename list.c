#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "list.h"

list_t* list_xor(list_t *a, list_t *b) {
	return (list_t *)((uintptr_t)a ^ (uintptr_t)b);
}

void list_append(list_t **prev, list_t **curr, int value) {
	list_t *next;

	if (prev == NULL || curr == NULL) {
		fprintf(stderr, "[ERROR]: list_append: prev and curr must not be NULL\n");
		return;
	}

	next = malloc(sizeof(*next));
	if (next == NULL) {
		fprintf(stderr, "[ERROR]: list_append: failed to allocate list node\n");
		return;
	}

	next->data = value;
	next->ptr = list_xor(*curr, next);

	if (*curr == NULL && *prev == NULL)
		*prev = next;
	else {
		(*curr)->ptr = list_xor(*prev, next);
		*prev = *curr;
	}
	*curr = next;
}

void list_step(list_t **prev, list_t **curr) {
	list_t *t = list_xor(*prev, (*curr)->ptr);
	*prev = *curr;
	*curr = t;
}
