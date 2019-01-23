/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:48:38 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/09 17:26:10 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		occ;
	int		cpt;

	cpt = 0;
	occ = -1;
	tmp = (char *)s;
	while (tmp[cpt])
	{
		if (tmp[cpt] == c)
			occ = cpt;
		cpt++;
	}
	if (tmp[cpt] == '\0' && c == '\0')
		occ = cpt;
	if (occ == -1)
		return (NULL);
	return (tmp + occ);
}
