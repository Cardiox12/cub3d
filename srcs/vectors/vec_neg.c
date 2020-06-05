/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_neg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:21:24 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 05:21:31 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vec	neg_vec(t_vec a)
{
	t_vec ret;

	ret.x = -a.x;
	ret.y = -a.y;
	return (ret);
}

t_vec2	neg_vec2(t_vec2 a)
{
	t_vec2 ret;

	ret.x = -a.x;
	ret.y = -a.y;
	return (ret);
}