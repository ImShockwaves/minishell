/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:09:13 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/09 14:48:35 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	char			*tmp;
	unsigned int	cpt;

	tmp = (char *)s;
	cpt = 0;
	if (!(s))
		return (0);
	if (!(dest = (char *)malloc(sizeof(char) * ft_strlen(tmp) + 1)))
		return (0);
	while (s[cpt])
	{
		dest[cpt] = (*f)(cpt, tmp[cpt]);
		cpt++;
	}
	dest[cpt] = '\0';
	return (dest);
}
