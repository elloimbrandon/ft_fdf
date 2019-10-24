/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:26:54 by brfeltz           #+#    #+#             */
/*   Updated: 2019/09/09 23:16:48 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_fdf.h"

int		size2d(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		i += 1;
	return (i);
}

void	line_counter(int fd, t_info *info)
{
	char	*tmp;
	int		ret;

	ret = 0;
	while (get_next_line(fd, &tmp) > 0)
	{
		ret += 1;
		free(tmp);
	}
	info->line_y = ret;
	close(fd);
}

int		ft_isfile(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len < 5)
	{
		ft_putendl("invalid file... ex. [filename].fdf");
		exit(1);
	}
	if (ft_strcmp(str + len - 4, ".fdf") != 0)
	{
		ft_putendl("invalid file... ex. [filename].fdf");
		exit(1);
	}
	return (1);
}

int		valid_file(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && INVALID(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	handle_errors(int argc)
{
	if (argc < 2)
	{
		ft_putendl("usage: ... ./ft_fdf [filename]");
		exit(1);
	}
}
