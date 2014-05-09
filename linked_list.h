#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

struct Node {
	unsigned long val;
	struct Node* next;
};

struct Node* add_to_list(struct Node* head, unsigned long val);
void print_linked_list(struct Node* root);

#endif /* LINKED_LIST_H_ */
