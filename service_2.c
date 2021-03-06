/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonitor <gmonitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:00:41 by gmonitor          #+#    #+#             */
/*   Updated: 2021/10/13 17:52:21 by gmonitor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup(int *sorted, int size)
{
	int	check_dup;

	check_dup = 0;
	while (size--)
	{
		if (check_dup == *sorted)
		{
			write(1, "Error", 5);
			exit(DOUBLEARGS);
		}
		check_dup = *sorted;
		sorted++;
	}
}
