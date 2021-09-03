#include <stdio.h>
#include <unistd.h>

#include "libft/libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	int				order;
	struct s_stack	*next;
	int				flag;
}					t_stack;

void		ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack		**ft_fillstack(int *sort, int *nsort, int size);
t_stack		*ft_stacklast(t_stack *stack);
t_stack		*ft_stacknew(int nbr, int order);
void		ft_stackprint(t_stack *stack);
void		move_sa(t_stack	**stack);
void		move_sb(t_stack	**stack);
void		move_pa(t_stack	**stack_a, t_stack	**stack_b);
void		move_rra(t_stack	**stack);
void		move_rrb(t_stack	**stack);
void		move_ra(t_stack	**stack);
void		move_rb(t_stack	**stack);
void		move_pb(t_stack	**stack_b, t_stack	**stack_a);
int			if_sort_stack(t_stack *stack);
int			if_sort_stack_reversed(t_stack *stack);
int			stack_length(t_stack *stack);
int			ft_max_ind(t_stack *stack);
int			ft_min_ind(t_stack *stack, int key);
void		ft_down_sorted(t_stack **stack);
int			ft_max_key(t_stack *stack);
void		sort_five_and_less(t_stack **stack_a, t_stack **stack_b);
void		sort_four(t_stack **st_a, t_stack **st_b);
void		sort_three(t_stack **s);
void		sort_five(t_stack **st_a, t_stack **st_b);
int			is_str_digit(char *str);
void		ft_stackclear(t_stack *stack);
void		find_zero_in_a(t_stack **stack_b, t_stack **stack_a, int radix);
void		find_one_in_b(t_stack **stack_b, t_stack **stack_a, int radix);
int			*ft_check_and_parse(int argc, char **argv);
int			find_ind(int	*arr, int	nbr);
void		get_back_from_b(t_stack **st_a, t_stack **st_b);


// 2.
