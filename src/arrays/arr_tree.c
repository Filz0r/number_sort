#include "../../includes/c_lists.h"

static int *in_order_traversal(t_tree *root, int *arr, int *steps, int *i)
{
	if (root != NULL)
	{
		in_order_traversal(root->left, arr, steps, i);
		arr[(*i)++] = root->value;
		(*steps)++;
		in_order_traversal(root->right, arr, steps , i);
	}
	return (arr);
}

void arr_tree_sort(int *arr, int size, int *steps)
{
	t_tree *root = NULL;
	int i = 0;

	while (i < size)
	{
		root = tree_insert(root, arr[i], steps);
		i++;
	}
	i = 0;
	arr = in_order_traversal(root, arr, steps, &i);
	free_tree(root);
}
