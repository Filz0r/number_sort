#include "../../includes/c_lists.h"

static void	swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void	arr_bubble_sort(int *arr, int size, int *steps)
{
	int i = 0;
	int k;
	int swapped;
	while (i <= (size - 1))
	{	
		swapped = 0;
		k = 0;
		while (k <= (size - 2))
		{
			if (arr[k] > arr[k + 1])
			{
				swap(&arr[k], &arr[k + 1]);
				(*steps)++;
				swapped = 1;
			}
			k++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}
