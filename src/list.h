#ifndef LIST_H
#define LIST_H

#include <stdint.h>
#include <stddef.h>

typedef struct node {
	uint32_t id;

	void *data;

	struct node *next;
} Node;

typedef struct {
	Node *head;

	uint32_t id_counter;

	Node **marked_for_removal;
	size_t marked_size;
	uint32_t marked_iterator;
} List;

List *list_create(void);

Node *list_get(List *list, void *data);
Node *list_add(List *list, void *data, size_t size);
void  list_remove(List *list, void *data);

void list_mark_for_removal(List *list, Node *node);
void list_remove_marked(List *list);

void list_free(List *list);

void list_print(List *list);

#endif // LIST_H
