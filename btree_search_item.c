#include "day13.h"

void	*btree_search_item(t_btree *root,
                           void *data_ref, int (*cmpf)(void *, void *))
{
    t_btree *tree;

    tree = NULL;
    if (root && data_ref && cmpf)
    {
        if ((tree = btree_search_item(root->left, data_ref, cmpf)))
            return (tree);
        if (cmpf(root->item, data_ref) == 0)
            return (root);
        tree = btree_search_item(root->right, data_ref, cmpf);
    }
    return (tree);
}