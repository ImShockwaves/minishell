/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 12:13:56 by ccharrie          #+#    #+#             */
/*   Updated: 2018/01/20 13:56:58 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_checkpath(char **args)
{
	if (ft_strchr(args[0], '/'))
		return (1);
	else
		return (0);
}

int		ft_checkargs(char **args)
{
	if (!(args[0]))
	{
		ft_del2dtab(args);
		return (1);
	}
	return (0);
}

int		ft_checkcmdorbuilt(char *cmd)
{
	char	**args;

	args = ft_splitwhitespaces(cmd);
	if (ft_checkargs(args) == 1)
		return (-1);
	if (ft_strcmp(args[0], "cd") == 0 || ft_strcmp(args[0], "exit") == 0 ||
			ft_strcmp(args[0], "echo") == 0)
	{
		ft_del2dtab(args);
		return (0);
	}
	else if (ft_strcmp(args[0], "env") == 0 ||
			ft_strcmp(args[0], "setenv") == 0)
	{
		ft_del2dtab(args);
		return (0);
	}
	else if (ft_strcmp(args[0], "unsetenv") == 0)
	{
		ft_del2dtab(args);
		return (0);
	}
	ft_del2dtab(args);
	return (1);
}

int		ft_checkvarname(t_env *env, char *args)
{
	t_env	*begin;

	begin = env;
	while (env)
	{
		if (ft_strcmp(env->name, args) == 0)
		{
			env = begin;
			return (1);
		}
		env = env->next;
	}
	env = begin;
	return (0);
}
