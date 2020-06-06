/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:23:03 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/06 02:18:30 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vec	mult_vec(t_vec a, float scalar)
{
	t_vec ret;

	ret.x = a.x * scalar;
	ret.y = a.y * scalar;
	return (ret);
}

t_vec2	mult_vec2(t_vec2 a, float scalar)
{
	t_vec2 ret;

	ret.x = a.x * scalar;
	ret.y = a.y * scalar;
	return (ret);
}
