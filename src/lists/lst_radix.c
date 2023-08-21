#include "../../includes/c_lists.h"

static int	lst_max_val(t_list **start)
{
	t_list *curr = *start;
	int	max = curr->value;

	while (curr)
	{
		if (curr->value > max)
			max = curr->value;
		curr = curr->next;
	}
	return (max);
}


static int get_digit(int number, int pos, int base)
{
    int divisor = 1;
    for (int i = 1; i < pos; i++) 
        divisor *= base;
    return ((number / divisor) % base);
}

static void column_sort(t_list **start, int pos, int *steps, int base)
{
    int *count = (int *)malloc(base * sizeof(int));
    memset(count, 0, base * sizeof(int));

    t_list **temp_arr = (t_list **)malloc(base * sizeof(t_list *));
    for (int i = 0; i < base; i++) {
        temp_arr[i] = NULL;
    }

    t_list *ptr = *start;
    while (ptr != NULL) {
        int index = get_digit(ptr->value, pos, base);
        count[index]++;
        ptr = ptr->next;
    }

    for (int i = 1; i < base; i++)
        count[i] += count[i - 1];

    ptr = *start;
    while (ptr != NULL) {
        int index = get_digit(ptr->value, pos, base);
        t_list *temp = ptr->next;
        ptr->next = temp_arr[index];
        temp_arr[index] = ptr;
        ptr = temp;
        (*steps)++;
    }

    t_list *output = NULL;
    for (int i = base - 1; i >= 0; i--) {
        t_list *temp = temp_arr[i];
        while (temp != NULL) {
            t_list *next = temp->next;
            temp->next = output;
            output = temp;
            temp = next;
        }
    }

    *start = output;

    free(temp_arr);
    free(count);
}

t_list *lst_radix_sort(t_list *start, int *steps, int base)
{
    if (start == NULL)
        return NULL;

    int max_val = lst_max_val(&start);
    int num_digits = 1;
    while (max_val / base > 0) 
    {
        max_val /= base;
        num_digits++;
    }

    for (int pos = 1; pos <= num_digits; pos++) 
    {
        column_sort(&start, pos, steps, base);
    }

    return start;
}
