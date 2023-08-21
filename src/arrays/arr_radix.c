#include "../../includes/c_lists.h"

static int get_max_val(int *arr, int size)
{
	int max = arr[0];
	while (--size > 0)
		if (arr[size] > max)
			max = arr[size];
	return (max);
}

static int get_digit(int number, int pos, int base)
{
	int divisor = 1;
	for (int i = 1; i < pos; i++)
		divisor *= base;
	return ((number / divisor) % base);
}

static void column_sort(int *arr, int size, int pos, int *steps, int base)
{	
	int *count = (int *)malloc(base * sizeof(int));
	memset(count, 0, base * sizeof(int));
	
	int *temp_arr = malloc(sizeof(int) * size);
	
	for (int i = 0; i < size; i++)
	{
		int index = get_digit(arr[i], pos, base);
	 	count[index]++;
	}
	
	for (int i = 1; i < base; i++)
	{
	 	count[i] += count[i - 1];
	}
	
	for (int i = size - 1; i >= 0; i--)
	{
	 	int index = get_digit(arr[i], pos, base);
	 	temp_arr[count[index] - 1] = arr[i];
	 	count[index]--;
	 	(*steps)++;
	}
	 
	for (int i = 0; i < size; i++)
	 	arr[i] = temp_arr[i];
	 
	 free(temp_arr);
	 free(count);
}

void	arr_radix_sort(int *arr, int size, int *steps, int base)
{
	int max_val = get_max_val(arr, size);
	int num_digits = 1;
	while (max_val / base > 0)
	{
		max_val /= base;
		num_digits++;
	}
	for (int pos = 1; pos <= num_digits; pos++)
		column_sort(arr, size, pos, steps, base);
}
