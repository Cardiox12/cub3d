/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:21:50 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 05:21:56 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vec	add_vec(t_vec a, t_vec b)
{
	t_vec ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	return (ret);
}

t_vec2	add_vec2(t_vec2 a, t_vec2 b)
{
	t_vec2 ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	return (ret);
}