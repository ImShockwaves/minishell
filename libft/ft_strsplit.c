/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:07:56 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/10 10:17:22 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cntwrds(const char *s, char c)
{
	size_t	res;
	int		i;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			res++;
			while (s[i + 1] && s[i] != c)
				i++;
		}
		i++;
	}
	return (res);
}

static char		**ft_split(char **splited, const char *str, char c, size_t nb)
{
	size_t	cpt;
	size_t	start;
	size_t	cpt2;

	cpt = 0;
	start = 0;
	cpt2 = 0;
	while (str[cpt])
	{
		if (str[cpt] != c && cpt2 < nb)
		{
			start = cpt;
			while (str[cpt] != c && str[cpt])
				cpt++;
			splited[cpt2] = ft_strsub(str, start, cpt - start);
			cpt2++;
		}
		else
			cpt++;
	}
	return (splited);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**dest;
	size_t	cpt;

	cpt = 0;
	if (!(str))
		return (0);
	cpt = ft_cntwrds(str, c);
	if (!(dest = (char **)malloc(sizeof(char *) * (cpt + 1))))
		return (0);
	dest = ft_split(dest, str, c, cpt);
	dest[cpt] = 0;
	return (dest);
}
