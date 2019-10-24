/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:29:18 by brfeltz           #+#    #+#             */
/*   Updated: 2019/09/09 20:17:43 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_fdf.h"

int		ft_plot_points(t_info *info)
{
	int x;
	int y;

	y = 0;
	mlx_clear_window(info->mlx->mlx_ptr, info->mlx->mlx_window);
	while (y < info->line_y)
	{
		x = 0;
		while (x < info->line_x)
		{
			if (y + 1 < (info->line_y))
				handle_y(info, x, y);
			if (x + 1 < (info->line_x))
				handle_x(info, x, y);
			++x;
		}
		++y;
	}
	return (0);
}

void	handle_x(t_info *info, int x, int y)
{
	info->map_points->x0 = x * info->map_points->t_zoom;
	info->map_points->x1 = (x + 1) * info->map_points->t_zoom;
	info->map_points->y0 = y * info->map_points->t_zoom;
	info->map_points->y1 = y * info->map_points->t_zoom;
	info->map_points->z0 = info->map[y][x] * info->map_points->t_zoom;
	info->map_points->z1 = info->map[y][x + 1] * info->map_points->t_zoom;
	handle_rotate_map(info);
	draw_line(info);
}

void	handle_y(t_info *info, int x, int y)
{
	info->map_points->x0 = x * info->map_points->t_zoom;
	info->map_points->x1 = x * info->map_points->t_zoom;
	info->map_points->y0 = y * info->map_points->t_zoom;
	info->map_points->y1 = (y + 1) * info->map_points->t_zoom;
	info->map_points->z0 = info->map[y][x] * info->map_points->t_zoom;
	info->map_points->z1 = info->map[y + 1][x] * info->map_points->t_zoom;
	handle_rotate_map(info);
	draw_line(info);
}

void	handle_rotate_map(t_info *info)
{
	info->map_points->x0 = ((info->map_points->x0 * cos(info->t_angle)) -
		(info->map_points->y0 * sin(info->t_angle)));
	info->map_points->y0 = ((info->map_points->x0 * sin(info->t_angle)) +
		(info->map_points->y0 * cos(info->t_angle)));
	info->map_points->x1 = ((info->map_points->x1 * cos(info->t_angle)) -
		(info->map_points->y1 * sin(info->t_angle)));
	info->map_points->y1 = ((info->map_points->x1 * sin(info->t_angle)) +
		(info->map_points->y1 * cos(info->t_angle)));
	handle_rotate_map2(info);
}

void	handle_rotate_map2(t_info *info)
{
	info->map_points->y0 = ((info->map_points->y0 * cos(info->keys->key_1)) +
		(info->map_points->z0 * sin(info->keys->key_1)));
	info->map_points->z0 = (((-1 * (info->map_points->y0 *
		sin(info->keys->key_1))) +
		(info->map_points->z0 * cos(info->keys->key_1))));
	info->map_points->y1 = ((info->map_points->y1 *
		cos(info->keys->key_1)) +
		(info->map_points->z1 * sin(info->keys->key_1)));
	info->map_points->z1 = (((-1 * (info->map_points->y1 *
		sin(info->keys->key_1))) +
		(info->map_points->z1 * cos(info->keys->key_1))));
	info->map_points->x0 = ((info->map_points->x0 *
		cos(info->keys->key_1)) +
		(info->map_points->z0 * sin(info->keys->key_1)));
	info->map_points->z0 = (((-1 * (info->map_points->x0 *
		sin(info->keys->key_1))) +
		(info->map_points->z0 * cos(info->keys->key_1))));
	info->map_points->x1 = ((info->map_points->x1 *
		cos(info->keys->key_1) +
		(info->map_points->z1 * sin(info->keys->key_1))));
	info->map_points->z1 = ((-1 * (info->map_points->x1 *
		sin(info->keys->key_1))) +
		(info->map_points->z1 * cos(info->keys->key_1)));
}
