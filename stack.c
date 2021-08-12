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
		printf("%d", stack->nbr);
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
				ft_stackadd_back(stack, ft_stacknew(not_sorted[ind_not_sorted], ind_sorted));
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

