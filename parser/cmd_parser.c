/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 02:22:56 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/01 02:40:16 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	cmd_parse(t_game *data, const char *cmd)
{
	const size_t len = ft_strlen(CMD_SAVE);

	if (ft_strncmp(cmd, CMD_SAVE, len) == 0)
		data->save = TRUE;
	else
		data->save = FALSE;
}