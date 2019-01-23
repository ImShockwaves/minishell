/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:47:51 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/09 19:21:10 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	int		i;
	int		j;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] && count < len)
	{
		while (tofind[j] && count < len && str[i] == tofind[j])
		{
			i++;
			j++;
			count++;
		}
		if (!tofind[j])
			return ((char*)&(str[i - j]));
		else
		{
			i++;
			count = i;
		}
	}
	return (0);
}
