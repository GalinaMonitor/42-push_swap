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
	int ind1 = 0;
	int ind2 = 0;
	int ind3 = 0;
	int ind4 = 0;

	stack_b = malloc(sizeof(t_stack *));
	*stack_b = NULL;
	if (stack_length(stack_a[0]) <= 5)
	{
		sort_five_and_less(stack_a, stack_b);
		return;
	}
	int bbb = 5;
	while(bbb--)
	// while(if_sort_stack(stack_a[0]) == 0)
	{
		length = stack_length(stack_a[0]);
		while (stack_a[0] && stack_a[0]->flag == 1 && length--)
		{
			if (!(stack_a[0]->order >> radix & 1))
			{
				stack_a[0]->flag = 0;
				move_pb(stack_a, stack_b);
				move_rb(stack_b);
				ind2++;
			}
			else
				move_ra(stack_a);
		}
		length = stack_length(stack_b[0]);
		while(ind2-- > 0)
		{
			move_rb(stack_b);
		}
		ind2 = 0;
		length = stack_length(stack_a[0]) ;
		while(length-- && stack_a[0]->flag != 1)
		{
			if (if_sort_stack(stack_a[0]) == 1 && if_sort_stack_reversed(stack_b[0]) == 1)
				break;
			if (!(stack_a[0]->order >> radix & 1))
				move_pb(stack_a, stack_b);
			else
				move_ra(stack_a);
		}



		printf("\n\n\n______A>_____\n");
		printf("radix = %d", radix);
		ft_stackprint(stack_a[0]);
		printf("\n______B_____\n");
		ft_stackprint(stack_b[0]);



		radix+=1;
		length = stack_length(stack_b[0]);
		ind1 = 0;
		while(length--)
		{
			if (if_sort_stack(stack_a[0]) == 1 && if_sort_stack_reversed(stack_b[0]) == 1)
				break;
			if (!(stack_b[0]->order >> radix & 1))
				move_rb(stack_b);
			else
			{
				stack_b[0]->flag += 1;
				move_pa(stack_a, stack_b);
				move_ra(stack_a);
				ind1+=1;
			}
		}



		printf("\n\n\n______A_____\n");
		printf("radix = %d", radix);
		ft_stackprint(stack_a[0]);
		printf("\n______<B_____\n");
		ft_stackprint(stack_b[0]);



	}
	if (stack_length(stack_b[0]) > 0)
	{
		while (stack_b[0])
			move_pa(stack_a, stack_b);
	}
	// printf("\n___________\n");
	// ft_stackprint(stack_a[0]);
	// printf("\n___________\n");
	// ft_stackprint(stack_b[0]);
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
	ft_sort(stack, argc - 1);
	return 0;
}
