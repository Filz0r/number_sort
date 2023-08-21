#include "../../includes/c_lists.h"

void	free_list(t_list **start)
{
	t_list	*curr = *start;
	t_list	*next;
	
	while (curr)
	{
		next = curr;
		curr = curr->next;
		free(next);
	}
	*start = NULL;
}

void	free_words(char **words)
{
	int i = 0;
	while (words[i] != 0)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

void free_tree(t_tree *root)
{
    if (root == NULL)
        return;

    free_tree(root->left);
    free_tree(root->right);

    free(root);
}

// void	free_array(int *arr, int size)
// {
	// while (--size > 0)
		// free(arr[size]);
// }



void	errors(int code)
{
	if (code == 0)
	{
		printf("%sERROR%s: Insuficient number of arguments\n", RED, WHITE);
		exit(2);
	}
	else if (code == 1)
	{
		printf("%sERROR:%s Could not allocate memory for new list nodes\n", RED, WHITE);
		exit(3);
	}
	else if (code == 2)
	{
		printf("%sERROR:%s You tried to add a number larger than int to the list\n", RED, WHITE);
		exit(4);
	}
	else if (code == 3)
	{
		printf("%sERROR%s: Error while allocating memory." , RED, WHITE);
		exit(3);
	}
	else if (code == 69)
	{
		printf("\033[1;31mERROR:\033[0m Your data set can't be sorted by bogo sort\n");
	}
}

int	check_number(long nb)
{
	return (nb > INT_MAX || nb < INT_MIN);
}
