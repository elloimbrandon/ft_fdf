/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:27:47 by brfeltz           #+#    #+#             */
/*   Updated: 2019/09/09 23:20:12 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_fdf.h"

void	free_all(t_info *info)
{
	free(info->map_points->head);
	free(info->map_points);
	free(info->keys);
	free(info->mlx);
	free(info);
}

void	free_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_int(t_info *info, int **str)
{
	while (info->handle_y)
	{
		free(str[info->handle_y]);
		info->handle_y--;
	}
	free(str);
}

void	help_r2(t_info *info, int x)
{
	while (x < info->map_points->head->px2)
	{
		mlx_pixel_put(info->mlx->mlx_ptr, info->mlx->mlx_window, x +
			info->map_points->center_x,
			IPART(info->map_points->head->intery) +
			info->map_points->center_y, 255);
		mlx_pixel_put(info->mlx->mlx_ptr, info->mlx->mlx_window, x +
			info->map_points->center_x,
			(IPART(info->map_points->head->intery) + 1) +
			info->map_points->center_y, 255);
		info->map_points->head->intery += info->map_points->head->gradient;
		x++;
	}
}

void	help_r4(t_info *info, int y)
{
	while (y < info->map_points->head->py2)
	{
		mlx_pixel_put(info->mlx->mlx_ptr, info->mlx->mlx_window,
			IPART(info->map_points->head->interx) +
			info->map_points->center_x, y + info->map_points->center_y, 255);
		mlx_pixel_put(info->mlx->mlx_ptr, info->mlx->mlx_window,
			(IPART(info->map_points->head->interx) + 1) +
			info->map_points->center_x, y +
			info->map_points->center_y, 255);
		info->map_points->head->interx += info->map_points->head->gradient;
		y++;
	}
}
