/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:48:31 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/09 21:54:54 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrbase(int n, char *base)
{
	size_t	len;

	len = (size_t)ft_strlen(base);
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if ((size_t)n >= len)
	{
		ft_putnbrbase(n / len, base);
		ft_putchar(base[n]);
	}
	if ((size_t)n < len)
		ft_putchar(base[n]);
}
