/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doer.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:35:17 by ccharrie          #+#    #+#             */
/*   Updated: 2018/01/20 14:25:18 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_doecho(char **args)
{
	int		i;

	i = 1;
	while (args[i])
	{
		ft_putstr(args[i]);
		if (args[i + 1])
			ft_putchar(' ');
		else
			ft_putchar('\n');
		i++;
	}
}

void	ft_docmd(char *cmd, t_env *env)
{
	char	**args;
	char	**tenv;

	tenv = ft_list2tab(env);
	args = ft_splitwhitespaces(cmd);
	if (ft_checkpath(args) == 1)
		execcmd(args, tenv);
	else
		execbincmd(args, env);
	ft_del2dtab(tenv);
	ft_del2dtab(args);
}

t_env	*ft_dobuiltin(char *cmd, t_env *env)
{
	char	**args;

	args = ft_splitwhitespaces(cmd);
	if (ft_strcmp(args[0], "env") == 0)
		ft_doenv(args, env);
	if (ft_strcmp(args[0], "setenv") == 0)
		env = ft_dosetenv(args, env);
	if (ft_strcmp(args[0], "unsetenv") == 0)
		env = ft_dounsetenv(args, env);
	if (ft_strcmp(args[0], "cd") == 0)
		env = ft_docd(args, env);
	if (ft_strcmp(args[0], "echo") == 0)
		ft_doecho(args);
	if (ft_strcmp(args[0], "exit") == 0)
		ft_putformat("See you later !👋\n", GREEN, NULL, "BOLD");
	ft_del2dtab(args);
	return (env);
}
