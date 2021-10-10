/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonitor <gmonitor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:02:10 by gmonitor          #+#    #+#             */
/*   Updated: 2021/10/04 15:06:07 by gmonitor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	castling(int *arr, int i, int j)
{
	int	temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void	quick_sort(int arr[], int left, int right)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	if (left >= right)
		return ;
	pivot = left;
	i = left + 1;
	j = right;
	while (i <= j)
	{
		while (i <= right && arr[i] <= arr[pivot])
			i++;
		while (j > left && arr[j] >= arr[pivot])
			j--;
		if (i > j)
			castling(arr, pivot, j);
		else
			castling(arr, i, j);
	}
	quick_sort(arr, left, j - 1);
	quick_sort(arr, j + 1, right);
}
