#include "push_swap.h"

void	move_sa_sb_ss(t_stack	**stack)
{
	t_stack *addr = stack[0]->next->next;
	t_stack *addr1 = stack[0]->next;
	stack[0]->next->next = *stack;
	stack[0]->next = addr;
	*stack = addr1;
}

void	move_pa(t_stack	**stack_a, t_stack	**stack_b)
{
	t_stack *addr = stack_b[0]->next;
	stack_b[0]->next = stack_a[0];
	stack_a[0] = stack_b[0];
	stack_b[0] = addr;
}

void	move_pb(t_stack	**stack_b, t_stack	**stack_a)
{
	t_stack *addr = stack_b[0]->next;
	stack_b[0]->next = stack_a[0];
	stack_a[0] = stack_b[0];
	stack_b[0] = addr;
}

void	move_rra_rrb_rrr(t_stack	**stack)
{
	if (stack[0] == NULL)
		return;
	t_stack *temp = stack[0];
	while(temp->next->next != NULL)
	{
		temp = temp->next;
	}
	temp->next->next = stack[0];
	stack[0] = temp->next;
	temp->next = NULL;
}

void	move_ra_rb_rr(t_stack	**stack)
{
	if (stack[0] == NULL)
		return;
	t_stack *temp = stack[0];
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = stack[0];
	stack[0] = stack[0]->next;
	temp->next->next = NULL;
}
