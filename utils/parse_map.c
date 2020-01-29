/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 22:25:32 by bbellavi          #+#    #+#             */
/*   Updated: 2020/01/29 22:25:34 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_string.h"
#include "ft_stdio.h"
#include "get_next_line.h"

/* Creating array managmenet API */

// static char    *Append(char **dst, const char *src)
// {
//     char *old;

//     if (dst == NULL)
//         return (NULL);
//     old = *dst;
//     if (*dst != NULL)
//         *dst = ft_strndup(src, ft_strlen(src) + 1);
//     else
//     {
//         if ((*dst = ft_strjoin(*dst, src)) == NULL)
//             return (NULL);
//         free(old);
//     }
//     return (*dst);
// }

/*           end                 */
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

static int  is_valid_filename(const char *path)
{
    // The file is correct is the file end with cub
    char    *ptr;
    size_t  size;
    
    size = ft_strlen(path);
    if (size > 4)
    {
        ptr = (char*)&path[size - 1 - 4];
        if (ft_strncmp(ptr, ".cub", 4) == 0)
            return (1);
    }
    return (0);
}

#include <stdio.h>
void    parse_map(const char *path, t_map *map)
{
    (void)map;
    const int   fd = open(path, O_RDONLY);
    char        *line;
    char        *identifier;

    line = NULL;
    get_next_line(fd, &line);
    if (is_valid_filename(path))
    {
        printf("This is the correct filename\n");
        if (*line != 0)
        {
            if ((identifier = is_identifier(line)) != NULL)
                printf("IDENTIFIER : %s\n", identifier);
        }
    }
}
