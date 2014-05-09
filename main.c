#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "print_utils.h"
#include "constants.h"

const int SIZE = 8;

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef struct {
	unsigned long positions;
	unsigned long threatened;
} ChessBoard;


int placeQueen(ChessBoard* board, int row, int col) {
	int index = row*SIZE + col;
	if ((board->positions >> index) & 0x01) {
		// Cell already occupied
		return -1;
	}
	//printf("placing queen at (%d, %d)\n", row, col);
	board->positions |= ((unsigned long)0x01 << index);
	// cover row
	int i, j;
	for (i=0; i<SIZE; i++) {
		board->threatened |= ((unsigned long)0x01 << (row*SIZE + i));
	}
	// cover column
	for (i=0; i<SIZE; i++) {
		board->threatened |= ((unsigned long)0x01 << (SIZE*i + col));
	}
	//diagonals
	i = MAX(0, row-col);
	j = MAX(0, col-row);
	while ((i < SIZE) & (j < SIZE)) {
		board->threatened |= ((unsigned long)0x01 << (SIZE*i + j));
		i++;
		j++;
	}
	i = MAX(0, (row+col)-(SIZE-1));
	j = MIN(SIZE-1, row+col);
	while ((i < SIZE) & (j >= 0)) {
		board->threatened |= ((unsigned long)0x01 << (SIZE*i + j));
		i++;
		j--;
	}
	return 0;
}

unsigned long rotate_ccw_90(unsigned long board) {
	unsigned long board_out = 0;
	int i, j; // traverse original board
	int m, n; // assign to output board
	m = 0;
	for (j=SIZE-1; j>=0; j--) {
		n = 0;
		for (i=0; i<SIZE; i++) {
			int orig_val = (board >> (i*SIZE + j)) & 0x01;
			if (orig_val) {
				board_out |= (unsigned long)0x01 << (m*SIZE+ n);
			}
			n++;
		}
		m++;
	}
	return board_out;
}

unsigned long rotate_ccw_180(unsigned long board) {
	return rotate_ccw_90(rotate_ccw_90(board));
}

unsigned long rotate_ccw_270(unsigned long board) {
	return rotate_ccw_90(rotate_ccw_180(board));
}

void recurse(ChessBoard board, int position, int depth, struct Node* solutions) {
	if ((position >= SIZE*SIZE)||(depth >= SIZE)) {
		return;
	}
	while (position < SIZE*SIZE) {
		if ((board.threatened >> position) & 0x01) {
			position++;
			continue;
		}
		ChessBoard board_copy = board;
		placeQueen(&board_copy, position/SIZE, position%SIZE);
		if (depth == SIZE-1) {
			// found a solution!
			//printBoard(board_copy.positions);
			add_to_list(solutions, board_copy.positions);
			add_to_list(solutions, rotate_ccw_90(board_copy.positions));
			add_to_list(solutions, rotate_ccw_180(board_copy.positions));
			add_to_list(solutions, rotate_ccw_270(board_copy.positions));
		}
		recurse(board_copy, position+1, depth+1, solutions);
		position++;
	}
}


int main() {
	int i;
	struct Node* solutions = malloc( sizeof(struct Node) );
	solutions->next = NULL;
	solutions->val = 0;

	for (i=0; i<SIZE; i++) {
		ChessBoard board = {0, 0};
		placeQueen(&board, i/SIZE, i%SIZE);
		recurse(board, i+1, 1, solutions);
	}
	print_linked_list(solutions);
	/*
	ChessBoard board = {0, 0};
	placeQueen(&board, 7, 0);
	printBoard(board.positions);
	unsigned long rotated_90 = rotate_ccw_90(board.positions);
	unsigned long rotated_180 = rotate_ccw_90(rotated_90);
	printBoard(rotated_90);
	printBoard(rotated_180);

	struct Node* root;
	root = malloc( sizeof(struct Node) );
	root->next = NULL;
	root->val = rotated_180;

	add_to_list(root, 5);
	add_to_list(root, rotated_180);
	print_linked_list(root);
	*/

	printf("done");
	return 0;
}
