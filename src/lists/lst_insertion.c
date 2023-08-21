#include "../../includes/c_lists.h"

t_list	*lst_insertion_sort(t_list *start, int *steps)
{
	t_list	*sorted;
	t_list	*current;

	if (start == NULL || start->next == NULL)
		return NULL;

	sorted = start;
	current = start->next;
	
	sorted->next = NULL;

	while (current != NULL)
	{
		t_list	*next = current->next;
		if (current->value < sorted->value)
		{
			current->next = sorted;
			sorted = current;
			(*steps)++;
		}
		else 
		{
			t_list	*temp = sorted;
			while (temp->next != NULL && temp->next->value < current->value)
				temp = temp->next;
			current->next = temp->next;
			temp->next = current;
			(*steps)++;
		}
		current = next;
	}
	start = sorted;
	return (start);
}
