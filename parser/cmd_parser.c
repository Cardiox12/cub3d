/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 02:22:56 by bbellavi          #+#    #+#             */
/*   Updated: 2020/06/03 04:22:17 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	cmd_parse(t_game *data, const char *cmd)
{
	const size_t len = ft_strlen(CMD_SAVE);

	if (ft_strncmp(cmd, CMD_SAVE, len) == 0)
	{
		data->save = TRUE;
		return (RET_NO_ERROR);
	}
	return (CODE_ERR_INVALID_OPT);
}