/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:17:05 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/09 12:19:43 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*dest;
	int		cpt;

	cpt = 0;
	if (!(dest = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (dest[cpt])
	{
		dest[cpt] = 0;
		cpt++;
	}
	return (dest);
}
