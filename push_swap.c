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
	// while (ind > 0)
	// {
	// 	printf("%d", sorted[--ind]);
	// }
	t_stack **stack = ft_fillstack(sorted, not_sorted, argc - 1);
	ft_stackprint(*stack);
	return 0;
}
