/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:27:16 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/08 18:53:48 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	cpt;

	cpt = 0;
	if (!(dest = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (!(s))
		return (0);
	while (len != 0)
	{
		dest[cpt] = s[start + cpt];
		cpt++;
		len--;
	}
	dest[cpt] = '\0';
	return (dest);
}
