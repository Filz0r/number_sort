#include "../../includes/c_lists.h"

t_list *lst_selection_sort(t_list *start, int *steps)
{
	t_list	*curr = start;

	while (curr)
	{
		t_list	*min = curr;
		t_list	*k = curr->next;

		while (k)
		{
			if (min->value > k->value)
				min = k;

			k = k->next;
		}

		int data = curr->value;
		curr->value = min->value;
		min->value = data;
		(*steps)++;	
		curr = curr->next;
	}

	return (start);
}
