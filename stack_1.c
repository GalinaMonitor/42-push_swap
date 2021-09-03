/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonitor <gmonitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:02:07 by gmonitor          #+#    #+#             */
/*   Updated: 2021/09/03 17:02:10 by gmonitor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = ft_stacklast(*stack);
	last->next = new;
}

int	if_sort_stack(t_stack *stack)
{
	int	biggest;
	int	order;

	if (stack == NULL)
		return (0);
	biggest = stack->nbr;
	order = stack->order;
	if (stack->next == NULL)
		return (0);
	while (stack->next != NULL)
	{
		stack = stack->next;
		if (stack->nbr > biggest && stack->order == order + 1)
		{
			biggest = stack->nbr;
			order += 1;
		}
		else
			return (0);
	}
	return (1);
}

int	if_sort_stack_reversed(t_stack *stack)
{
	int	smallest;
	int	order;

	if (stack == NULL)
		return (0);
	smallest = stack->nbr;
	order = stack->order;
	if (stack->next == NULL)
		return (0);
	while (stack->next != NULL)
	{
		stack = stack->next;
		if (stack->nbr < smallest && stack->order == order - 1)
		{
			smallest = stack->nbr;
			order -= 1;
		}
		else
			return (0);
	}
	return (1);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (stack != NULL)
		if (stack->next)
			return (ft_stacklast(stack->next));
	return (stack);
}
