/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:30:43 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/08 14:51:56 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	cpt;
	char	tmp[n];
	char	*tmp2;
	char	*tmp3;

	cpt = 0;
	tmp3 = (char *)src;
	tmp2 = (char *)dst;
	if (n > 100000000)
		return (0);
	while (cpt < n)
	{
		tmp[cpt] = tmp3[cpt];
		cpt++;
	}
	cpt = 0;
	while (cpt < n)
	{
		tmp2[cpt] = tmp[cpt];
		cpt++;
	}
	return (tmp2);
}
