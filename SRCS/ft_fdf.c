#include "../HEADERS/ft_fdf.h"
#include <stdio.h> //// REMOVEEEEEEEEEEEEEEEEEEEEEEEEEEEE

void line_counter(int fd, t_info *info) 
{
    char *tmp;
    int ret;

    ret = 0;
    while (get_next_line(fd, &tmp)) 
        ret += 1;
    info->line_y = ret;
    close(fd);
}

void builder(t_info *info, int fd)
{
    char    *tmp;
    char    **nums;
    int     i;
    int     j;

    i = 0;
    while (get_next_line(fd, &tmp)) 
    {
        if(valid_file(tmp) == 0)
        {
            nums = ft_strinfolit(tmp, ' ');
            info->map[i] = (int*)malloc(sizeof(int) * size2D(nums) + 1);
            j = 0;
            while (nums[j]) 
            {
                info->map[i][j] = ft_atoi(nums[j]);
                j += 1; 
            }
            i += 1;
            info->line_x = size2D(nums);
            free(nums);
        }
        else
        {
            ft_putendl("invalid map file...");
            exit(1);
        }
    }
    close(fd);
}

void    handle_y(t_info *info, int x, int y)
{
    info->map_info->map_points->x = x * 10;
    info->map_info->map_points->sx = x * 10;
    info->map_info->map_points->y = x * 10;
    info->map_info->map_points->sy = x * 10;
    info->map_info->map_points->z = info->map[x][y];
    info->map_info->map_points->sz = info->map[x][y + 1];
    draw_line(info);
}

void    handle_x(t_info *info, int x, int y)
{
    info->map_info->map_points->x = x * 10;
    info->map_info->map_points->sx = x * 10;
    info->map_info->map_points->y = x * 10;
    info->map_info->map_points->sy = x * 10;
    info->map_info->map_points->z = info->map[x][y];
    info->map_info->map_points->sz = info->map[x + 1][y];
    draw_line(info);
}

void    ft_plot_ponts(t_info *info)
{
    int x;
    int y;

    x = -1;
    while (++x < info->line_x)
    {
        int y = -1;
        while (++y < info->line_y)
        {
            if (x + 1 < (info->line_x))
                handle_x(info, x, y);
            if (y + 1 < (info->line_y))
                handle_y(info, x, y);
        }
    }
}

void    ft_fdf(t_info *info)
{
    info->mlx = (t_head *)malloc(sizeof(t_head));
    info->mlx->mlx_ptr = mlx_init();
    info->mlx->mlx_window = mlx_new_window(info->mlx->mlx_ptr, 500, 500, "Brfeltz 42_FDF");
    mlx_loop_hook(info->mlx->mlx_ptr, ft_plot_points, info);

}

int         main(int argc, char **argv)
{
    t_info  *info;

    info = ft_memalloc(sizeof(t_info));
    info->map_info = ft_memalloc(sizeof(t_map));
    info->map_info->map_points = ft_memalloc(sizeof(t_map_points));
    zero_out(info);
    if (argc == 2)
    {
        ft_isfile(argv[1]);
        line_counter(open(argv[1], O_RDONLY), info);
        info->map = (int**)malloc(sizeof(int*) * (info->line_y + 1));
        builder(info, open(argv[1], O_RDONLY));
        ft_fdf(info);
    }
    else
        handle_errors(argc);
    return(0);
}