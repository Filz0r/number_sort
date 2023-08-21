#include "../../includes/c_lists.h"

static t_list	*in_order_traversal(t_tree *root, t_list **start, int *steps)
{
	if (root != NULL) 
	{
		in_order_traversal(root->left, start, steps);
		(*start)->value = root->value;
		(*start) = (*start)->next;
		(*steps)++;
		in_order_traversal(root->right, start, steps);
	}
	return (*start);
}

t_list	*lst_tree_sort(t_list *start, int *steps)
{
	t_tree	*root = NULL;
	t_list	*current = start;

	while (current)
	{
		root = tree_insert(root, current->value, steps);
		current = current->next;
	}
	t_list *sorted_start = start;
	sorted_start = in_order_traversal(root, &sorted_start, steps);
	free_tree(root);
	return (start);
}
