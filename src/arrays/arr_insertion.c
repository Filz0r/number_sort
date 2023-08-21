#include "../../includes/c_lists.h"

void	arr_insertion_sort(int *arr, int size, int *steps)
{
	int i, k, key;
	i = 1;
	while (i < size)
	{
		key = arr[i];
		k = i - 1;
		while (k >= 0 && arr[k] > key)
		{
			arr[k + 1] = arr[k];
			(*steps)++;
			k -= 1;
		}
		arr[k + 1] = key;
		i++;
	}
}
