/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:47:51 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/09 14:55:29 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		cpt;
	int		i;
	int		i2;

	i = 0;
	cpt = 0;
	if (to_find[i] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		i2 = i;
		while (to_find[cpt] == str[i])
		{
			if (to_find[cpt + 1] == 0)
			{
				return ((char *)&str[i2]);
			}
			i++;
			cpt++;
		}
		cpt = 0;
		i = i2 + 1;
	}
	return (0);
}
