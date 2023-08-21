#include "../../includes/c_lists.h"

static void	swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

t_list	*lst_bubble_sort(t_list *start, int *steps)
{
	t_list	*curr;
	t_list	*temp = start;
	int	swapped;

	while (temp)
	{
		curr = start;
		swapped = 0;
		while(curr->next != NULL)
		{
			if (curr->value > curr->next->value)
			{
				swap(&curr->value, &curr->next->value);
				swapped = 1;
				(*steps)++;
			}
			curr = curr->next;
		}
		if (swapped == 0)
			break ;
		temp = temp->next;	
	}
	return (start);
}
