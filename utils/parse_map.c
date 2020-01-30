/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:25:32 by bbellavi          #+#    #+#             */
/*   Updated: 2020/01/30 00:49:01 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_string.h"
#include "ft_stdio.h"
#include "ft_std.h"
#include "get_next_line.h"
#include <stdio.h>

static char *is_identifier(char *s)
{
    int index;

    index = 0;
    while (index < ID_SIZE)
    {
        if (ft_strncmp(s, identifiers[index], ft_strlen(identifiers[index])) == 0)
            return (identifiers[index]);
        index++;
    }
    return (NULL);
}

/* This function check if filename is valid by checking if it ends with .cub */

static int  is_valid_filename(const char *path)
{
    char    *ptr;
    size_t  size;
    
    size = ft_strlen(path);
    if (size > CUB_EXT_LENGTH)
    {
        ptr = (char*)&path[size - CUB_EXT_LENGTH];
        if (ft_strncmp(ptr, CUB_EXTENSION, CUB_EXT_LENGTH) == 0)
            return (TRUE);
    }
    return (FALSE);
}

size_t   array_length(char **str_arr)
{
    size_t length;

    length = 0;
    while (*str_arr != NULL)
    {
        length++;
        str_arr++;
    }
    return (length);
}

static void store_resolution_to_map(t_map *map, char *res)
{
    char **line;

    line = ft_split(res, ' ');
    if (array_length(line) == 3)
    {
        map->resolution->x = ft_atoi(line[1]);
        map->resolution->y = ft_atoi(line[2]);
    }
    else
    {
        ft_putstr("Error\n");
        ft_putstr(ERR_RESOLUTION);
        exit(1);
    }
}

static void store_to_map(t_map *map, char *identifier, char *s)
{
    (void)map;
    const size_t length = ft_strlen(identifier);
    
    if (ft_strncmp(identifier, RES, length) == 0)
        store_resolution_to_map(map, s);
}

void    parse_map(const char *path, t_map *map)
{
    int         fd;
    char        *line;
    char        *identifier;
    (void)map;

    line = NULL;
    if (is_valid_filename(path))
    {
        fd = open(path, O_RDONLY);
        get_next_line(fd, &line);
        if ((identifier = is_identifier(line)) != NULL)
            store_to_map(map, identifier, line);
    }
}
