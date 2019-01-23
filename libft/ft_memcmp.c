/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:06:36 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/09 12:23:19 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				cpt;
	const unsigned char	*tmp;
	const unsigned char	*tmp2;

	cpt = 0;
	tmp = (const unsigned char *)s1;
	tmp2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (cpt < n)
	{
		if (tmp[cpt] != tmp2[cpt])
			return (tmp[cpt] - tmp2[cpt]);
		cpt++;
	}
	return (0);
}
