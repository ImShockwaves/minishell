/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:17:23 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/08 14:45:16 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	cpt;
	char	*tmp;
	char	*tmp2;

	cpt = 0;
	tmp = (char *)dst;
	tmp2 = (char *)src;
	while (cpt < n)
	{
		tmp[cpt] = tmp2[cpt];
		if (tmp2[cpt] == c)
			return (&tmp[cpt + 1]);
		cpt++;
	}
	return (NULL);
}
