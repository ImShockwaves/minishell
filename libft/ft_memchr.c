/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:52:47 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/09 18:05:16 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			cpt;
	unsigned char	*tmp;

	cpt = 0;
	tmp = (unsigned char *)s;
	while (cpt < n)
	{
		if (tmp[cpt] == (unsigned char)c)
			return (&(tmp[cpt]));
		cpt++;
	}
	return (NULL);
}
