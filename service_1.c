/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonitor <gmonitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:00:36 by gmonitor          #+#    #+#             */
/*   Updated: 2021/10/13 17:44:57 by gmonitor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_str_digit(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str) && *str)
		str++;
	if (*str)
		return (0);
	else
		return (1);
}

void	find_zero_in_a(t_stack **st_b, t_stack **st_a, int radix)
{
	int	length;

	length = stack_length(st_a[0]);
	while (length--)
	{
		if (if_sort_stack(st_a[0]) == 1 && if_sort_stack_reversed(st_b[0]) == 1)
			return ;
		if (!(st_a[0]->order >> radix & 1))
			move_pb(st_a, st_b);
		else
			move_ra(st_a);
	}
}

void	find_one_in_b(t_stack **st_b, t_stack **st_a, int radix)
{
	int	length;

	length = stack_length(st_b[0]);
	while (length--)
	{
		if (if_sort_stack(st_a[0]) == 1 && if_sort_stack_reversed(st_b[0]) == 1)
			return ;
		if (!(st_b[0]->order >> radix & 1))
			move_rb(st_b);
		else
			move_pa(st_a, st_b);
	}
}

int	*check_and_parse(int argc, char **argv)
{
	int			ind;
	int			*not_sorted;
	long long	temp;

	not_sorted = malloc(sizeof(int) * (argc - 1));
	ind = 0;
	while (ind < argc - 1)
	{
		if (is_str_digit(argv[ind + 1]))
		{
			temp = ft_atoi(argv[ind + 1]);
			if (temp < -2147483648 || temp > 2147483647)
			{
				write(1, "Error", 5);
				exit(NOTINT);
			}
			not_sorted[ind++] = (int)temp;
		}
		else
		{
			write(1, "Error", 5);
			exit(NOTADIGIT);
		}
	}
	return (not_sorted);
}

int	find_ind(int *arr, int nbr, int size)
{
	int	res;

	res = 0;
	while (size--)
	{
		if (*arr == nbr)
			return (res);
		else
		{
			arr++;
			res++;
		}
	}
	return (-1);
}
