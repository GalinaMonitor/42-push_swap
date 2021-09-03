#include "push_swap.h"

void quick_sort(int arr[], int left, int right)
{
	int pivot;
	int i, j;
	int temp;

	if (left >= right)
		return ;
	pivot = left;
	i = left + 1;
	j = right;
	while(i <= j)
	{
		while (i <= right && arr[i] <= arr[pivot])
			i++;
		while ( j > left && arr[j] >= arr[pivot])
			j--;
		if (i > j)
		{
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		}
		else
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	quick_sort(arr, left, j - 1);
	quick_sort(arr, j + 1, right);
}

void	ft_sort(t_stack **stack_a, int count)
{
	t_stack **stack_b;
	int length = 0;
	int radix = 0;
	int key = 0;

	stack_b = malloc(sizeof(t_stack *));
	*stack_b = NULL;
	if (stack_length(stack_a[0]) <= 5 && if_sort_stack(stack_a[0]) == 0)
	{
		sort_five_and_less(stack_a, stack_b);
		return;
	}
	while(if_sort_stack(stack_a[0]) == 0)
	{
		find_zero_in_a(stack_b, stack_a, radix);
		radix+=1;
		find_one_in_b(stack_b, stack_a, radix);
	}
	if (stack_length(stack_b[0]) > 0)
		while (stack_b[0])
			move_pa(stack_a, stack_b);
}

int main(int argc, char **argv)
{
	int *not_sorted;
	int *sorted;
	t_stack **stack;

	not_sorted = ft_check_and_parse(argc, argv);
	if (not_sorted == NULL)
		return 1;
	sorted = ft_check_and_parse(argc, argv);
	quick_sort(sorted, 0, argc - 2);
	stack = ft_fillstack(sorted, not_sorted, argc - 1);
	ft_sort(stack, argc - 1);
	ft_stackclear(*stack);
	free(stack);
	free(not_sorted);
	free(sorted);
	return 0;
}
