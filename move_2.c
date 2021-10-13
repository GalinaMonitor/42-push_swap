/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonitor <gmonitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:38:01 by gmonitor          #+#    #+#             */
/*   Updated: 2021/10/10 16:18:33 by gmonitor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_sa(t_stack	**stack)
{
	t_stack	*addr;
	t_stack	*addr1;

	write(1, "sa\n", 3);
	addr1 = stack[0]->next;
	addr = stack[0]->next->next;
	stack[0]->next->next = *stack;
	stack[0]->next = addr;
	*stack = addr1;
}

void	move_sb(t_stack	**stack)
{
	t_stack	*addr;
	t_stack	*addr1;

	write(1, "sb\n", 3);
	addr1 = stack[0]->next;
	addr = stack[0]->next->next;
	stack[0]->next->next = *stack;
	stack[0]->next = addr;
	*stack = addr1;
}

void	move_pa(t_stack	**stack_a, t_stack	**stack_b)
{
	t_stack	*addr;

	write(1, "pa\n", 3);
	addr = stack_b[0]->next;
	stack_b[0]->next = stack_a[0];
	stack_a[0] = stack_b[0];
	stack_b[0] = addr;
}

void	move_pb(t_stack	**stack_b, t_stack	**stack_a)
{
	t_stack	*addr;

	write(1, "pb\n", 3);
	addr = stack_b[0]->next;
	stack_b[0]->next = stack_a[0];
	stack_a[0] = stack_b[0];
	stack_b[0] = addr;
}
