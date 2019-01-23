/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:03:34 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/09 17:55:30 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		cpt++;
	}
	return (tmp);
}
