/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitwhitespaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 13:54:51 by ccharrie          #+#    #+#             */
/*   Updated: 2018/01/20 13:55:17 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(const char *s)
{
	int		i;
	int		words;

	i = 0;
	if (s[0] == ' ' || s[0] == '\t')
		words = 0;
	else
		words = 1;
	while (s[i])
	{
		if (s[i] && (s[i] == ' ' || s[i] == '\t') && s[i + 1] != ' ' &&
				s[i + 1] != '\t' && s[1 + i] != '\0')
			words++;
		i++;
	}
	return (words);
}

static void		substitute_loop(char const *s, char **tab)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (j < count_words(s))
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		start = i;
		while (s[i] && s[i] != ' ' && s[i] != '\t')
			i++;
		tab[j] = ft_strsub(s, (unsigned int)start, (size_t)(i - start));
		j++;
	}
	tab[j] = 0;
}

char			**ft_splitwhitespaces(char const *s)
{
	char	**tab;

	if (!s)
		return (0);
	if (s[0] == '\0')
	{
		if (!(tab = (char**)malloc(sizeof(char*))))
			return (0);
		tab[0] = 0;
		return (tab);
	}
	if (!(tab = (char**)malloc(sizeof(char*) * ((count_words(s) + 1)))))
		return (0);
	substitute_loop(s, tab);
	return (tab);
}
