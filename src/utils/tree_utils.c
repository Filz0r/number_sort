#include "../../includes/c_lists.h"

t_tree *tree_create_node(int value)
{
    t_tree *node = (t_tree *)malloc(sizeof(t_tree));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

t_tree *tree_insert(t_tree *start, int value, int *steps)
{
    if (start == NULL)
        return tree_create_node(value);

    if (value < start->value)
    {
        start->left = tree_insert(start->left, value, steps);
        (*steps)++;
    }
    else if (value > start->value)
    {
        start->right = tree_insert(start->right, value, steps);
        (*steps)++;
    }

    return start;
}
