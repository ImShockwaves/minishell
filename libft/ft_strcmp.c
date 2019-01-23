/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:32:47 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/08 16:38:52 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int cpt;

	cpt = 0;
	while (s1[cpt] && s2[cpt] && s1[cpt] == s2[cpt])
		cpt++;
	return ((unsigned char)(s1[cpt]) - (unsigned char)(s2[cpt]));
}
