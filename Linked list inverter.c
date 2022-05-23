/*
Write a function that gets a poiner 'head', to a one way linked list
and converts the order of pointers in the list.
The function will return a pointer to the head of the list,
which was the last node in the input list.
NOTE: the function should not create any new nodes, update data or free nodes from given list
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef struct item {
	int data;
	struct item* next;
}Item;

Item* Create_list() {
	Item* Ist, * curr_point;
	int x, i = 1;
	printf("Enter Natural number [0]: ");
	scanf("%d", &x);
	if (x <= 0) return;
	Ist = (Item*)malloc(sizeof(Item));
	curr_point = Ist;
	Ist->data = x;
	printf("Enter Natural number [%d]: ", i);
	scanf("%d", &x);
	while (x > 0) {
		i++;
		curr_point->next = (Item*)malloc(sizeof(Item));
		curr_point = curr_point->next;
		curr_point->data = x;
		printf("Enter Natural number [%d]: ", i);
		scanf("%d", &x);
	}
	curr_point->next = NULL;
	return Ist;
}

Item* reverse(Item* head) {
	Item* next, * prev, * current;
	current = head;
	prev = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}

void print_list(Item* head) {
	while (head) {
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

void main() {
	Item* Ist, * Snd;
	Ist = Create_list();
	print_list(Ist);
	Snd = reverse(Ist);
	print_list(Snd);
}
