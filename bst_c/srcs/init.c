#include <bst.h>

static t_TreeNode_ptr _copy (t_TreeNode_ptr from);

t_BST_ptr init_bst () {
    t_BST_ptr tree = (t_BST_ptr) wrapper_malloc (sizeof(t_BST));
    tree->root = NULL;
    tree->size = 0;

    return tree;
}


t_BST_ptr copy_bst (const t_BST_ptr bst) {
    t_BST_ptr tree = init_bst();

    tree->root = _copy(bst->root);

    return tree;
}

static t_TreeNode_ptr _copy (t_TreeNode_ptr from) {
    t_TreeNode_ptr root;

    if (!from)
        return (NULL);

    root = _make_node(from->key, from->value, NULL, NULL);
    root->left = _copy(from->left);
    root->right = _copy(from->right);

    return root;
}