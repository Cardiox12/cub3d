/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 01:53:16 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/05 22:57:40 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_texture	*get_index(t_game *data, const char *id)
{
	t_texture *ret;

	ret = NULL;
	if (ft_strncmp(id, ID_NORTH, ft_strlen(ID_NORTH)) == 0)
		ret = &data->map.textures[IDX_NORTH];
	else if (ft_strncmp(id, ID_SOUTH, ft_strlen(ID_SOUTH)) == 0)
		ret = &data->map.textures[IDX_SOUTH];
	else if (ft_strncmp(id, ID_WEST, ft_strlen(ID_WEST)) == 0)
		ret = &data->map.textures[IDX_WEST];
	else if (ft_strncmp(id, ID_EAST, ft_strlen(ID_EAST)) == 0)
		ret = &data->map.textures[IDX_EAST];
	else if (ft_strncmp(id, ID_SPRITE, ft_strlen(ID_SPRITE)) == 0)
		ret = &data->map.textures[IDX_SPRITE];
	return (ret);
}

int					parse_texture(t_game *data, const char *id, char *line)
{
	const size_t	id_len = ft_strlen(id);
	size_t			path_len;
	t_texture		*texture;

	line = skip_spaces(&line[id_len]);
	if (*line == '\0')
		return (CODE_ERR_TEXTURE_PATH_MISSING);
	path_len = ft_strlen_to_sep(line, SPACE);
	if (path_len == 0)
		return (CODE_ERR_TEXTURE_PATH_MISSING);
	texture = get_index(data, id);
	ft_memset(texture->path, 0, PATH_MAX);
	ft_memcpy(texture->path, line, path_len);
	return (RET_NO_ERROR);
}
