/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:36:54 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/07 19:15:15 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char *src, size_t nb)
{
	size_t	cpt;
	int		len;

	cpt = 0;
	len = 0;
	while (dest[len] != '\0')
	{
		len++;
	}
	while (src[cpt] != '\0' && cpt < nb)
	{
		dest[len + cpt] = src[cpt];
		cpt++;
	}
	dest[len + cpt] = '\0';
	return (dest);
}
