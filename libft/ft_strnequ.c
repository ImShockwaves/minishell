/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:17:03 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/09 15:00:26 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	cpt;

	cpt = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[cpt] == s2[cpt] && s1[cpt] && s2[cpt] && cpt < n)
		cpt++;
	if ((!s1[cpt] && !s2[cpt]) || cpt == n)
		return (1);
	return (0);
}
