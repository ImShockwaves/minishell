/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:37:59 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/09 19:24:00 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*tmp;
	char	*tmp2;

	tmp = (char *)s1;
	tmp2 = (char *)s2;
	if (n == 0)
		return (0);
	while ((*tmp && *tmp2) && *tmp == *tmp2 && n - 1 > 0)
	{
		tmp++;
		tmp2++;
		n--;
	}
	return ((unsigned char)*tmp - (unsigned char)*tmp2);
}
