#include "day13.h"
#include <stdio.h>

void	call(t_btree *root, int current_level, int *levels,
             void (*applyf)(void *item, int current_level, int is_first_elem))
{
    applyf(root->item, current_level, levels[current_level]);
    if (levels[current_level])
        levels[current_level] = 0;
    if (root->left)
        call(root->left, current_level + 1, levels, applyf);
    if (root->right)
        call(root->right, current_level + 1, levels, applyf);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
                                                           int current_level, int is_first_elem))
{
    int	count;
    int	*levels;

    if (root && applyf)
    {
        count = btree_level_count(root);
        levels = (int *)malloc(sizeof(int) * count);
        if (levels)
        {
            while (count--)
                levels[count] = 1;
            call(root, 0, levels, applyf);
        }
    }
}