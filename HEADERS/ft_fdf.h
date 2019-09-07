#ifndef FT_FDF
# define FT_FDF
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

# define INVALID(i) (i == '-' || i == '\n')

/*
** Structs
*/

typedef struct      s_map_points
{
    int     x;
    int     y;
}                   t_map_points;

typedef struct      s_map
{
    int             width;
    int             height;
    int             m_count;
    t_map_points    *map_points;
}                   t_map;

typedef struct      s_info
{
    int         **map;
    int         lines;
    int         line_length;
    t_map       *map_info;
}                   t_info;

/*
** Functions
*/

int    ft_map_size_parse(int fd);
int    valid_file(char *str);
int    size2D(char **arr);
void   line_counter(int fd, t_info *info);
void   builder(t_info *info, int fd);
void   ft_isfile(char *str);
void   zero_out(t_info *info);
void   handle_errors(int argc);

#endif