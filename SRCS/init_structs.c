#include "../HEADERS/ft_fdf.h"

void    zero_out(t_info *info)
{
    info->map = NULL;
    info->line_y = 0;
    info->line_x = 0;
    info->map_info->height = 0;
    info->map_info->width = 0;
    info->map_info->map_points->x = 0;
    info->map_info->map_points->y = 0;
    info->map_info->map_points->z = 0;
    info->map_info->map_points->sx = 0;
    info->map_info->map_points->sy = 0;
    info->map_info->map_points->sz = 0;
}