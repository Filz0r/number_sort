#include "../includes/c_lists.h"

void	arr_bubble_sort_and_print(int *arr, int size)
{
	int *sorted_array = NULL;
	int sorted_array_length = 0;
	int steps = 0;

	sorted_array_length = arr_dup(arr, &sorted_array, size);
	arr_bubble_sort(sorted_array, sorted_array_length, &steps);
	printf("%sBubble Sort%s\n", YELLOW, WHITE);
	print_steps(steps);
	if (PRINT_ARR == 1)
		print_array(sorted_array, sorted_array_length);
	free(sorted_array);
}

void	arr_bogo_sort_and_print(int *arr, int size)
{
	int *sorted_array = NULL;
	int sorted_array_length = 0;
	int steps = 0;

	sorted_array_length = arr_dup(arr, &sorted_array, size);
	arr_bogo_sort(sorted_array, sorted_array_length, &steps);
	printf("%sBogo Sort%s\n", RED, WHITE);
	print_steps(steps);

	if (PRINT_ARR == 1)
		print_array(sorted_array, sorted_array_length);
	free(sorted_array);
}

void	arr_insertion_sort_and_print(int *arr, int size)
{
	int *sorted_array = NULL;
	int sorted_array_length = 0;
	int steps = 0;

	sorted_array_length = arr_dup(arr, &sorted_array, size);
	arr_insertion_sort(sorted_array, sorted_array_length, &steps);
	printf("%sInsertion Sort%s\n", GREEN, WHITE);
	print_steps(steps);
	if (PRINT_ARR == 1)
		print_array(sorted_array, sorted_array_length);
	free(sorted_array);
}

void	arr_quick_sort_and_print(int *arr, int size)
{
	int *sorted_array = NULL;
	int sorted_array_length = 0;
	int steps = 0;

	sorted_array_length = arr_dup(arr, &sorted_array, size);
	arr_quick_sort(sorted_array, sorted_array_length, &steps);
	printf("%sQuick Sort%s\n", GREEN, WHITE);
	print_steps(steps);

	if (PRINT_ARR == 1)
		print_array(sorted_array, sorted_array_length);
	free(sorted_array);
}

void	arr_radix_sort_and_print(int *arr, int size)
{
	int *sorted_array_base10 = NULL;
	int *sorted_array_base2 = NULL;
	int sorted_array_length_base10 = 0;
	int sorted_array_length_base2 = 0;
	int steps_base10 = 0;
	int steps_base2 = 0;

	sorted_array_length_base10 = arr_dup(arr, &sorted_array_base10, size);
	arr_radix_sort(sorted_array_base10, sorted_array_length_base10, &steps_base10, 10);

	sorted_array_length_base2 = arr_dup(arr, &sorted_array_base2, size);
	arr_radix_sort(sorted_array_base2, sorted_array_length_base2, &steps_base2, 2);

	printf("%sRadix Sort%s - Base 10\n", PURPLE, WHITE);
	print_steps(steps_base10);

	printf("%sRadix Sort%s - Base 2\n", PURPLE, WHITE);
	print_steps(steps_base2);

	if (PRINT_ARR == 1)
	{
		print_array(sorted_array_base10, sorted_array_length_base10);
		print_array(sorted_array_base2, sorted_array_length_base2);
	}

	free(sorted_array_base10);
	free(sorted_array_base2);
}

void	arr_selection_sort_and_print(int *arr, int size)
{
	int *sorted_array = NULL;
	int sorted_array_length = 0;
	int steps = 0;

	sorted_array_length = arr_dup(arr, &sorted_array, size);
	arr_selection_sort(sorted_array, sorted_array_length, &steps);
	printf("%sSelection Sort%s\n", BLUE, WHITE);
	print_steps(steps);

	if (PRINT_ARR == 1)
		print_array(sorted_array, sorted_array_length);
	free(sorted_array);
}

void	arr_tree_sort_and_print(int *arr, int size)
{
	int *sorted_array = NULL;
	int sorted_array_length = 0;
	int steps = 0;

	sorted_array_length = arr_dup(arr, &sorted_array, size);
	arr_tree_sort(sorted_array, sorted_array_length, &steps);
	printf("%sTree Sort%s\n", YELLOW, WHITE);
	print_steps(steps);

	if (PRINT_ARR == 1)
		print_array(sorted_array, sorted_array_length);
	free(sorted_array);
}
