#include "../../includes/c_lists.h"

static void	swap(int *x, int *y, int *steps)
{
	int temp = *x;
	*x = *y;
	*y = temp;
	(*steps)++;
}

static int	partition(int *arr, int start, int end, int *steps)
{
	int pivot = arr[end];
	int i = start - 1;
	int k = start;

	while (k <= end - 1)
	{
		if (arr[k] < pivot)
		{
			i++;
			swap(&arr[i], &arr[k], steps);
		}
		k++;
	}
	swap(&arr[i + 1], &arr[end], steps);
	return (i + 1);
}



static	void	qs_recursive(int *arr, int start, int end, int *steps)
{
	if (start < end)
	{
		int pivot = partition(arr, start, end, steps);

		qs_recursive(arr, start, (pivot - 1), steps);
		qs_recursive(arr, (pivot + 1), end, steps);
	}
}

void	arr_quick_sort(int *arr, int size, int *steps)
{
	return (qs_recursive(arr, 0, (size - 1), steps));
}
