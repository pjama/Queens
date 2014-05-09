#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct Node* add_to_list(struct Node* root, unsigned long val) {
    if (root == NULL) {
    	root = malloc( sizeof(struct Node) );
    	root->next = NULL;
    	root->val = val;
    	return root;
    }
	struct Node* curr = root;
	struct Node* prev = NULL;

	while (curr != NULL) {
        if (curr->val == val) {
        	return NULL;
        }
        prev = curr;
        curr = curr->next;
    }

    struct Node* new_node = malloc( sizeof(struct Node) );
    new_node->next = NULL;
    new_node->val = val;
    prev->next = new_node;

    return new_node;
}




