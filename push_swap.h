#include <stdio.h>
#include <unistd.h>

#include "libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	int				order;
	struct s_stack	*next;
	int				flag;
}					t_stack;

void	ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack	**ft_fillstack(int *sorted, int *not_sorted, int size);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stacknew(int nbr, int order);
void	ft_stackprint(t_stack *stack);
void	move_sa_sb_ss(t_stack	**stack);
void	move_pa(t_stack	**stack_a, t_stack	**stack_b);
void	move_rra_rrb_rrr(t_stack	**stack);
void	move_ra_rb_rr(t_stack	**stack);
void	move_pb(t_stack	**stack_b, t_stack	**stack_a);
int		if_sort_stack(t_stack *stack);
void	sort_three(t_stack **stack);
int		if_sort_stack_reverse(t_stack *stack);
int		stack_length(t_stack *stack);
int	ft_max_ind(t_stack *stack, int key);
int	ft_min_ind(t_stack *stack, int key);
// 2.
