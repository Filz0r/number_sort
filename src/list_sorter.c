#include "../includes/c_lists.h"

void	lst_bogo_sort_and_print(t_list **start)
{
	t_list *sorted_list;
	int steps = 0;

	sorted_list = list_dup(start);
	sorted_list = lst_bogo_sort(sorted_list, &steps);
	if (PRINT_LISTS == 1)
		print_list(&sorted_list);
	print_steps(steps);
	free_list(&sorted_list);
}

void	lst_radix_sort_and_print(t_list **start, int base)
{
	t_list *sorted_list;
	int	steps = 0;
	
	sorted_list = list_dup(start);
	sorted_list = lst_radix_sort(sorted_list, &steps, base);
	if (PRINT_LISTS == 1)
		print_list(&sorted_list);
	print_steps(steps);
	free_list(&sorted_list);
}

void	lst_insertion_sort_and_print(t_list **start)
{
	t_list *sorted_list;
	int steps = 0;

	sorted_list = list_dup(start);
	sorted_list = lst_insertion_sort(sorted_list, &steps);
	if (PRINT_LISTS == 1)
		print_list(&sorted_list);
	print_steps(steps);
	free_list(&sorted_list);
}

void	lst_bubble_sort_and_print(t_list **start)
{
	t_list *sorted_list;
	int steps = 0;

	sorted_list = list_dup(start);
	sorted_list = lst_bubble_sort(sorted_list, &steps);
	if (PRINT_LISTS == 1)
		print_list(&sorted_list);
	print_steps(steps);
	free_list(&sorted_list);
}

void	lst_tree_sort_and_print(t_list **start)
{
	t_list *sorted_list;
	int steps = 0;

	sorted_list = list_dup(start);
	sorted_list = lst_tree_sort(sorted_list, &steps);
	if (PRINT_LISTS == 1)
		print_list(&sorted_list);
	print_steps(steps);
	free_list(&sorted_list);
}

void	lst_quick_sort_and_print(t_list **start)
{
	t_list *sorted_list;
	t_list *end;
	int steps = 0;

	sorted_list = list_dup(start);
	end = get_lst_tail(sorted_list);
	sorted_list = lst_quick_sort(sorted_list, end, &steps);

	if (PRINT_LISTS == 1)
		print_list(&sorted_list);
	print_steps(steps);
	free_list(&sorted_list);
}

void	lst_selection_sort_and_print(t_list **start)
{
	t_list *sorted_list;
	int steps = 0;

	sorted_list = list_dup(start);
	sorted_list = lst_selection_sort(sorted_list, &steps);
	if (PRINT_LISTS == 1)
		print_list(&sorted_list);
	print_steps(steps);
	free_list(&sorted_list);
}
