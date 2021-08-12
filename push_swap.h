#include <stdio.h>
#include <unistd.h>

#include "libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	int				order;
	struct s_stack	*next;
}					t_stack;

void	ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack	**ft_fillstack(int *sorted, int *not_sorted, int size);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stacknew(int nbr, int order);
void	ft_stackprint(t_stack *stack);

// 2.
