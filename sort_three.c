#include "push_swap.h"

void	sort_five_and_less(t_stack **stack_a, t_stack **stack_b)
{
	int ind;

	ind = 0;
	if (stack_a[0] == NULL)
		return;
	if (stack_a[0]->next == NULL)
		return;
	if (stack_length(stack_a[0]) == 2)
	{
		if (stack_a[0]->nbr > stack_a[0]->next->nbr)
			move_sa(stack_a);
		return;
	}
	if (stack_length(stack_a[0]) == 3)
		sort_three(stack_a);
	if (stack_length(stack_a[0]) == 4)
		sort_four(stack_a, stack_b);
	if (stack_length(stack_a[0]) == 5)
		sort_five(stack_a, stack_b);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
		int ind = ft_max_ind(stack_a[0]);
		if (stack_a[0]->order == ind)
		{
			move_pb(stack_a, stack_b);
			sort_three(stack_a);
			move_pa(stack_a, stack_b);
			move_ra(stack_a);
			return;
		}
		else if (ft_stacklast(stack_a[0])->order == ind)
		{
			move_rra(stack_a);
			move_pb(stack_a, stack_b);
			sort_three(stack_a);
			move_pa(stack_a, stack_b);
			move_ra(stack_a);
			return;
		}
		else
		{
			move_ra(stack_a);
			sort_four(stack_a, stack_b);
		}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int ind1 = ft_max_ind(stack_a[0]);
	int ind2 = ind1 - 1;
	while (stack_length(stack_b[0]) != 2)
	{
		if (ft_stacklast(stack_a[0])->order == ind1 || ft_stacklast(stack_a[0])->order == ind2 || stack_a[0]->order == ind1 || stack_a[0]->order == ind2)
		{
			if (stack_a[0]->order == ind1 || stack_a[0]->order == ind2)
				move_pb(stack_a, stack_b);
			if (ft_stacklast(stack_a[0])->order == ind1 || ft_stacklast(stack_a[0])->order == ind2)
			{
				move_rra(stack_a);
				move_pb(stack_a, stack_b);
			}
		}
		else
			move_ra(stack_a);
	}
	sort_three(stack_a);
	if (stack_b[0]->order == (ft_max_ind(stack_a[0]) + 1))
	{
		move_pa(stack_a, stack_b);
		move_ra(stack_a);
		move_pa(stack_a, stack_b);
		move_ra(stack_a);
	}
	else
	{
		move_pa(stack_a, stack_b);
		move_pa(stack_a, stack_b);
		move_ra(stack_a);
		move_ra(stack_a);
	}
}



void	sort_three(t_stack **stack)
{
	if (stack[0]->nbr > stack[0]->next->nbr)
	{
		if (stack[0]->nbr > stack[0]->next->next->nbr)
		{
			if (stack[0]->next->nbr > stack[0]->next->next->nbr)
			{
				move_sa(stack);
				move_rra(stack);
			}
			else
				move_ra(stack);
		}
		else if (stack[0]->nbr < stack[0]->next->next->nbr)
			move_sa(stack);
	}
	else if (stack[0]->nbr < stack[0]->next->nbr)
	{
		if (stack[0]->nbr > stack[0]->next->next->nbr)
			move_rra(stack);
		else if (stack[0]->nbr < stack[0]->next->next->nbr)
		{
			if (stack[0]->next->nbr > stack[0]->next->next->nbr)
			{
				move_sa(stack);
				move_ra(stack);
			}
			else
				return;
		}
	}
}

