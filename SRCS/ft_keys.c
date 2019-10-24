/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:27:27 by brfeltz           #+#    #+#             */
/*   Updated: 2019/09/09 20:48:28 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_fdf.h"

int		key_mapping(int key_info, t_info *info)
{
	if (key_info == 126)
		info->keys->key_1 += 0.2;
	if (key_info == 125)
		info->keys->key_1 -= 0.2;
	if (key_info == 123)
		info->keys->key_2 += 0.1;
	if (key_info == 124)
		info->keys->key_2 -= 0.1;
	if (key_info == 0)
		info->map_points->center_x -= 20;
	if (key_info == 13)
		info->map_points->center_y += 20;
	if (key_info == 2)
		info->map_points->center_x += 20;
	if (key_info == 1)
		info->map_points->center_y -= 20;
	key_mapping2(key_info, info);
	return (0);
}

void	key_mapping2(int key_info, t_info *info)
{
	if (key_info == 24)
		info->map_points->t_zoom += 5;
	if (key_info == 27)
		info->map_points->t_zoom -= 5;
	if (key_info == 18)
		info->t_angle += .1;
	if (key_info == 19)
		info->t_angle -= .1;
	if (key_info == 53)
		exit(0);
}

int		ft_close(void *p)
{
	(void)p;
	exit(0);
}

void	key_management(t_info *info)
{
	mlx_hook(info->mlx->mlx_window, 2, 0, key_mapping, info);
	mlx_hook(info->mlx->mlx_window, 17, 0, ft_close, info);
}
