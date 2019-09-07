#include "../HEADERS/ft_fdf.h"

void    zero_out(t_info *info)
{
    info->map = NULL;
    info->map_info->height = 0;
    info->map_info->width = 0;
    info->map_info->m_count = 0;
    info->map_info->map_points->x = 0;
    info->map_info->map_points->y = 0;
}