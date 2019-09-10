/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:27:58 by brfeltz           #+#    #+#             */
/*   Updated: 2019/09/09 16:28:01 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_fdf.h"

void    zero_out(t_info *info)
{
    info->map = NULL;
    info->line_y = 0;
    info->line_x = 0;
    info->handle_y = 0;
    info->handle_x = 0;
    info->t_angle = 0;
    info->keys->key_1 = -.06;
    info->keys->key_2 = 0;
    info->map_points->center_x = 340;
    info->map_points->center_y = 1200 / 3.5;
    info->map_points->t_zoom = 10;
    info->map_points->x0 = 0;
    info->map_points->y0 = 0;
    info->map_points->z0 = 0;
    info->map_points->x1 = 0;
    info->map_points->y1 = 0;
    info->map_points->z1 = 0;
    info->map_points->dx = 0;
    info->map_points->dy = 0;
}
