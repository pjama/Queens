#include <stdio.h>
#include "linked_list.h"
#include "constants.h"

void printBoard(unsigned long board) {
	int i,j;
	for (i=0; i<SIZE; i++) {
		for (j=0; j<SIZE; j++) {
			int cellVal = (board >> (i*SIZE + j)) & 1;
			printf("%d ", cellVal);
		}
		printf("\n");
	}
	printf("\n");
}

void print_linked_list(struct Node* root) {
	printf("--- Linked List Start ---\n");
	int counter = 0;
	struct Node* curr = root;
	while (curr != NULL) {
		printf("\n--(%d)--\n", counter++);
		printBoard(curr->val);
		curr = curr->next;
	}
	printf("--- Linked List End ---\n");
}
