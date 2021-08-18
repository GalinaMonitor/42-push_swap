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

	int temp_middle = 0;
	int temp_count = 0;
	int middle = 0;
	int key = 0;
	int count_key = 0;

	// printf("\n count arg = %d\n", count);
	stack_b = malloc(sizeof(t_stack *));
	*stack_b = NULL;
	key = ft_max_key(stack_a[0]);
	if (stack_length(stack_a[0]) <= 5)
	{
		sort_five_and_less(stack_a, stack_b, key);
		return;
	}
	while(if_sort_stack(stack_a[0]) != 1)
	{
		key = ft_max_key(stack_a[0]);
		middle = (ft_max_ind(stack_a[0], key) + ft_min_ind(stack_a[0], key))/2;
		temp_middle = (ft_max_ind(stack_a[0], key) - ft_min_ind(stack_a[0], key))/2 + 1;
		if (temp_middle < 5)
		{
			temp_middle = (ft_max_ind(stack_a[0], key) - ft_min_ind(stack_a[0], key)) + 1;
			middle = ft_max_ind(stack_a[0], key);
		}

		temp_count = stack_length(stack_a[0]);
		// printf("\nMIDDLE = %d\n", middle);
		// printf("\nTEMPMIDDLE = %d\n", temp_middle);
		// printf("\nKEY = %d\n", key);
		while (temp_middle && temp_count && if_sort_stack(stack_a[0]) == 0)
		{
			if (stack_a[0]->order <= middle && stack_a[0]->flag == key)
			{
				move_pb(stack_a, stack_b);
				temp_middle--;
			}
			else
			{
				move_ra_rb_rr(stack_a);
				temp_count--;
			}
		}
		key = ft_max_key(stack_b[0]);
		count_key = 1;
		ft_down_sorted(stack_a);
		while(stack_length(stack_b[0]) > 5)
		{
			middle = (ft_max_ind(stack_b[0], key) + ft_min_ind(stack_b[0], key))/2;
			temp_middle = (ft_max_ind(stack_b[0], key) - ft_min_ind(stack_b[0], key))/2 + 1;
			temp_count = stack_length(stack_b[0]);
			printf("\nMIDDLE = %d\n", middle);
			printf("\nTEMPMIDDLE = %d\n", temp_middle);
			printf("\nKEY = %d\n", key);
			while (temp_middle > 0 && temp_count > 0)
			{
				if (stack_b[0]->order > middle)
				{
					stack_b[0]->flag+= key;
					move_pa(stack_a, stack_b);
					temp_middle--;
				}
				else
				{
					move_ra_rb_rr(stack_b);
					temp_count--;
				}
			}
			count_key++;
		}
		key = ft_max_key(stack_b[0]);
		sort_five_and_less(stack_b, stack_a, key);
		while(stack_b[0])
		{
			stack_b[0]->flag = -1;
			move_pa(stack_a, stack_b);
			move_ra_rb_rr(stack_a);
		}
		printf("\n\nStack A");
		ft_stackprint(*stack_a);
		printf("\n\nStack B");
		ft_stackprint(*stack_b);
	}
	// printf("\n\nStack A");
	// ft_stackprint(*stack_a);
	// printf("\n\nStack B");
	// ft_stackprint(*stack_b);
}

int main(int argc, char **argv)
{
	int ind;
	int not_sorted[argc - 1];
	int sorted[argc - 1];
	ind = 0;
	while (ind < argc - 1)
	{
		not_sorted[ind] = ft_atoi(argv[ind + 1]);
		sorted[ind] = ft_atoi(argv[ind + 1]);
		ind++;
	}
	quick_sort(sorted, 0, argc - 2);
	t_stack **stack = ft_fillstack(sorted, not_sorted, argc - 1);
	// printf("\nFirst\n");
	// ft_stackprint(*stack);
	ft_sort(stack, argc - 1);
	return 0;
}
