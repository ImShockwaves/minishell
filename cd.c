/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moreft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:00:54 by ccharrie          #+#    #+#             */
/*   Updated: 2018/01/20 14:04:00 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_switchpwd(t_env *env)
{
	char	*tmp;
	char	*tmp2;
	t_env	*begin;

	begin = env;
	while (env)
	{
		if (ft_strcmp(env->name, "PWD") == 0)
			tmp = ft_strdup(env->value);
		else if (ft_strcmp(env->name, "OLDPWD") == 0)
			tmp2 = ft_strdup(env->value);
		env = env->next;
	}
	env = begin;
	while (env)
	{
		if (ft_strcmp(env->name, "PWD") == 0)
			ft_changevarvalue(env, tmp2);
		else if (ft_strcmp(env->name, "OLDPWD") == 0)
			ft_changevarvalue(env, tmp);
		env = env->next;
	}
	ft_2strdel(&tmp, &tmp2);
	env = begin;
	return (env);
}

t_env	*ft_getworkdir(char *args, t_env *env)
{
	t_env	*begin;

	begin = env;
	if (chdir(args) == 0)
	{
		env = ft_switchpwd(env);
		while (env)
		{
			if (ft_strcmp(env->name, "PWD") == 0)
			{
				ft_changevarvalue(env, args);
				break ;
			}
			env = env->next;
		}
		env = begin;
	}
	else if (access(args, F_OK) == 0)
		ft_putformat("cd : permission denied🤔\n", LIGHT_RED, NULL, "BOLD");
	else
		ft_putformat("cd : no such directory🤔\n", LIGHT_RED, NULL, "BOLD");
	return (env);
}

t_env	*ft_getolddir(t_env *env)
{
	t_env	*begin;

	begin = env;
	env = ft_switchpwd(env);
	while (env)
	{
		if (ft_strcmp(env->name, "PWD") == 0)
		{
			chdir(env->value);
			ft_putendl(env->value);
			break ;
		}
		env = env->next;
	}
	env = begin;
	return (env);
}

t_env	*ft_gohome(t_env *env)
{
	t_env	*begin;
	char	*args;

	begin = env;
	while (env)
	{
		if (ft_strcmp(env->name, "HOME") == 0)
		{
			args = ft_strdup(env->value);
			env = begin;
			env = ft_getworkdir(args, env);
			ft_strdel(&args);
			break ;
		}
		env = env->next;
	}
	if (env == NULL)
		ft_putformat("cd : home not set🤔\n", LIGHT_RED, NULL, "BOLD");
	return (env);
}

t_env	*ft_docd(char **args, t_env *env)
{
	int i;

	i = 0;
	while (args[i])
		i++;
	if (i > 2)
	{
		ft_putformat("cd : too many arguments🤔\n", LIGHT_RED, NULL, "BOLD");
		ft_putformat("here is the good usage : cd [PATH]\n", RED, NULL, "BOLD");
	}
	else if (i == 1)
		env = ft_gohome(env);
	else if (ft_strcmp(args[1], "-") == 0)
		env = ft_getolddir(env);
	else if (ft_strcmp(args[1], "~") == 0)
		env = ft_gohome(env);
	else
		env = ft_getworkdir(args[1], env);
	return (env);
}
