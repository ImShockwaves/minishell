/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:28:07 by ccharrie          #+#    #+#             */
/*   Updated: 2018/02/05 15:55:36 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_changevarvalue(t_env *env, char *newvalue)
{
	ft_strdel(&env->value);
	env->value = ft_strdup(newvalue);
}

t_env	*ft_putpath(t_env *env)
{
	char	buf[BUF_SIZE];

	if (getcwd(buf, BUF_SIZE))
	{
		ft_putformat(getcwd(buf, BUF_SIZE), CYAN, NULL, "BOLD");
		ft_putformat(" ➜  ", GREEN, NULL, "BOLD");
	}
	else
	{
		ft_putformat("Your path doesn't exist anymore, let's go home ! 😃 \n",
				RED, NULL, "BOLD");
		env = ft_gohome(env);
		env = ft_putpath(env);
	}
	return (env);
}

t_env	*ft_setvarvalue(t_env *env, char **args)
{
	t_env	*begin;

	begin = env;
	while (env)
	{
		if (ft_strcmp(args[1], env->name) == 0)
		{
			ft_strdel(&env->value);
			env->value = ft_strdup(args[2]);
			break ;
		}
		env = env->next;
	}
	env = begin;
	return (env);
}

t_env	*ft_unsetvar(char **args, t_env *env)
{
	t_env	*begin;
	t_env	*before;

	begin = env;
	before = NULL;
	while (env)
	{
		if (ft_strcmp(env->name, args[1]) == 0)
		{
			before->next = env->next;
			ft_strdel(&env->name);
			ft_strdel(&env->value);
			free(env);
			break ;
		}
		before = env;
		env = env->next;
	}
	env = begin;
	return (env);
}

char	**getpath(t_env *env)
{
	char	**path;
	t_env	*begin;

	path = NULL;
	begin = env;
	while (env)
	{
		if (ft_strcmp("PATH", env->name) == 0)
		{
			path = ft_strsplit(env->value, ':');
			break ;
		}
		env = env->next;
	}
	if (env == NULL)
		ft_putformat("error : command not found, everyone make mistakes 😉\n",
				RED, NULL, "BOLD");
	env = begin;
	return (path);
}
