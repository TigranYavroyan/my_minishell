#include <bst.h>

static void _clear (t_TreeNode_ptr root);
static void _copy_bst (t_TreeNode_ptr to, t_TreeNode_ptr from);
static t_TreeNode_ptr _remove(t_TreeNode_ptr root, const key_type key);

void clear_bst (t_BST_ptr* bst) {
    if (!bst || !(*bst)) return;

    _clear((*bst)->root);
    free(*bst);
    *bst = NULL;
}

void    remove_bst (t_BST_ptr bst, const key_type key) {
    if (_find_bst(bst->root, key))
        --bst->size;
    bst->root = _remove(bst->root, key);
}

static void _clear (t_TreeNode_ptr root) {
    if (!root)
        return ;
    
    _clear(root->left);
    _clear(root->right);
    _free_node(&root);
}

static void _copy_bst (t_TreeNode_ptr to, t_TreeNode_ptr from) {
    free(to->key);
    free(to->value);
    to->key = ft_strdup(from->key);
    to->value = ft_strdup(from->value);
}

static t_TreeNode_ptr _remove(t_TreeNode_ptr root, const key_type key) {
    t_TreeNode_ptr tmp;

    if (!root)
        return (NULL);
    if (_less(root->key, key))
        root->right = _remove(root->right, key);
    else if (_greater(root->key, key))
        root->left = _remove(root->left, key);
    else {
        if (!root->left) {
            tmp = root->right;
            _free_node(&root);
            return tmp;
        }
        else if (!root->right) {
            tmp = root->left;
            _free_node(&root);
            return tmp;
        }
        else {
            tmp = _find_min_bst(root->right);
            _copy_bst(root, tmp);
            root->right = _remove(root->right, tmp->key);
        }
    }
    return root;
}

