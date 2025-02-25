#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct list_t *list_t;
struct list_t {
	list_t ptr;
	int data;
};

list_t list_xor(list_t a, list_t b) {
	return (list_t)((uintptr_t)a ^ (uintptr_t)b);
}

list_t list_node(list_t prev, list_t curr, int value) {
	list_t next;
	next = malloc(sizeof(*next));

	next->data = value;
	next->ptr  = curr;
	
	if (curr == NULL)
		;
	else if (prev == NULL) {
		curr->ptr = next;
		next->ptr = curr;
	} else
		curr->ptr = list_xor(prev, next);

	return next;
}

int main(void) {
	printf("Hello world\n");

	list_t head = list_node(NULL, NULL, 1);
	list_t tail = list_node(NULL, head, 2);
	list_t next = list_node(head, tail, 3);

	printf("head data: %d\n", head->data);
	printf("head ptr:  %p\n", head->ptr);
	printf("next data: %d\n", head->ptr->data);
	printf("next ptr:  %p\n", head->ptr->ptr);

	// int *a, *b, *n = NULL;
	// printf("a = %p\n", a);
	// printf("b = %p\n\n", b);
	// printf("b = %p,    a ^ b ^ a = %p\n", b, xord(xord(a, b), a));
	// printf("a = %p,    a ^ 0 = %p\n", a, xord(a, n));
	// printf("a = %p,    a ^ a = %p\n", a, xord(a, a));
	// printf("a ^ b = %p, b ^ a = %p\n", xord(a, b), xord(b, a));
	return 0;
}
