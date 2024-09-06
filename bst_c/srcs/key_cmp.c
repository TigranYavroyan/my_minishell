#include <bst.h>

static int _strcmp_bst (const key_type in_tree, const key_type to_cmp);
static int _key_cmp (const key_type in_tree, const key_type to_cmp);

bool _less (const key_type in_tree, const key_type to_cmp) {
    return (_key_cmp(in_tree, to_cmp) < 0);
}

bool _greater (const key_type in_tree, const key_type to_cmp) {
    return (_key_cmp(in_tree, to_cmp) > 0);
}

bool _equal (const key_type in_tree, const key_type to_cmp) {
    return (_key_cmp(in_tree, to_cmp) == 0);
}

static int _strcmp_bst (const key_type in_tree, const key_type to_cmp) {
    int i;

    i = 0;
    while (in_tree[i] && to_cmp[i])
    {
        if (in_tree[i] != to_cmp[i])
            return (in_tree[i] - to_cmp[i]);
        ++i;
    }

    return (in_tree[i] - to_cmp[i]);
}

static int _key_cmp (const key_type in_tree, const key_type to_cmp) {
    return _strcmp_bst(in_tree, to_cmp);
}