/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonitor <gmonitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:02:14 by gmonitor          #+#    #+#             */
/*   Updated: 2021/09/03 17:34:21 by gmonitor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**ft_fillstack(int *sort, int *nsort, int size)
{
	t_stack	**stack;
	int		i;

	i = 0;
	stack = malloc(sizeof(t_stack *));
	*stack = NULL;
	while (size-- > 0)
	{
		ft_stackadd_back(stack, ft_stacknew(sort[i], find_ind(sort, nsort[i])));
		i++;
	}
	return (stack);
}

t_stack	*ft_stacknew(int nbr, int order)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->nbr = nbr;
	stack->order = order;
	stack->next = NULL;
	stack->flag = 0;
	return (stack);
}

int	stack_length(t_stack *stack)
{
	if (stack == NULL)
		return (0);
	if (stack->next == NULL)
		return (1);
	return (1 + stack_length(stack->next));
}

int	ft_max_ind(t_stack *stack)
{
	int	max_ind;

	max_ind = 0;
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		if (max_ind < stack->order)
			max_ind = stack->order;
		stack = stack->next;
	}
	return (max_ind);
}
