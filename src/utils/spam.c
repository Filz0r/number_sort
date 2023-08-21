#include "../../includes/c_lists.h"

void	print_lst_start(t_list **start)
{
	size_t size = list_length(start);
	printf("Printing the List:\n");
	print_list(start);
	printf("The list as a total of %zu elements.\n", size);
}

void	print_steps(int nb)
{
	printf("The algorithm ran in %s%d%s steps.\n", YELLOW, nb, WHITE);
}

void	lst_print_bogo_text(void)
{
	printf("%sBogo/Stupid Sort%s.\n", RED, WHITE);
	printf("Note that the list is copied into a new list\n");
}

void	lst_print_radix_text(void)
{
	printf("%sRadix Sort%s - Base 10.\n", YELLOW, WHITE);
	printf("Note that the list is copied into a new list\n");
}

void	lst_print_radix_bin_text(void)
{
	printf("%sRadix Sort%s - Base 2.\n", YELLOW, WHITE);
	printf("Note that the list is copied into a new list\n");
}

void	lst_print_insertion_text(void)
{
	printf("%sInsertion Sort%s.\n", GREEN, WHITE);
	printf("Note that the list is copied into a new list\n");
}

void	lst_print_bubble_text(void)
{
	printf("%sBubble Sort%s.\n", CYAN, WHITE);
	printf("Note that the list is copied into a new list\n");
}

void	lst_print_tree_text(void)
{
	printf("%sTree Sort%s.\n", PURPLE, WHITE);
	printf("Note that the list is copied into a new list\n");
}


void	lst_print_quicksort_text(void)
{
	printf("%sQuick Sort%s.\n", BLUE, WHITE);
	printf("Note that the list is copied into a new list\n");
}

void	lst_print_selection_sort_text(void)
{
	printf("%sSelection Sort%s.\n", MAGENTA, WHITE);
	printf("Note that the list is copied into a new list\n");
}

void	intro(void)
{
	printf("This program will parse all the arguments that fit inside an INT value\n");
	printf("then it will place all the numbers without being ordered inside a list.\n");
	printf("Finally it will sort the list using different algorithms and will say\n");
	printf("how many steps it took to sort the list for each algorithm\n");
}
