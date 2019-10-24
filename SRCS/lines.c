/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:29:07 by brfeltz           #+#    #+#             */
/*   Updated: 2019/09/09 21:24:38 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_fdf.h"

void	draw_line(t_info *info)
{
	info->map_points->head->dx = (double)info->map_points->x1 -
		(double)info->map_points->x0;
	info->map_points->head->dy = (double)info->map_points->y1 -
		(double)info->map_points->y0;
	if (fabs(info->map_points->head->dx) > fabs(info->map_points->head->dy))
	{
		r_one(info);
		r_two(info);
	}
	else
	{
		r_three(info);
		r_four(info);
	}
}

void	r_one(t_info *info)
{
	if (info->map_points->x1 < info->map_points->x0)
	{
		ft_swap(&info->map_points->x0, &info->map_points->x1);
		ft_swap(&info->map_points->y0, &info->map_points->y1);
	}
	info->map_points->head->gradient = info->map_points->head->dy /
		info->map_points->head->dx;
	info->map_points->head->xend = ROUND(info->map_points->x0);
	info->map_points->head->yend = info->map_points->y0 +
		info->map_points->head->gradient *
		(info->map_points->head->xend - info->map_points->x0);
	info->map_points->head->xgap = RFPART(info->map_points->x0 + 0.5);
	info->map_points->head->px1 = info->map_points->head->xend;
	info->map_points->head->py1 = IPART(info->map_points->head->yend);
	mlx_pixel_put(info->mlx->mlx_ptr, info->mlx->mlx_window,
		info->map_points->head->px1 +
		info->map_points->center_x, info->map_points->head->py1 +
		info->map_points->center_y, 255);
	mlx_pixel_put(info->mlx->mlx_ptr, info->mlx->mlx_window,
	info->map_points->head->px1 +
	info->map_points->center_x, (info->map_points->head->py1 + 1) +
	info->map_points->center_y, 255);
	info->map_points->head->intery = info->map_points->head->yend +
	info->map_points->head->gradient;
}

void	r_two(t_info *info)
{
	int x;

	info->map_points->head->xend = ROUND(info->map_points->x1);
	info->map_points->head->yend = info->map_points->y1 +
		info->map_points->head->gradient *
		(info->map_points->head->xend - info->map_points->x1);
	info->map_points->head->xgap = FPART(info->map_points->x1 + 0.5);
	info->map_points->head->px2 = info->map_points->head->xend;
	info->map_points->head->py2 = IPART(info->map_points->head->yend);
	mlx_pixel_put(info->mlx->mlx_ptr,
		info->mlx->mlx_window, info->map_points->head->px2 +
		info->map_points->center_x, info->map_points->head->py2 +
		info->map_points->center_y, 255);
	mlx_pixel_put(info->mlx->mlx_ptr, info->mlx->mlx_window,
		info->map_points->head->px2 +
		info->map_points->center_x, (info->map_points->head->py2 + 1) +
		info->map_points->center_y, 255);
	x = info->map_points->head->px1;
	help_r2(info, x);
}

void	r_three(t_info *info)
{
	if (info->map_points->y1 < info->map_points->y0)
	{
		ft_swap(&info->map_points->x0, &info->map_points->x1);
		ft_swap(&info->map_points->y0, &info->map_points->y1);
	}
	info->map_points->head->gradient = info->map_points->head->dx /
		info->map_points->head->dy;
	info->map_points->head->yend = ROUND(info->map_points->y0);
	info->map_points->head->xend = info->map_points->x0 +
		info->map_points->head->gradient *
		(info->map_points->head->yend - info->map_points->y0);
	info->map_points->head->xgap = RFPART(info->map_points->y0 + 0.5);
	info->map_points->head->py1 = info->map_points->head->yend;
	info->map_points->head->px1 = IPART(info->map_points->head->xend);
	mlx_pixel_put(info->mlx->mlx_ptr, info->mlx->mlx_window,
		info->map_points->head->px1 +
		info->map_points->center_x, info->map_points->head->py1 +
		info->map_points->center_y, 255);
	mlx_pixel_put(info->mlx->mlx_ptr, info->mlx->mlx_window,
	(info->map_points->head->px1 + 1) +
	info->map_points->center_x, info->map_points->head->py1 +
	info->map_points->center_y, 255);
	info->map_points->head->interx = info->map_points->head->xend +
	info->map_points->head->gradient;
}

void	r_four(t_info *info)
{
	int y;

	info->map_points->head->yend = ROUND(info->map_points->y1);
	info->map_points->head->xend = info->map_points->x1 +
		info->map_points->head->gradient *
		(info->map_points->head->yend - info->map_points->y1);
	info->map_points->head->xgap = FPART(info->map_points->y1 + 0.5);
	info->map_points->head->py2 = info->map_points->head->yend;
	info->map_points->head->px2 = IPART(info->map_points->head->xend);
	mlx_pixel_put(info->mlx->mlx_ptr,
		info->mlx->mlx_window, info->map_points->head->px2 +
		info->map_points->center_x, info->map_points->head->py2 +
		info->map_points->center_y, 255);
	mlx_pixel_put(info->mlx->mlx_ptr, info->mlx->mlx_window,
	(info->map_points->head->px2 + 1) +
	info->map_points->center_x, info->map_points->head->py2 +
	info->map_points->center_y, 255);
	y = info->map_points->head->py1;
	help_r4(info, y);
}
