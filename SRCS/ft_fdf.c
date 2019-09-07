#include "../HEADERS/ft_fdf.h"
#include <stdio.h> //// REMOVEEEEEEEEEEEEEEEEEEEEEEEEEEEE

void line_counter(int fd, t_info *info) 
{
    char *tmp;
    int ret;

    ret = 0;
    while (get_next_line(fd, &tmp)) 
        ret += 1;
    info->lines = ret;
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
            nums = ft_strsplit(tmp, ' ');
            info->map[i] = (int*)malloc(sizeof(int) * size2D(nums) + 1);
            j = 0;
            while (nums[j]) 
            {
                info->map[i][j] = ft_atoi(nums[j]);
                j += 1; 
            }
            i += 1;
            info->line_length = size2D(nums);
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
        info->map = (int**)malloc(sizeof(int*) * (info->lines + 1));
        builder(info, open(argv[1], O_RDONLY));
    }
    else
        handle_errors(argc);
    return(0);
}