#include "../../includes/c_lists.h"

static void swap(int *x, int *y, int *steps)
{
	int temp = *x;
	*x = *y;
	*y = temp;
	(*steps)++;
}

void	arr_selection_sort(int *arr, int size, int *steps)
{
	for (int step = 0; step < (size - 1); step++)
	{
		int min = step;
		for (int i = step + 1; i < size; i++)
		{
			if (arr[i] < arr[min])
				min = i;
		}
		swap(&arr[min], &arr[step], steps);
	}
	// int min, key;
	// for (int i = 0; i < (size - 1); i++)
	// {
	// 	min = i;
	// 	for (int k = i + 1; k < (size); k++)
	// 	{
	// 		if(arr[min] > arr[k])
	// 			min = k;
	// 	}
	// 	key = arr[min];
	// 	for (int j = min; j > i; j--)
	// 	{
	// 		arr[j] = arr[j - 1];
	// 		arr[i] = key;
	// 		(*steps)++;
	// 	}
	// }
}
