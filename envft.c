/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:18:29 by ccharrie          #+#    #+#             */
/*   Updated: 2018/01/31 14:52:49 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_getenv(void)
{
	char extern	**environ;
	char		**tmp;
	t_env		*res;
	int			i;

	i = 0;
	res = NULL;
	while (environ[i])
	{
		tmp = ft_strsplit(environ[i], '=');
		lstaddend(&res, envnew(tmp[0], tmp[1]));
		ft_del2dtab(tmp);
		i++;
	}
	return (res);
}

t_env	*ft_dosetenv(char **args, t_env *env)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	if (i > 3)
	{
		ft_putformat("setenv : too many arguments🤔\n", LIGHT_RED, NULL, "BOLD");
		ft_putformat("here is the good usage : setenv [NAME] [VALUE]\n",
				LIGHT_RED, NULL, "BOLD");
	}
	else if (i < 3)
	{
		ft_putformat("setenv : too few arguments🤔\n", LIGHT_RED, NULL, "BOLD");
		ft_putformat("here is the good usage : setenv [NAME] [VALUE]\n",
				LIGHT_RED, NULL, "BOLD");
	}
	else if (ft_checkvarname(env, args[1]) == 1)
		env = ft_setvarvalue(env, args);
	else
		lstaddend(&env, envnew(args[1], args[2]));
	return (env);
}

void	ft_doenv(char **args, t_env *env)
{
	int		y;
	t_env	*begin;

	y = 0;
	while (args[y])
		y++;
	if (y > 1)
		ft_parsingenv(args, env);
	else
	{
		begin = env;
		while (env)
		{
			ft_putstr(env->name);
			ft_putstr("=");
			ft_putendl(env->value);
			env = env->next;
		}
		env = begin;
	}
}

t_env	*ft_dounsetenv(char **args, t_env *env)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	if (i > 2)
	{
		ft_putformat("unsetenv : too many arguments🤔\n", RED, NULL, "BOLD");
		ft_putformat("here is the good usage : unsetenv [NAME]\n",
				RED, NULL, "BOLD");
	}
	else if (i < 2)
	{
		ft_putformat("unsetenv : too many arguments🤔\n", RED, NULL, "BOLD");
		ft_putformat("here is the good usage : unsetenv [NAME]\n",
				LIGHT_RED, NULL, "BOLD");
	}
	else if (ft_checkvarname(env, args[1]) == 1)
		env = ft_unsetvar(args, env);
	else
		ft_putformat("unsetenv : no such variable🤔\n", LIGHT_RED, NULL, "BOLD");
	return (env);
}
