/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:03:35 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/09 20:21:42 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	cpt;

	cpt = 0;
	if (s && f)
	{
		while (s[cpt])
		{
			(*f)(cpt, &s[cpt]);
			cpt++;
		}
	}
}
