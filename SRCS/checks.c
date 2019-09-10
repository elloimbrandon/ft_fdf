/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:26:54 by brfeltz           #+#    #+#             */
/*   Updated: 2019/09/09 16:27:01 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_fdf.h"

int size2D(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
        i += 1;
    return (i);
}

void line_counter(int fd, t_info *info) 
{
    char *tmp;
    int ret;

    ret = 0;
    while (get_next_line(fd, &tmp)) 
        ret += 1;
    info->line_y = ret;
    free(tmp);
    close(fd);
}

void        ft_isfile(char *str)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(str);
    if (len < 5)
    {
        ft_putendl("invalid file... ex. [filename].fdf");
        exit(1);
    }
    if (!(ft_strcmp(str - 4, ".fdf")))
    {
        printf("len: %d\n", len);
        printf("string: %s\n", str);
        ft_putendl("invalid file... ex. [filename].fdf");
        exit(1);
    }
}

int    valid_file(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]) && INVALID(str[i]))
            return (1);
        i++;
    }
    return (0);

}

void       handle_errors(int argc)
{
    if (argc < 2)
    {
        ft_putendl("usage: ... ./ft_fdf [filename]");
        exit(1);   
    }
}
