#include "../../includes/c_lists.h"

void	print_list(t_list **start)
{
	t_list *curr;

	curr = *start;
	while (curr)
	{
		printf("Value: %d\n", curr->value);
		curr = curr->next;
	}
}

void	add_to_list_end(t_list **start, int x)
{
	t_list *new_node;

	new_node = malloc(sizeof(t_list));

	if (new_node == NULL)
		errors(1);

	new_node->value = x;
	new_node->next = NULL;

	//check if root is NULL	
	if (*start == NULL)
	{
		*start = new_node;
		return ;
	}

	t_list	*curr = *start;

	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

void	add_to_list_start(t_list **start, int x)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		errors(1);

	new_node->value = x;
	new_node->next = *start;

	*start = new_node;
}

void	add_to_list_after(t_list *node, int x)
{
	t_list	*new_node;
	
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		errors(1);

	new_node->value = x;
	new_node->next = node->next;
	node->next = new_node;
}

void	insert_sorted(t_list **start, int x)
{
	if (*start== NULL || (*start)->value >= x)
		return add_to_list_start(start, x);

	t_list *curr = *start;
	while (curr->next != NULL)
	{
		if (curr->next->value >= x) 
		{
			add_to_list_after(curr, x);
			return ;
		}
		curr = curr->next;
	}
	add_to_list_end(start, x);
}

size_t	list_length(t_list **start)
{
	size_t	i = 0;
	t_list	*curr;
	
	if (*start == NULL)
		return (i);
	
	curr = *start;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

t_list	*list_dup(t_list **start)
{
	t_list	*result = NULL;
	t_list	*current = *start;

	while (current)
	{
		add_to_list_end(&result, current->value);
		current = current->next;
	}
	return (result);
}

t_list	*get_lst_tail(t_list *start)
{
	if (start == NULL || start->next == NULL)
		return (start);
	while (start->next != NULL)
		start = start->next;
	return (start);
}

