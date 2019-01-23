/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resizetab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:10:59 by ccharrie          #+#    #+#             */
/*   Updated: 2018/01/10 14:02:04 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_resizetab(char **tab, char *str)
{
	int		i;
	char	**res;

	i = 0;
	while (tab[i])
		i++;
	if (!(res = (char **)malloc(sizeof(char *) * i + 2)))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		res[i] = ft_strdup(tab[i]);
		i++;
	}
	res[i] = ft_strdup(str);
	i++;
	res[i] = 0;
	ft_del2dtab(tab);
	return (res);
}
