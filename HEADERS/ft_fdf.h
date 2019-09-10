/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:26:40 by brfeltz           #+#    #+#             */
/*   Updated: 2019/09/09 17:48:30 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF
# define FT_FDF
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

/*
** Macros
*/

# define INVALID(i) (i == '-' || i == '\n')
# define ipart(X) ((int)(X))
# define round(X) ((int)(((double)(X)) + 0.5))
# define fpart(X) (((double)(X)) - (double)ipart(X))
# define rfpart(X) (1.0 - fpart(X))

/*
** Structs
*/

typedef struct      s_head
{
    void *mlx_ptr;
    void *mlx_window;
}                   t_head;

typedef struct s_line_alg
{
    double dx;
    double dy;
    double gradient;
    double xend;
    double yend;
    double xgap;
    double intery;
    int px1;
    int py1;
    int px2;
    int py2;
    bool steep;
    double interx;
}              t_line_alg;

typedef struct      s_map_points
{
    t_line_alg *head;
    int     x0;
    int     y0;
    int     z0;
	int		x1;
	int     y1;
    int     z1;
    int     dx;
    int     dy;
    int     center_x;
    int     center_y;
    int     t_zoom;
}                   t_map_points;

typedef struct       s_keys
{
    double key_1;
    double key_2;
}                   t_keys;

typedef struct      s_info
{
    int             **map;
    t_head          *mlx;
    t_keys          *keys;
    t_map_points    *map_points;
    int             line_y;
    int             line_x;
    int             handle_x;
    int             handle_y;
    float           t_angle;
}                   t_info;

/*
** Functions
*/

int    ft_map_size_parse(int fd);
int    valid_file(char *str);
int    size2D(char **arr);
int    ft_plot_points(t_info *info);
int    key_mapping(int key_info, t_info *info);
int    ft_close(void *p);
void   handle_x(t_info *info, int x, int y);
void   handle_y(t_info *info, int x, int y);
void   handle_rotate_map(t_info *info);
void   handle_rotate_map2(t_info *info);
void   rotate_x(t_info *info);
void   rotate_y(t_info *info);
void   rotate_z(t_info *info);
void   draw_line(t_info *info);
void   r_one(t_info *info);
void   r_two(t_info *info);
void   r_three(t_info *info);
void   r_four(t_info *info);
void   ft_fdf(t_info *info);
void   key_management(t_info *info);
void   line_counter(int fd, t_info *info);
void   builder(t_info *info, int fd);
void   ft_isfile(char *str);
void   zero_out(t_info *info);
void   handle_errors(int argc);
void   free_all(t_info *info);
void   free_int(t_info *info, int **str);
void   free_str(char **str);


#endif
