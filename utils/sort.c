/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 22:25:42 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/27 02:09:48 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	swap(t_pair *a, t_pair *b)
{
	t_pair tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(t_pair *pairs, int low, int high)
{
	t_vec	i;
	int		pivot;

	pivot = pairs[high].val;
	i.x = (low - 1);
	i.y = low;
	while (i.y <= high - 1)
	{
		if (pairs[i.y].val > pivot)
		{
			i.x++;
			swap(&pairs[i.x], &pairs[i.y]);
		}
		i.y++;
	}
	swap(&pairs[i.x + 1], &pairs[high]);
	return (i.x + 1);
}

static void	quicksort(t_pair *pairs, int low, int high)
{
	if (low < high)
	{
		int pi = partition(pairs, low, high);

		quicksort(pairs, low, pi - 1);
		quicksort(pairs, pi + 1, high);
	}
}

void	sort_pairs(t_pair *pairs, int size)
{
	quicksort(pairs, 0, size - 1);
}