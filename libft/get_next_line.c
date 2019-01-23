/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:15:56 by ccharrie          #+#    #+#             */
/*   Updated: 2018/01/06 17:20:10 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	stock_the_end(char *str, size_t i)
{
	int	j;

	j = 0;
	while (i < ft_strlen(str))
	{
		str[j] = str[i + 1];
		i++;
		j++;
	}
	str[j] = '\0';
}

int		get_the_line(int ret, char **line, char *str)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!(res = ft_strnew(ft_strlen(str))))
		return (0);
	if (ret != 0 || ft_strlen(str) != 0)
	{
		if (str[0] == '\n')
			res[0] = '\0';
		else
		{
			while (str[i] != '\n' && str[i])
			{
				res[i] = str[i];
				i++;
			}
			res[i] = '\0';
		}
		*line = res;
		stock_the_end(str, i);
		return (1);
	}
	return (0);
}

char	*resizestr(char *str)
{
	char *tmp;

	if (!(tmp = ft_strnew(ft_strlen(str))))
		return (NULL);
	tmp = ft_strcpy(tmp, str);
	free(str);
	if (!(str = ft_strnew(ft_strlen(tmp) + BUFF_SIZE)))
		return (NULL);
	str = ft_strcpy(str, tmp);
	free(tmp);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	static char	*str = NULL;
	char		*tmp;
	int			eol;
	int			ret;

	eol = 1;
	if (fd < 0 || (!(line)))
		return (-1);
	if ((!(str)) && (!(str = ft_strnew(BUFF_SIZE))))
		return (-1);
	if (!(tmp = ft_strnew(BUFF_SIZE)))
		return (-1);
	while (eol == 1 && (ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		str = resizestr(str);
		str = ft_strncat(str, tmp, ret);
		if (ft_strchr(tmp, '\n'))
			eol = 0;
	}
	free(tmp);
	if (ret == -1)
		return (-1);
	if (get_the_line(ret, line, str) == 1)
		return (1);
	return (0);
}
