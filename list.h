#ifndef XOR_LIST_H
#define XOR_LIST_H

typedef struct list_t list_t;
struct list_t {
	list_t *ptr;
	int data;
};

extern void list_append(list_t **prev, list_t **curr, int value);
extern void list_step(list_t **prev, list_t **curr);

extern void list_free(list_t **head);

#endif
