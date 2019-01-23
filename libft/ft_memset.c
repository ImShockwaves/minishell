/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:27:38 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/07 19:14:13 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int src, size_t len)
{
	char	*tmp;
	size_t	cpt;

	cpt = 0;
	tmp = (char *)dest;
	while (cpt < len)
	{
		tmp[cpt] = src;
		cpt++;
	}
	return (tmp);
}
