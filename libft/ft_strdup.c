/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brandonf <brfeltz@student.42.us.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 22:58:22 by brfeltz           #+#    #+#             */
/*   Updated: 2019/08/28 20:22:08 by brandonf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*s2;

	s2 = ft_strnew(ft_strlen(src));
	if (s2)
		return (ft_strcpy(s2, (char*)src));
	return (NULL);
}
