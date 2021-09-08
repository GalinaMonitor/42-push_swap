/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonitor <gmonitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 17:02:17 by gmonitor          #+#    #+#             */
/*   Updated: 2021/09/08 15:55:12 by gmonitor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_ind(t_stack *stack, int key)
{
	int	max_ind;

	max_ind = stack->order;
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		if (max_ind > stack->order && stack->flag == key)
			max_ind = stack->order;
		stack = stack->next;
	}
	return (max_ind);
}

void	down_sorted(t_stack **stack)
{
	t_stack	*last;
	t_stack	*check;
	int		flag;

	flag = 0;
	if (stack[0] == 0)
		return ;
	check = stack[0];
	while (check != NULL)
	{
		if (check->flag == -1)
			flag = 1;
		check = check->next;
	}
	last = stacklast(stack[0]);
	if (last->flag != -1 && flag == 1)
	{
		move_rra(stack);
		down_sorted(stack);
	}
	else
		return ;
}

int	max_key(t_stack *stack)
{
	int	key;

	key = 0;
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		if (key < stack->flag)
			key = stack->flag;
		stack = stack->next;
	}
	return (key);
}

void	stackclear(t_stack *stack)
{
	if (stack != NULL)
	{
		stackclear(stack->next);
		free(stack);
		stack = NULL;
	}
}

void	get_back_from_b(t_stack **st_a, t_stack **st_b)
{
	if (st_b[0]->order == (max_ind(st_a[0]) + 1))
	{
		move_pa(st_a, st_b);
		move_ra(st_a);
		move_pa(st_a, st_b);
		move_ra(st_a);
	}
	else
	{
		move_pa(st_a, st_b);
		move_pa(st_a, st_b);
		move_ra(st_a);
		move_ra(st_a);
	}
}
