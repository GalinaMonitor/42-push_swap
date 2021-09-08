/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonitor <gmonitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:02:14 by gmonitor          #+#    #+#             */
/*   Updated: 2021/09/08 15:55:27 by gmonitor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**fillstack(int *srt, int *nsrt, int size)
{
	t_stack	**st;
	int		i;

	i = 0;
	st = malloc(sizeof(t_stack *));
	*st = NULL;
	while (size-- > 0)
	{
		stackadd_back(st, stacknew(nsrt[i], find_ind(srt, nsrt[i]) + 1));
		i++;
	}
	return (st);
}

t_stack	*stacknew(int nbr, int order)
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

int	max_ind(t_stack *stack)
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
