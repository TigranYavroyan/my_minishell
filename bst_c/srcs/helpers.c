#include <bst.h>

t_TreeNode_ptr _find_bst(t_TreeNode_ptr root, const key_type key) {
    if (!root)
        return (NULL);
    if (_equal(root->key, key))
        return root;
    else if (_less(root->key, key))
        return _find_bst(root->right, key);
    else
        return _find_bst(root->left, key);
}

t_TreeNode_ptr _make_node (const key_type key, const value_type value, t_TreeNode_ptr left, t_TreeNode_ptr right) {
    t_TreeNode_ptr node = (t_TreeNode_ptr) wrapper_malloc (sizeof(t_TreeNode));
    node->key = ft_strdup(key);
    node->value = ft_strdup(value);
    node->left = left;
    node->right = right;
    return node;
}

void _free_node (t_TreeNode_ptr* root) {
    free((*root)->key);
    free((*root)->value);
    free(*root);
    *root = NULL;
}

