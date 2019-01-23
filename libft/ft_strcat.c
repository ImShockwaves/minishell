/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:41:37 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/08 19:28:01 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *dest, const char *src)
{
	int cpt;
	int len;

	cpt = 0;
	len = 0;
	while (dest[len] != '\0')
	{
		len++;
	}
	while (src[cpt] != '\0')
	{
		dest[len + cpt] = src[cpt];
		cpt++;
	}
	dest[len + cpt] = '\0';
	return (dest);
}
