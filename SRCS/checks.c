#include "../HEADERS/ft_fdf.h"

int size2D(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
        i += 1;
    return (i);
}

void        ft_isfile(char *str)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(str);
    if (len < 5)
    {
        ft_putendl("invalid file... ex. [filename].fdf");
        exit(1);
    }
    if (!(ft_strcmp(str - 4, ".fdf")))
    {
        printf("len: %d\n", len);
        printf("string: %s\n", str);
        ft_putendl("invalid file... ex. [filename].fdf");
        exit(1);
    }
}

int    valid_file(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]) && INVALID(str[i]))
            return (1);
        i++;
    }
    return (0);

}
//void       handle_errors(int argc, t_info *info)
void       handle_errors(int argc)
{
    if (argc < 2)
    {
        ft_putendl("usage: Not enough arguments... ./fdf [filename]");
        exit(1);   
    }
    // invalid map error
    // map read error
    // mlx error
}