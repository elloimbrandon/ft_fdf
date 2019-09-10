/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:27:10 by brfeltz           #+#    #+#             */
/*   Updated: 2019/09/09 17:52:44 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_fdf.h"

void	builder(t_info *info, int fd)
{
	char	*tmp;
	char	**nums;
	int		i;
	int		j;

	i = 0;
	while (get_next_line(fd, &tmp)) 
	{
		if(valid_file(tmp) == 0)
		{
			nums = ft_strsplit(tmp, ' ');
			info->map[i] = ft_memalloc(sizeof(int) * (size2D(nums) + 1) * sizeof(info->map));
			j = 0;
			while (nums[j]) 
			{
				info->map[i][j] = ft_atoi(nums[j]);
				j += 1; 
			}
			i += 1;
			info->line_x = size2D(nums);
			free_str(nums);
			free(tmp);
		}
		else
		{
			ft_putendl("invalid map file...");
			exit(1);
		}
	}
	close(fd);  
}
#include <stdio.h> ////////////////////////SEX
void	ft_fdf(t_info *info)
{
	info->mlx = (t_head *)malloc(sizeof(t_head));
	info->mlx->mlx_ptr = mlx_init();
	info->mlx->mlx_window = mlx_new_window(info->mlx->mlx_ptr, 1000, 1000, "Brfeltz 42_FDF");
	key_management(info);
	mlx_loop_hook(info->mlx->mlx_ptr, ft_plot_points, info);
	mlx_loop(info->mlx);
}

int		main(int argc, char **argv)
{
	t_info	*info;

	info = ft_memalloc(sizeof(t_info));
	info->keys = ft_memalloc(sizeof(t_keys));
	info->map_points = ft_memalloc(sizeof(t_map_points));
	info->map_points->head = ft_memalloc(sizeof(t_line_alg));
	zero_out(info);
	if (argc == 2)
	{
		ft_isfile(argv[1]);
		line_counter(open(argv[1], O_RDONLY), info);
		info->map = ft_memalloc(sizeof(int*) * (info->line_y + 1) * sizeof(info->map));
		builder(info, open(argv[1], O_RDONLY));
		ft_fdf(info);
	}
	else
	{
		handle_errors(argc);
		//free_all(info);
	}
	while(1);
	return(0);
}
