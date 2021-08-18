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
	int biggest;
	int order;

	biggest = stack->nbr;
	order = stack->order;
	if (stack->next == NULL)
		return 0;
	while(stack->next != NULL)
	{
		stack = stack->next;
		if (stack->nbr > biggest && stack->order == order + 1)
		{
			biggest = stack->nbr;
			order+=1;
		}
		else
			return 0;
		// printf("%d", stack->order);
	}
	return 1;
}


// void	ft_stackclear(t_stack **stack, void (*del)(void*))
// {
// 	if (*stack != NULL)
// 	{
// 		ft_stackclear(&(*stack)->next, del);
// 		ft_stackdelone(*stack, del);
// 		*stack = NULL;
// 	}
// }

// void	ft_stackdelone(t_stack *stack, void (*del)(void*))
// {
// 	if (stack != NULL && del != NULL)
// 		del(stack->nbr);
// 	free(stack);
// }

void	ft_stackprint(t_stack *stack)
{
	if (stack != NULL)
	{
		printf("\nnbr = %d ", stack->nbr);
		printf(" order = %d", stack->order);
		printf(" flag = %d", stack->flag);
		if (stack->next)
			return (ft_stackprint(stack->next));
	}
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (stack != NULL)
		if (stack->next)
			return (ft_stacklast(stack->next));
	return (stack);
}

// t_stack	*ft_stackmap(t_stack *stack, void *(*f)(void *), void (*del)(void *))
// {
// 	t_stack	*elem;
// 	t_stack	*new_stack;

// 	new_stack = NULL;
// 	while (stack != NULL)
// 	{
// 		elem = ft_stacknew(f(stack->nbr));
// 		if (elem == NULL)
// 		{
// 			ft_stackclear(&new_stack, del);
// 			return (NULL);
// 		}
// 		ft_stackadd_back(&new_stack, elem);
// 		stack = stack->next;
// 	}
// 	return (new_stack);
// }

t_stack **ft_fillstack(int *sorted, int *not_sorted, int size)
{
	t_stack **stack = malloc(sizeof(t_stack *));
	*stack = NULL;
	int ind_sorted = 0;
	int ind_not_sorted = 0;
	int temp_size = size;
	int temp_size2 = size;

	while (temp_size-- > 0)
	{
		while (temp_size2-- > 0)
		{
			if (not_sorted[ind_not_sorted] == sorted[ind_sorted])
			{
				ft_stackadd_back(stack, ft_stacknew(not_sorted[ind_not_sorted], ind_sorted + 1));
				break;
			}
			ind_sorted++;
		}
		ind_not_sorted++;
		ind_sorted = 0;
		temp_size2 = size;
	}
	return stack;
}

t_stack	*ft_stacknew(int nbr, int order)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->nbr = nbr;
	stack->order = order;
	stack->next = NULL;
	stack->flag = 0;
	return (stack);
}

// int	ft_stacksize(t_stack *stack)
// {
// 	if (stack != NULL)
// 	{
// 		if (stack->next)
// 		{
// 			return (ft_stacksize(stack->next) + 1);
// 		}
// 		return (1);
// 	}
// 	return (0);
// }

int	stack_length(t_stack *stack)
{
	if (stack == NULL)
		return 0;
	if (stack->next == NULL)
		return 1;
	return (1 + stack_length(stack->next));
}

int	ft_max_ind(t_stack *stack, int key)
{
	int max_ind = 0;

	if (stack == NULL)
		return 0;
	while (stack != NULL)
	{
		if (max_ind < stack->order && stack->flag == key)
			max_ind = stack->order;
		stack = stack->next;
	}
	return max_ind;
}

int	ft_min_ind(t_stack *stack, int key)
{
	int max_ind = stack->order;

	if (stack == NULL)
		return 0;
	while (stack != NULL)
	{
		if (max_ind > stack->order && stack->flag == key)
			max_ind = stack->order;
		stack = stack->next;
	}
	return max_ind;
}

void	ft_down_sorted(t_stack **stack)
{
	t_stack *last;
	t_stack *check;
	int flag = 0;
	if (stack[0] == 0)
		return;
	check = stack[0];
	while (check != NULL)
	{
		if (check->flag == -1)
			flag = 1;
		check = check->next;
	}
	last = ft_stacklast(stack[0]);
	if (last->flag != -1 && flag == 1)
	{
		move_rra_rrb_rrr(stack);
		ft_down_sorted(stack);
	}
	else
		return;
}

int	ft_max_key(t_stack *stack)
{
	int key = 0;

	if (stack == NULL)
		return 0;
	while (stack != NULL)
	{
		if (key < stack->flag)
			key = stack->flag;
		stack = stack->next;
	}
	return key;
}
