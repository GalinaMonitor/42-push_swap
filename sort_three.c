#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	if (stack[0] == NULL)
		return;
	if (stack[0]->next == NULL)
		return;
	if (stack[0]->next->next == NULL)
	{
		if (stack[0]->nbr > stack[0]->next->nbr)
			move_sa_sb_ss(stack);
		return;
	}
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
			{
				move_ra_rb_rr(stack);
			}
		}
		else if (stack[0]->nbr < stack[0]->next->next->nbr)
		{
			move_sa_sb_ss(stack);
		}
	}
	else if (stack[0]->nbr < stack[0]->next->nbr)
	{
		if (stack[0]->nbr > stack[0]->next->next->nbr)
		{
			move_rra_rrb_rrr(stack);
		}
		else if (stack[0]->nbr < stack[0]->next->next->nbr)
		{
			if (stack[0]->next->nbr > stack[0]->next->next->nbr)
			{
				move_sa_sb_ss(stack);
				move_ra_rb_rr(stack);
			}
			else
			{
				return;
			}
		}
	}
}
