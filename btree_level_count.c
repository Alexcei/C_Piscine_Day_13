#include "day13.h"

int btree_level_count(t_btree *root)
{
    if (root)
        return (FT_MAX(btree_level_count(root->left),
                       btree_level_count(root->right)) + 1);
    return (0);
}