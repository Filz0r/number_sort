#include "../../includes/c_lists.h"

static int is_sorted(t_list *start)
{
	t_list	*curr = start;

	while (curr->next != NULL)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}


static void	shuffle(t_list *start, int *steps)
{
	int length = (int)list_length(&start);
	t_list	*curr =	start;
	int i = 0;
	int k = 0;

	while (i < length - 1)
	{
		int j = random() % (length - i) + i;
		t_list *nodeI = NULL;
		t_list *nodeJ = NULL;
		k = 0;
		
		while (k <= j && curr != NULL)
		{
			if (k == i)
				nodeI = curr;
			if (k == j)
				nodeJ = curr;
			curr = curr->next;
			k++;
		}
		if (nodeJ != NULL && nodeI != NULL)
		{
			int temp = nodeI->value;
			nodeI->value = nodeJ ->value;
			nodeJ->value = temp;
			(*steps)++;
		}
		i++;
	}
}

t_list	*lst_bogo_sort(t_list *start, int *steps)
{
	while (is_sorted(start) != 1)
	{
		if (*steps >= 80000)
		{
			errors(69);
			return (start);
		}	
		shuffle(start, steps);
	}
	return (start);
}
