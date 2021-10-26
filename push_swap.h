/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonitor <gmonitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:36:02 by gmonitor          #+#    #+#             */
/*   Updated: 2021/10/22 23:37:53 by gmonitor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include "libft/libft/libft.h"
# define NOARGS 1
# define DOUBLEARGS 2
# define NOTINT 3
# define NOTADIGIT 4

typedef struct s_stack
{
	int				nbr;
	int				order;
	struct s_stack	*next;
	int				flag;
}					t_stack;

void		move_sa(t_stack	**stack);
void		move_sb(t_stack	**stack);
void		move_pa(t_stack	**stack_a, t_stack	**stack_b);
void		move_pb(t_stack	**stack_b, t_stack	**stack_a);
void		move_rra(t_stack	**stack);
void		move_rrb(t_stack	**stack);
void		move_ra(t_stack	**stack);
void		move_rb(t_stack	**stack);

void		sort(t_stack **stack_a);
void		castling(int *arr, int i, int j);
void		quick_sort(int arr[], int left, int right);

int			is_str_digit(char *str);
void		find_zero_in_a(t_stack **st_b, t_stack **st_a, int radix);
void		find_one_in_b(t_stack **st_b, t_stack **st_a, int radix);
int			*check_and_parse(int argc, char **argv);
void		check_dup(int *sorted, int size);
int			find_ind(int *arr, int nbr, int size);

void		sort_five_and_less(t_stack **stack_a, t_stack **stack_b);
void		sort_four(t_stack **st_a, t_stack **st_b);
void		sort_three(t_stack **s);
void		sort_five(t_stack **st_a, t_stack **st_b);
void		get_back_from_b(t_stack **st_a, t_stack **st_b);

int			if_sort_stack(t_stack *stack);
int			if_sort_stack_reversed(t_stack *stack);
int			stack_length(t_stack *stack);
int			max_ind(t_stack *stack);
int			min_ind(t_stack *stack, int key);
void		down_sorted(t_stack **stack);
int			max_key(t_stack *stack);

void		stackclear(t_stack *stack);
void		stackadd_back(t_stack **stack, t_stack *new);
t_stack		**fillstack(int *srt, int *nsrt, int size);
t_stack		*stacklast(t_stack *stack);
t_stack		*stacknew(int nbr, int order);
void		stackprint(t_stack *stack);

#endif
