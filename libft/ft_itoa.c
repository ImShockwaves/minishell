/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:58:37 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/09 17:36:24 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_spec(int n)
{
	char	*str;

	if (n == -2147483648)
	{
		if (!(str = ft_strnew(13)))
			return (NULL);
		return (ft_strcpy(str, "-2147483648"));
	}
	else
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		return (ft_strcpy(str, "0"));
	}
}

static int		cntdigit(int tmp)
{
	int	cpt;

	cpt = 0;
	while (tmp > 0)
	{
		cpt++;
		tmp = tmp / 10;
	}
	return (cpt);
}

static char		*ft_res(int n, char *str, int cpt, int sign)
{
	str[cpt] = '\0';
	while (n > 0)
	{
		str[cpt - sign - 1] = n % 10 + 48;
		n = n / 10;
		cpt--;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		cpt;
	int		sign;
	int		tmp;

	cpt = 0;
	sign = 0;
	tmp = 0;
	if (n == -2147483648 || n == 0)
		return (ft_spec(n));
	else if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	tmp = n;
	cpt = cntdigit(tmp);
	if (!(str = ft_strnew(cpt + 1)))
		return (NULL);
	str = ft_res(n, str, cpt, sign);
	return (str);
}
