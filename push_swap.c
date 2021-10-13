/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonitor <gmonitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:30:44 by gmonitor          #+#    #+#             */
/*   Updated: 2021/10/13 17:52:04 by gmonitor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **stack_a)
{
	t_stack	**stack_b;
	int		length;
	int		radix;
	int		key;

	length = 0;
	radix = 0;
	key = 0;
	stack_b = malloc(sizeof(t_stack *));
	*stack_b = NULL;
	if (stack_length(stack_a[0]) <= 5 && if_sort_stack(stack_a[0]) == 0)
	{
		sort_five_and_less(stack_a, stack_b);
		return ;
	}
	while (if_sort_stack(stack_a[0]) == 0)
	{
		find_zero_in_a(stack_b, stack_a, radix);
		radix += 1;
		find_one_in_b(stack_b, stack_a, radix);
	}
	if (stack_length(stack_b[0]) > 0)
		while (stack_b[0])
			move_pa(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	int		*not_sorted;
	int		*sorted;
	t_stack	**stack;

	if (argc == 1)
		exit (NOARGS);
	not_sorted = check_and_parse(argc, argv);
	sorted = check_and_parse(argc, argv);
	quick_sort(sorted, 0, argc - 2);
	check_dup(sorted, argc - 1);
	stack = fillstack(sorted, not_sorted, argc - 1);
	sort(stack);
	stackclear(*stack);
	free(stack);
	free(not_sorted);
	free(sorted);
	exit (0);
}
