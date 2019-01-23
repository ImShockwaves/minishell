/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moreenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:30:32 by ccharrie          #+#    #+#             */
/*   Updated: 2018/02/05 17:16:34 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_lstcpy(t_env *env)
{
	t_env	*nenv;
	t_env	*begin;

	nenv = NULL;
	begin = env;
	while (env)
	{
		lstaddend(&nenv, envnew(env->name, env->value));
		env = env->next;
	}
	env = begin;
	return (nenv);
}

t_env	*ft_addenv(t_env *env, char **args, int i)
{
	char	**tmp;
	char	**cmd;

	tmp = ft_strsplit(args[i], '=');
	if (!(cmd = (char **)malloc(sizeof(char *) * ft_tablen(args) + 2)))
		return (NULL);
	cmd[0] = ft_strdup("setenv");
	cmd[1] = ft_strdup(tmp[0]);
	cmd[2] = ft_strdup(tmp[1]);
	cmd[3] = 0;
	env = ft_dosetenv(cmd, env);
	ft_del2dtab(tmp);
	ft_del2dtab(cmd);
	return (env);
}

int		ft_execwnenv(t_env *nenv, t_env *env, char **args, int i)
{
	char	**path;
	char	**cmd;
	int		j;
	char	**tenv;

	path = getpath(env);
	if (!(cmd = (char **)malloc(sizeof(char *) * ft_tablen(args) + 1)))
		return (0);
	j = 0;
	while (args[i])
	{
		cmd[j] = ft_strdup(args[i]);
		j++;
		i++;
	}
	cmd[j] = NULL;
	tenv = ft_list2tab(nenv);
	forknexec(cmd, path, tenv);
	ft_del2tab(cmd, path);
	ft_del2dtab(tenv);
	return (0);
}

void	ft_envwvar(char **args, t_env *env)
{
	int		i;

	i = 1;
	while (args[i])
	{
		ft_strdel(&args[i]);
		i++;
	}
	args[1] = 0;
	ft_doenv(args, env);
}

void	ft_parsingenv(char **args, t_env *env)
{
	t_env	*nenv;
	int		i;

	i = 1;
	if (ft_strcmp("-i", args[i]) == 0)
	{
		i++;
		nenv = NULL;
	}
	else
		nenv = ft_lstcpy(env);
	while (args[i] && ft_strchr(args[i], '='))
	{
		nenv = ft_addenv(nenv, args, i);
		i++;
	}
	if (ft_tablen(args) >= i + 1)
		ft_execwnenv(nenv, env, args, i);
	else
		ft_envwvar(args, nenv);
	ft_dellst(nenv);
}
