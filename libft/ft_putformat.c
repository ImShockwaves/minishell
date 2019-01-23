/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:17:31 by ccharrie          #+#    #+#             */
/*   Updated: 2017/12/17 13:21:43 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putformat(char *str, char *color, char *background, char *format)
{
	if (color != NULL)
		ft_putstr(color);
	if (background != NULL)
		ft_putstr(background);
	if (format != NULL)
	{
		if (ft_strstr(format, "BOLD") != 0)
			ft_putstr(BOLD);
		if (ft_strstr(format, "UNDERLINE") != 0)
			ft_putstr(UNDERLINE);
		if (ft_strstr(format, "BLINK") != 0)
			ft_putstr(BLINK);
		if (ft_strstr(format, "HIGHLIGHT") != 0)
			ft_putstr(HIGHLIGHT);
	}
	ft_putstr(str);
	ft_putstr("\033[0m");
}
