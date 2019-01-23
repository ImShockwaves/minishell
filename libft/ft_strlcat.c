/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:33:18 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/10 10:22:52 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t nb)
{
	size_t	cpt;
	size_t	len;

	cpt = 0;
	if (nb == 0)
		return ((size_t)ft_strlen(dest));
	while (dest[cpt] && cpt < nb)
		cpt++;
	len = cpt;
	while (src[cpt - len] && cpt < nb - 1)
	{
		dest[cpt] = src[cpt - len];
		cpt++;
	}
	if (len < nb)
		dest[cpt] = '\0';
	return (len + ft_strlen(src));
}
