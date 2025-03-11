#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "list.h"

/*
 * Internal function to xor list_t pointers
 */
static list_t* list_xor(list_t *a, list_t *b) {
	return (list_t *)((uintptr_t)a ^ (uintptr_t)b);
}

void list_append(list_t **prev, list_t **curr, int value) {
	/*
	 * `prev` and `curr` should point to the two list
	 * nodes preceeding the node to be inserted.
	 */
	if (prev == NULL || curr == NULL) {
		fprintf(stderr, "[ERROR]: list_append: prev and curr must not be NULL\n");
		return;
	}

	list_t *next = malloc(sizeof(*next));
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

/*
 * For the general iteration step, the xor list 
 * should look something like this:
 *
 *    ... --- b --- c --- d --- ...
 *            ^     ^ 
 *          prev  curr
 *
 * Let b be the previous node and c the current node.
 *
 * The pointer to the next node d is
 * computed by xor-ing b and the pointer
 * held by C, which equals b ^ d.
 *
 * By the invariant property of the xor
 * operation,
 *
 *            b ^ (b ^ d) = d
 *
 * The previous pointer is discarded and set
 * equal to the value of the current pointer.
 * The current pointer `curr` is set equal to d.
 *
 * There are two edge cases:
 * 1. The first iteration
 * 2. The final iteration
 *
 * The first iteration is initiated by passing
 * the head node in as `prev` and `curr`
 * simulaneously. This effectively bootstraps
 * `prev` and `curr` to continue iterating.
 * After the first iteration, `prev` still
 * points to the head but `curr` points to
 * the next node.
 *
 * The final iteration occurs when the
 * returned values of `prev` and `curr`
 * are the same, or that `curr` will point
 * to the same node two iteration in a row.
 *
 * Like the first node, the final node will
 * be self referential:
 *
 *             	... --- e --- f
 *             	        ^     ^
 *             	      prev  curr
 *
 * The xor'ed value stored at the final node
 * `f` will be (e^f). Thus, when the previous
 * node is the second to last node e and 
 * the current node is at f, by the invariant
 * property of the xor operator,
 *
 *              e ^ (e ^ f) = f
 *
 * Rather than jumping to the next node, we
 * jump to ourselves. So this self jump must
 * be tested for at each iteration.
 *
 * If the last iteration is not checked for,
 * the iteration will not crash --- in fact,
 * it will continue forever! After the last
 * iteration, step will continue iterating
 * through the list *backwards*. Boomeranging
 * like this will continue ad infinitum.
 * 
 * A final note: NULL need not be checked for.
 * By another invarient property of the xor
 * operator,
 *
 *               NULL ^ a = a
 */
void list_step(list_t **prev, list_t **curr) {
	list_t *t = list_xor(*prev, (*curr)->ptr);
	*prev = *curr;
	*curr = t;
}

void list_free(list_t **head) {
	/*
	 * If head does not point at anything meaningful,
	 * neither should we.
	 */
	if (head == NULL || *head == NULL)
		return;

	/*
	 * The pointers:
	 * t is for temporary
	 * p is for previous
	 * c is for current
	 */
	list_t *t = NULL, *p = NULL, *c = NULL;
	/*
	 * Now if both p and c point to the head,
	 * iteration is bootstrapped by passing
	 * the head twice to list_step
	 */
	p = c = *head;
	list_step(&p, &c);

	/* For lists of size one (i.e., one list node) */
	if (p == c)
		goto LIST_FREE_CLEANUP;

	/* For lists of size greater than or equal to two */
	do {
		t = p;
		list_step(&p, &c);
		free(t);
		/*
		 * Once the previous and current
		 * list node pointers point at the same
		 * location in memory, we have finished iteration.
		 *
		 * In other words, only a single node remains
		 * (the final node). So we should goto the
		 * final cleanup section.
		 */
	} while (p != c);

LIST_FREE_CLEANUP:
	free(p);
	*head = NULL;
}
