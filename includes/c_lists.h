#ifndef C_LISTS_H
# define C_LISTS_H

# include <stddef.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# define PRINT_LISTS	0
# define PRINT_ARR	0

# define   BLACK    "\033[0;30m"
# define   RED	    "\033[0;31m"
# define   GREEN    "\033[0;32m"
# define   YELLOW   "\033[0;33m"
# define   BLUE	    "\033[0;34m"
# define   PURPLE   "\033[0;35m"
# define   CYAN	    "\033[0;36m"
# define   WHITE    "\033[0m"
# define   MAGENTA  "\e[0;35m"

typedef struct t_list {
	int 		value;
	struct t_list	*next;
}	t_list;

typedef struct t_tree {
    int value;
    struct t_tree *left;
    struct t_tree *right;
}	t_tree;

// Algo_tester
void	algo_tester_lst_init(t_list **start, int nb);
int	algo_tester_arr_init(t_list **start, int **arr);
void	algo_tester(t_list **start);

// Utils
void	free_list(t_list **start);
void	free_words(char **words);
void	free_tree(t_tree *node);
void	errors(int code);
int	check_number(long nb);
char	**ft_split(char *str);
void	intro(void);

// General Prints
void	print_steps(int nb);

// Algo Array prints
void	arr_bubble_sort_and_print(int *arr, int size);
void	arr_bogo_sort_and_print(int *arr, int size);
void	arr_insertion_sort_and_print(int *arr, int size);
void	arr_quick_sort_and_print(int *arr, int size);
void	arr_radix_sort_and_print(int *arr, int size);
void	arr_selection_sort_and_print(int *arr, int size);
void	arr_tree_sort_and_print(int *arr, int size);

// Array Utils
void	print_arr_start(int *arr, int size);
void	print_array(int *arr, int size);
int	arr_dup(int *arr, int **new_arr, int size);

// Array Algorithms
void	arr_bubble_sort(int *arr, int size, int *steps);
void	arr_bogo_sort(int *arr, int size, int *steps);
void	arr_insertion_sort(int *arr, int size, int *steps);
void	arr_quick_sort(int *arr, int size, int *steps);
void	arr_radix_sort(int *arr, int size, int *steps, int base);
void	arr_selection_sort(int *arr, int size, int *steps);
void	arr_tree_sort(int *arr, int size, int *steps);

// Algo List prints
void	lst_print_bogo_text(void);
void	lst_print_radix_text(void);
void	lst_print_radix_bin_text(void);
void	lst_print_insertion_text(void);
void	lst_print_bubble_text(void);
void	lst_print_tree_text(void);
void	lst_print_quicksort_text(void);
void	lst_print_selection_sort_text(void);
void	lst_bogo_sort_and_print(t_list **start);
void	lst_radix_sort_and_print(t_list **start, int base);
void	lst_insertion_sort_and_print(t_list **start);
void	lst_bubble_sort_and_print(t_list **start);
void	lst_tree_sort_and_print(t_list **start);
void	lst_quick_sort_and_print(t_list **start);
void	lst_selection_sort_and_print(t_list **start);

// List Utils
void	print_lst_start(t_list **start);
void	add_to_list_end(t_list **start, int x);
void	add_to_list_start(t_list **start, int x);
void	add_to_list_after(t_list *node, int x);
void	insert_lst_sorted(t_list **start, int x);
void	print_list(t_list **start);
size_t	list_length(t_list **start);
t_list	*list_dup(t_list **start);
t_list	*get_lst_tail(t_list *start);

// Tree Utils
t_tree	*tree_insert(t_tree *start, int value, int *steps);
t_tree	*tree_create_node(int value);

// List Algorithms
t_list	*lst_radix_sort(t_list *start, int *steps, int base);
t_list	*lst_bogo_sort(t_list *start, int *steps);
t_list	*lst_insertion_sort(t_list *start, int *steps);
t_list	*lst_bubble_sort(t_list *start, int *steps);
t_list	*lst_tree_sort(t_list *start, int *steps);
t_list	*lst_quick_sort(t_list *start, t_list *end,int *steps);
t_list	*lst_selection_sort(t_list *start, int *steps);

#endif
