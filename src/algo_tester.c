#include "../includes/c_lists.h"

void	algo_tester_lst_init(t_list **start, int nb)
{
	add_to_list_end(start, nb);
}

int algo_tester_arr_init(t_list **start, int **arr)
{
	int arr_len = list_length(start);
	int i = 0;
	if (*arr == NULL)
	{
		t_list *curr = *start;
		*arr = malloc(sizeof(int) * arr_len);
		if (!(*arr))
			errors(3);
		while (curr != NULL)
		{
			(*arr)[i] = curr->value;
			i++;
			curr = curr->next;
		}
	}
	if (i == arr_len)
		return (arr_len);
	else
		return (0);
}

void	algo_tester(t_list **start)
{
	int *start_arr = NULL;
	int arr_len = 0;

	// Array sorting
	arr_len = algo_tester_arr_init(start, &start_arr);
	if (arr_len > 0)
	{
		if (PRINT_ARR == 1)
		{
			print_arr_start(start_arr, arr_len);
		}
		arr_bubble_sort_and_print(start_arr, arr_len);
		arr_bogo_sort_and_print(start_arr, arr_len);
		arr_insertion_sort_and_print(start_arr, arr_len);
		arr_quick_sort_and_print(start_arr, arr_len);
		arr_radix_sort_and_print(start_arr, arr_len);
		arr_selection_sort_and_print(start_arr, arr_len);
		arr_tree_sort_and_print(start_arr, arr_len);
	}
	else
		printf("errors idiot\n");
	// Don't forget to free the starting array
	free(start_arr);
	// List Sorting
	if (PRINT_LISTS == 1) 
		print_lst_start(start);
	lst_print_bogo_text();
	lst_bogo_sort_and_print(start);
	lst_print_radix_text();
	lst_radix_sort_and_print(start, 10);
	lst_print_radix_bin_text();
	lst_radix_sort_and_print(start, 2);
	lst_print_insertion_text();
	lst_insertion_sort_and_print(start);
	lst_print_bubble_text();
	lst_bubble_sort_and_print(start);
	lst_print_tree_text();
	lst_tree_sort_and_print(start);
	lst_print_quicksort_text();
	lst_quick_sort_and_print(start);
	lst_print_selection_sort_text();
	lst_selection_sort_and_print(start);

}


