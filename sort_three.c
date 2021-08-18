#include "push_swap.h"

void	sort_five_and_less(t_stack **stack_a, t_stack **stack_b, int key)
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
			move_sa_sb_ss(stack_a);
		return;
	}
	if (stack_length(stack_a[0]) == 3)
		sort_three(stack_a);
	if (stack_length(stack_a[0]) == 4)
		sort_four(stack_a, stack_b, key);
	if (stack_length(stack_a[0]) == 5)
		sort_five(stack_a, stack_b, key);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b, int key)
{
		int ind = ft_max_ind(stack_a[0], key);
		if (stack_a[0]->order == ind)
		{
			move_pb(stack_a, stack_b);
			sort_three(stack_a);
			move_pa(stack_a, stack_b);
			move_ra_rb_rr(stack_a);
			return;
		}
		else if (ft_stacklast(stack_a[0])->order == ind)
		{
			move_rra_rrb_rrr(stack_a);
			move_pb(stack_a, stack_b);
			sort_three(stack_a);
			move_pa(stack_a, stack_b);
			move_ra_rb_rr(stack_a);
			return;
		}
		else
		{
			move_ra_rb_rr(stack_a);
			sort_four(stack_a, stack_b, key);
		}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, int key)
{
	int ind1 = ft_max_ind(stack_a[0], key);
	int ind2 = ind1 - 1;
	while (ind1 != -1 || ind2 != -1)
	{
		if (stack_a[0]->order == ind1)
		{
			move_pb(stack_a, stack_b);
			ind1 = -1;
		}
		if (stack_a[0]->order == ind2)
		{
			move_pb(stack_a, stack_b);
			ind2 = -1;
		}
		if (ft_stacklast(stack_a[0])->order == ind1)
		{
			move_rra_rrb_rrr(stack_a);
			move_pb(stack_a, stack_b);
			ind1 = -1;
		}
		if (ft_stacklast(stack_a[0])->order == ind2)
		{
			move_rra_rrb_rrr(stack_a);
			move_pb(stack_a, stack_b);
			ind2 = -1;
		}
		move_ra_rb_rr(stack_a);
	}
	sort_three(stack_a);
	if (stack_b[0]->order == (ft_max_ind(stack_a[0], key) + 1))
	{
		move_pa(stack_a, stack_b);
		move_ra_rb_rr(stack_a);
	}
	else
	{
		move_pa(stack_a, stack_b);
		move_pa(stack_a, stack_b);
		move_ra_rb_rr(stack_a);
		move_ra_rb_rr(stack_a);
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
					move_sa_sb_ss(stack);
					move_rra_rrb_rrr(stack);
				}
				else
					move_ra_rb_rr(stack);
			}
			else if (stack[0]->nbr < stack[0]->next->next->nbr)
				move_sa_sb_ss(stack);
		}
		else if (stack[0]->nbr < stack[0]->next->nbr)
		{
			if (stack[0]->nbr > stack[0]->next->next->nbr)
				move_rra_rrb_rrr(stack);
			else if (stack[0]->nbr < stack[0]->next->next->nbr)
			{
				if (stack[0]->next->nbr > stack[0]->next->next->nbr)
				{
					move_sa_sb_ss(stack);
					move_ra_rb_rr(stack);
				}
				else
					return;
			}
		}
}

