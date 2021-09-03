#include "push_swap.h"

int	is_str_digit(char *str)
{
	if(*str == '+' || *str == '-')
		str++;
	while(ft_isdigit(*str) && *str)
		str++;
	if(*str)
		return 0;
	else
		return 1;
}

void	find_zero_in_a(t_stack **stack_b, t_stack **stack_a, int radix)
{
	int length;

	length = stack_length(stack_a[0]);
	while(length--)
	{
		if (if_sort_stack(stack_a[0]) == 1 && if_sort_stack_reversed(stack_b[0]) == 1)
			return;
		if (!(stack_a[0]->order >> radix & 1))
			move_pb(stack_a, stack_b);
		else
			move_ra(stack_a);
	}
}

void	find_one_in_b(t_stack **stack_b, t_stack **stack_a, int radix)
{
	int length;

	length = stack_length(stack_b[0]);
	while(length--)
	{
		if (if_sort_stack(stack_a[0]) == 1 && if_sort_stack_reversed(stack_b[0]) == 1)
			return;
		if (!(stack_b[0]->order >> radix & 1))
			move_rb(stack_b);
		else
			move_pa(stack_a, stack_b);
	}
}

int	*ft_check_and_parse(int argc, char **argv)
{
	int ind;
	int *not_sorted;

	not_sorted = malloc(sizeof(int) * (argc - 1));
	ind = 0;
	while (ind < argc - 1)
	{
		if (is_str_digit(argv[ind + 1]))
		{
			not_sorted[ind] = ft_atoi(argv[ind + 1]);
			if (not_sorted[ind] < 0)
			{
				write(1, "Error", 5);
				return NULL;
			}
			ind++;
		}
		else
		{
			write(1, "Error", 5);
			return NULL;
		}
	}
	return (not_sorted);
}

int	find_ind(int	*arr, int	nbr)
{
	int	res;

	res = 0;
	while (*arr)
	{
		if (*arr == nbr)
			return (res);
		else
		{
			arr++;
			res++;
		}
	}
	return (-1);
}
