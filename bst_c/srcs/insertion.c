#include <bst.h>

static t_TreeNode_ptr __insert (t_TreeNode_ptr root, const key_type key, const value_type value);
static void _update_old_value (t_TreeNode_ptr TreeNode, const value_type value);

void insert_bst (t_BST_ptr bst, const key_type key, const value_type value) {
    bst->root = __insert (bst->root, key, value);
}

void update_bst (t_BST_ptr bst, const key_type key, const value_type value) {
    t_TreeNode_ptr x;
    t_TreeNode_ptr y;

    x = bst->root;
    while (x) {
        y = x;
        if (_equal(x->key, key))
            return _update_old_value(x, value);
        if (_less(x->key, key))
            x = x->right;
        else
            x = x->left;
    }

    if (_less(y->key, key))
        y->right = _make_node(key, value, NULL, NULL);
    else
        y->left = _make_node(key, value, NULL, NULL);
}

static t_TreeNode_ptr __insert (t_TreeNode_ptr root, const key_type key, const value_type value) {
    if (!root)
        return _make_node(key, value, NULL, NULL);
    if (_less(root->key, key))
        root->right = __insert(root->right, key, value);
    else if (_greater(root->key, key))
        root->left = __insert(root->left, key, value);

    return root;
}

static void _update_old_value (t_TreeNode_ptr TreeNode, const value_type value) {
    free(TreeNode->value);
    TreeNode->value = ft_strdup(value);
}