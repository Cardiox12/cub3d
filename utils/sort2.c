/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 22:29:07 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/26 21:16:07 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	swap(double *a, double *b)
{
	double tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(double *arr, int low, int high)
{
	t_vec	i;
	int		pivot;

	pivot = arr[high];
	i.x = (low - 1);
	i.y = low;
	while (i.y <= high - 1)
	{
		if (arr[i.y] > pivot)
		{
			i.x++;
			swap(&arr[i.x], &arr[i.y]);
		}
		i.y++;
	}
	swap(&arr[i.x + 1], &arr[high]);
	return (i.x + 1);
}

static void	quicksort(double *arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

void	sort_double(double *arr, int size)
{
	quicksort(arr, 0, size - 1);
}