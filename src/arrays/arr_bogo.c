#include "../../includes/c_lists.h"

static int is_sorted(int *arr, int size)
{
	int i = 0;
	while (i <= (size - 1))
	{
		if (i < (size - 1) && arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

static void	shuffle(int *arr, int size, int *steps)
{
	int i = 0;
	while (i < (size - 1))
	{
		swap(&arr[i], &arr[rand() % size]);
		(*steps)++;
		i++;
	}
}

void	arr_bogo_sort(int *arr, int size,int *steps)
{
	while (is_sorted(arr, size) == 0)
	{
		if ((*steps) >= 80000)
		{
			return errors(69);
		}
		shuffle(arr, size, steps);
	}
}
