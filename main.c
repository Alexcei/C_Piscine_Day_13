#include <stdio.h>
#include "day13.h"

void    print_item(void *item)
{
    printf("%s\n", item);
}

void    print_i_c_f(void *item, int current_level, int is_first_elem)
{
    printf("%s %d %d\n", item, current_level, is_first_elem);
}

int main()
{
    //t_btree *tree;

    t_btree *root = btree_create_node("3");
    root->left = btree_create_node("1");
    root->right = btree_create_node("5");

    //btree_apply_prefix(root, ft_print);
    //btree_apply_infix(root, ft_print);
    //btree_apply_suffix(root, ft_print);

    btree_insert_data(&root, "9", (void*)ft_strcmp);
    //print_item(root->right->right->item);

    //tree = btree_search_item(root, "9", (void*)ft_strcmp);
    //print_item(tree->item);

    //print_item("%d\n", btree_level_count(root));

    btree_apply_by_level(root, print_i_c_f);

    printf("  %s\n", root->item);
    printf("%s   %s\n", root->left->item, root->right->item);



    return (0);
}