#include "../../includes/c_lists.h"

void	print_arr_start(int *arr, int size)
{
	int i = 0;
	printf("%sStarting Array:%s { ", YELLOW, WHITE);
	while (i <= (size - 1))
	{
		printf("%s%d%s", CYAN, arr[i], WHITE);
		if (i < (size - 1))
			printf(", ");
		i++;
	}
	if (i == size)
		printf(" }\n");
}

void	print_array(int *arr, int size)
{
	int i = 0;
	printf("%sCurrent Array:%s { ", GREEN, WHITE);
	while (i <= (size - 1))
	{
		printf("%s%d%s", CYAN, arr[i], WHITE);
		if (i < (size - 1))
			printf(", ");
		i++;
	}
	if (i == size)
		printf(" }\n");
}

int	arr_dup(int *arr, int **new_arr, int size)
{
	if (*new_arr == NULL)
	{
		int i = -1;
		(*new_arr) = malloc(sizeof(int) * size);
		if (!(*new_arr))
			errors(3);
		while (++i <= (size - 1))
			(*new_arr)[i] = arr[i];
		if (i == size)
			return (size);
		else
			return (0);
	}
	return (0);
}
