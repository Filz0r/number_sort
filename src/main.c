#include "../includes/c_lists.h"

int main(int ac, char **av)
{
	t_list *root;
	int i;
	int count = 0;
	long number;
	root = NULL;

//	intro();
	if (ac == 2)
	{
		char **numbers = ft_split(av[1]);
		i = 0;
		while (numbers[i] != 0)
		{
			number = atol(numbers[i]);
			if (check_number(number))
				errors(2);
			algo_tester_lst_init(&root, (int)number);
			count++;
			i++;
		}
		algo_tester(&root);
		free_list(&root);
		free_words(numbers);
	}
	else if (ac > 2) 
	{
		i = 1;
		while (i < ac)
		{
			number = atol(av[i]);
			if (check_number(number))
				errors(2);
			algo_tester_lst_init(&root, (int)number);
			count++;
			i++;
		}
		algo_tester(&root);
		free_list(&root);
	}
	else 
		errors(0);
	return (0);
}
