#include "push_swap.h"

void	move_sa(t_stack	**stack)
{
	printf("sa\n");
	t_stack *addr = stack[0]->next->next;
	t_stack *addr1 = stack[0]->next;
	stack[0]->next->next = *stack;
	stack[0]->next = addr;
	*stack = addr1;
}

void	move_sb(t_stack	**stack)
{
	printf("sb\n");
	t_stack *addr = stack[0]->next->next;
	t_stack *addr1 = stack[0]->next;
	stack[0]->next->next = *stack;
	stack[0]->next = addr;
	*stack = addr1;
}

void	move_pa(t_stack	**stack_a, t_stack	**stack_b)
{
	printf("pa\n");
	t_stack *addr = stack_b[0]->next;
	stack_b[0]->next = stack_a[0];
	stack_a[0] = stack_b[0];
	stack_b[0] = addr;
}

void	move_pb(t_stack	**stack_b, t_stack	**stack_a)
{
	printf("pb\n");
	t_stack *addr = stack_b[0]->next;
	stack_b[0]->next = stack_a[0];
	stack_a[0] = stack_b[0];
	stack_b[0] = addr;
}

void	move_rra(t_stack	**stack)
{
	printf("rra\n");
	if (stack[0] == NULL)
		return;
	t_stack *temp = stack[0];
	while(temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = stack[0];
	stack[0] = temp->next;
	temp->next = NULL;
}

void	move_rrb(t_stack	**stack)
{
	printf("rrb\n");
	if (stack[0] == NULL)
		return;
	t_stack *temp = stack[0];
	while(temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = stack[0];
	stack[0] = temp->next;
	temp->next = NULL;
}

void	move_ra(t_stack	**stack)
{
	printf("ra\n");
	if (stack[0] == NULL)
		return;
	t_stack *temp = stack[0];
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = stack[0];
	stack[0] = stack[0]->next;
	temp->next->next = NULL;
}

void	move_rb(t_stack	**stack)
{
	printf("rb\n");
	if (stack[0] == NULL)
		return;
	t_stack *temp = stack[0];
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = stack[0];
	stack[0] = stack[0]->next;
	temp->next->next = NULL;
}

