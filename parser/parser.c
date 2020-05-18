/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 17:39:44 by bbellavi          #+#    #+#             */
/*   Updated: 2020/05/18 18:42:25 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
	Algorithme :

	- SI le nom de la map a une extension valide :
		- POUR TOUT ligne DE fichier :
			- SI ligne commence par identifier :
				- get identifier type 
				- appeler la fonction appropriee en fonction du type de l'id (tableau de pointeurs sur fonction)
*/

int		has_valid_ext(const char *path)
{
	const size_t len = ft_strlen(path);
	const size_t ext_len = ft_strlen(MAP_EXT);

	if (len < 5)
		return (FALSE);
	if (ft_strncmp(&path[len - ext_len], MAP_EXT, ext_len) != 0)
		return (FALSE);
	return (TRUE);
}

int		parse(t_game *data, const char *path)
{
	(void)data;
	if (has_valid_ext(path) == FALSE)
		return (FALSE);
	return (TRUE);
}