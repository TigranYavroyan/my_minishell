#include "./includes/bst.h"

int main () {
	t_bst_ptr bst = init_bst();
	insert_bst(bst, "0", "ape");
	insert_bst(bst, "1", "ape1");
	insert_bst(bst, "2", "ape2");
	insert_bst(bst, "3", "ape2");
	insert_bst(bst, "4", "ape2");
	traverse_bst(bst, PREORDER, NULL);
}