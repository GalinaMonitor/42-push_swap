/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonitor <gmonitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:00:41 by gmonitor          #+#    #+#             */
/*   Updated: 2021/10/10 14:49:20 by gmonitor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup(int *sorted)
{
	int	check_dup;

	check_dup = *sorted;
	while (*sorted)
	{
		sorted++;
		if (check_dup == *sorted)
		{
			write(1, "Error", 5);
			exit(1);
		}
		check_dup = *sorted;
	}
}
