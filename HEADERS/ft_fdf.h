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
# define MIN_WIDTH 1000;
# define MIN_HEIGHT 600;

/*
** Structs
*/

typedef struct      s_head
{
    void *mlx_ptr;
    void *mlx_window;
}                   t_head;

typedef struct      s_map_points
{
    int     x;
    int     y;
    int     z;
	int		sx;
	int     sy;
    int     sz;
}                   t_map_points;

typedef struct      s_map
{
    int             width;
    int             height;
    t_map_points    *map_points;
}                   t_map;

typedef struct      s_info
{
    int         **map;
    int         line_y;
    int         line_x;
    t_head      *mlx;
    t_map       *map_info;
}                   t_info;

/*
** Functions
*/

int    ft_map_size_parse(int fd);
int    valid_file(char *str);
int    size2D(char **arr);
int   ft_plot_points(t_info *info);
void   handle_x(t_info *info, int x, int y);
void   handle_y(t_info *info, int x, int y);
void   ft_fdf(t_info *info);
void   line_counter(int fd, t_info *info);
void   builder(t_info *info, int fd);
void   ft_isfile(char *str);
void   zero_out(t_info *info);
void   handle_errors(int argc);

#endif