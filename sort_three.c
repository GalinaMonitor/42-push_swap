#include "push_swap.h"

void	sort_five_and_less(t_stack **st_a, t_stack **st_b)
{
	int	ind;

	ind = 0;
	if (st_a[0] == NULL)
		return ;
	if (st_a[0]->next == NULL)
		return ;
	if (stack_length(st_a[0]) == 2)
	{
		if (st_a[0]->nbr > st_a[0]->next->nbr)
			move_sa(st_a);
		return ;
	}
	if (stack_length(st_a[0]) == 3)
		sort_three(st_a);
	if (stack_length(st_a[0]) == 4)
		sort_four(st_a, st_b);
	if (stack_length(st_a[0]) == 5)
		sort_five(st_a, st_b);
}

void	sort_four(t_stack **st_a, t_stack **st_b)
{
	int	ind;

	ind = ft_max_ind(st_a[0]);
	if (st_a[0]->order == ind)
	{
		move_pb(st_a, st_b);
		sort_three(st_a);
		move_pa(st_a, st_b);
		move_ra(st_a);
		return ;
	}
	else if (ft_stacklast(st_a[0])->order == ind)
	{
		move_rra(st_a);
		move_pb(st_a, st_b);
		sort_three(st_a);
		move_pa(st_a, st_b);
		move_ra(st_a);
		return ;
	}
	else
	{
		move_ra(st_a);
		sort_four(st_a, st_b);
	}
}

void	sort_five(t_stack **st_a, t_stack **st_b)
{
	int	i1;
	int	i2 ;

	i1 = 5;
	i2 = 4;
	while (stack_length(st_b[0]) != 2)
	{
		if (ft_stacklast(st_a[0])->order == i1 || \
			ft_stacklast(st_a[0])->order == i2 || \
			st_a[0]->order == i1 || \
			st_a[0]->order == i2)
		{
			if (st_a[0]->order == i1 || st_a[0]->order == i2)
				move_pb(st_a, st_b);
			if (ft_stacklast(st_a[0])->order == i1 || \
				ft_stacklast(st_a[0])->order == i2)
			{
				move_rra(st_a);
				move_pb(st_a, st_b);
			}
		}
		else
			move_ra(st_a);
	}
	sort_three(st_a);
	get_back_from_b(st_a, st_b);
}

void	sort_three(t_stack **s)
{
	if (s[0]->nbr > s[0]->next->nbr && s[0]->nbr > s[0]->next->next->nbr)
	{
		if (s[0]->next->nbr > s[0]->next->next->nbr)
		{
			move_sa(s);
			move_rra(s);
		}
		else
			move_ra(s);
	}
	else if (s[0]->nbr > s[0]->next->nbr && s[0]->nbr < s[0]->next->next->nbr)
		move_sa(s);
	else if (s[0]->nbr < s[0]->next->nbr)
	{
		if (s[0]->nbr > s[0]->next->next->nbr)
			move_rra(s);
		else if (s[0]->nbr < s[0]->next->next->nbr)
		{
			if (s[0]->next->nbr > s[0]->next->next->nbr)
			{
				move_sa(s);
				move_ra(s);
			}
		}
	}
}
