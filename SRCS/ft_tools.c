/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:27:47 by brfeltz           #+#    #+#             */
/*   Updated: 2019/09/09 17:33:18 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_fdf.h"
#include <stdio.h> //////////////////remove

void    free_all(t_info *info)
{
    printf("free all\n");
    free(info->map_points->head);
    free(info->map_points);
    free(info->keys);
    free(info->mlx);
}

void	free_str(char **str)
{
    printf("free str\n");
    int i;

    i = 0;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

void	free_int(t_info *info, int **str)
{
    printf("free_int\n");
    while(info->handle_y)
    {
        free(str[info->handle_y]);
        info->handle_y--;
    }
    //free(str);
}