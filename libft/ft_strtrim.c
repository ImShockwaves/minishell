/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:49:18 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/08 20:02:13 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	cpt;
	char			*dest;
	size_t			len;
	unsigned int	start;

	cpt = 0;
	len = 0;
	if (!(s))
		return (0);
	while (s[cpt] && (s[cpt] == ' ' || s[cpt] == '\n' || s[cpt] == '\t'))
		cpt++;
	start = cpt;
	while (s[cpt])
	{
		if (s[cpt] != ' ' && s[cpt] != '\n' && s[cpt] != '\t')
			len = cpt - start + 1;
		cpt++;
	}
	if (len == 0 && start > 0)
		return (ft_strdup("\0"));
	if (!(dest = ft_strnew(len + 1)))
		return (NULL);
	dest = ft_strsub(s, start, len);
	return (dest);
}
