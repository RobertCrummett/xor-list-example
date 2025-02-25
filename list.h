#ifndef LIST_H
#define LIST_H

typedef struct list_t *list_t;
struct list_t {
	list_t ptr;
	int data;
};

extern list_t list_append(list_t prev, list_t curr, int value);
extern void list_step(list_t *prev, list_t *curr);

#endif
