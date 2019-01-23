/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:18:59 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/09 12:21:32 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			i;
	int			nb;
	int			neg;
	const char	*tmp;

	i = 0;
	nb = 0;
	neg = 1;
	tmp = str;
	while ((tmp[i] <= '\r' && tmp[i] >= '\t') || tmp[i] == ' ')
		i++;
	if (tmp[i] == '-' && (tmp[i + 1] >= '0' && tmp[i + 1] <= '9'))
		neg = -1;
	if (tmp[i] == '-' || tmp[i] == '+')
		i++;
	while (tmp[i] >= '0' && tmp[i] <= '9')
	{
		nb = nb * 10 + (tmp[i] - 48);
		i++;
	}
	return (nb * neg);
}
