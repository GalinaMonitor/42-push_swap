/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonitor <gmonitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:37:07 by gmonitor          #+#    #+#             */
/*   Updated: 2021/09/08 15:56:23 by gmonitor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_rra(t_stack	**stack)
{
	t_stack	*temp;

	temp = stack[0];
	if (stack[0] == NULL)
		return ;
	printf("rra\n");
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = stack[0];
	stack[0] = temp->next;
	temp->next = NULL;
}

void	move_rrb(t_stack	**stack)
{
	t_stack	*temp;

	temp = stack[0];
	if (stack[0] == NULL)
		return ;
	printf("rrb\n");
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = stack[0];
	stack[0] = temp->next;
	temp->next = NULL;
}

void	move_ra(t_stack	**stack)
{
	t_stack	*temp;

	temp = stack[0];
	if (stack[0] == NULL)
		return ;
	printf("ra\n");
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = stack[0];
	stack[0] = stack[0]->next;
	temp->next->next = NULL;
}

void	move_rb(t_stack	**stack)
{
	t_stack	*temp;

	temp = stack[0];
	if (stack[0] == NULL)
		return ;
	printf("rb\n");
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = stack[0];
	stack[0] = stack[0]->next;
	temp->next->next = NULL;
}
