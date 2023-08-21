#include "../../includes/c_lists.h"

// This will split out linked list using the last element of the list as a pivot
static t_list	*partition(t_list *start, t_list *end, t_list **new_start, t_list **new_end, int *steps)
{
	t_list *pivot = end;
	t_list *prev = NULL;
	t_list *curr = start;
	t_list *tail = pivot;

	// While the list is being splited, both the start end the end of the list might change
	// so we use the new_start and new_end pointers to follow the changes.
	while (curr != pivot)
	{
		if (curr->value < pivot->value)
		{
			// The first node will have a smaller value than the pivot node
			// making the pivot node the new new_start 
			if ((*new_start) == NULL)
				(*new_start) = curr;
			prev = curr;
			curr = curr->next;
		}
		else // if the value of the current node is greater than the pivot
		{
			// We make our current node next to the tail node
			// and update the tail node with the current value
			if (prev != NULL)
				prev->next = curr->next;
			t_list *temp = curr->next;
			curr->next = NULL;
			tail->next = curr;
			tail = curr;
			curr = temp;
			(*steps)++;
		}
	}
	// If the value of the pivot node is the smallest in the current list
	// then, we make the pivot the new_start
	if ((*new_start) == NULL)
		(*new_start) = pivot;
	// And the new_end is updated to the current tail node
	(*new_end) = tail;

	return (pivot);	
}

t_list	*lst_quick_sort(t_list *start, t_list *end, int *steps)
{
	if (start == NULL || start == end)
		return (start);

	t_list *new_start = NULL;
	t_list *new_end = NULL;
	// We call the partition function and it will split the list in parts
	// it will also update new_start and new_end and return the pivot node
	t_list	*pivot = partition(start, end, &new_start, &new_end, steps);

	// If our pivot node is the smallest in the current list then there 
	// is no need to recur for the left part of the list
	if (new_start != pivot)
	{
		t_list *temp = new_start;
		while (temp->next != pivot)
			temp = temp->next;
		temp->next = NULL;
		// Now we recur for the list before the pivot node.	
		new_start = lst_quick_sort(new_start, temp, steps);

		temp = get_lst_tail(new_start);
		temp->next = pivot;
	}
	// Finally we recur the list after the pivot node.
	pivot->next = lst_quick_sort(pivot->next, new_end, steps);
	return (new_start);
}
