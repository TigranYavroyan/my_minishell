#include <minishell.h>
//int argc, char** argv, char** env
int main () {
    t_BST_ptr tree = init_bst();
    insert_bst(tree, "nav3", "baaa3");
    insert_bst(tree, "nav2", "baaa2");
    insert_bst(tree, "nav1", "baaa");
    update_bst(tree, "nav1", "en vor senc");
    update_bst(tree, "nav4", "dpa chasharan");
    remove_bst(tree, "nav3");
    remove_bst(tree, "nav2");
    remove_bst(tree, "nav1");
    traverse_bst(tree, INORDER, NULL);
    clear_bst(&tree);
}