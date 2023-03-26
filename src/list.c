#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

List *list_create(void)
{
	List *list = malloc(sizeof(List));

	list->id_counter = 1;
	list->head = NULL;
	list->marked_for_removal = malloc(sizeof(Node **));
	list->marked_size = 1;
	list->marked_iterator = 0;

	return list;
}

Node *list_get(List *list, void *data)
{
	Node *temp;
	for (temp = list->head; temp->data != data; temp = temp->next);

	return temp;
}

Node *list_add(List *list, void *data, size_t size)
{
	if (list->head == NULL) {
		Node *head = list->head;

		head = malloc(sizeof(Node));
		head->data = data;
		head->id = list->id_counter++;
		head->next = NULL;

		list->head = head;
		
		return head;
	}

	Node *temp;
	for (temp = list->head; temp->next != NULL; temp = temp->next);

	temp->next = malloc(sizeof(Node));
	temp = temp->next;
	temp->data = data;
	temp->id = list->id_counter++;
	temp->next = NULL;

	return temp;
}

void list_remove(List *list, void *data)
{
	if (list->head == NULL)
		return;

	if (list->head->data == data) {
		Node *temp = list->head->next;

		free(list->head->data);
		free(list->head);

		list->head = temp;

		return;
	}

	Node *current;
	for (current = list->head; current->next->data != data; current = current->next) {
		if (current->next->next == NULL)
			return;
	}

	Node *temp = current->next;
	current->next = current->next->next;
	free(temp->data);
	free(temp);
}

void list_mark_for_removal(List *list, Node *node)
{
	Node **marked = list->marked_for_removal;

	if (list->marked_iterator + 1 == list->marked_size)
		marked = realloc(marked, (list->marked_size *= 2) * sizeof(Node **));

	marked[list->marked_iterator++] = node;

	list->marked_for_removal = marked;
}

void list_remove_marked(List *list)
{
	if (list->marked_iterator == 0)
		return;

	for (uint32_t i = 0; i < list->marked_iterator; ++i)
		list_remove(list, list->marked_for_removal[i]->data);
	list->marked_iterator = 0;
}

void list_free(List *list)
{
	Node *head = list->head;
	Node *prev = NULL;

	while (head != NULL) {
		prev = head;
		head = head->next;
		free(prev->data);
		free(prev);
	}

	list->head = head;
	
	free(list->marked_for_removal);
	free(list);
}

void list_print(List *list)
{
	Node *temp;
	for (temp = list->head; temp != NULL; temp = temp->next)
		printf("%d | ", temp->id);

	printf("\n");
}
