/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:34:08 by ccharrie          #+#    #+#             */
/*   Updated: 2018/01/20 14:08:02 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_dofork(char *cmd, t_env *env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		ft_putformat("error : unable to fork 🤔", LIGHT_RED, NULL, "BOLD");
	else if (pid == 0)
	{
		ft_docmd(cmd, env);
		exit(1);
	}
	else
		waitpid(pid, &status, 0);
}

t_env	*ft_parsingline(char **cmd, t_env *env)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		if (ft_strcmp(cmd[i], "\0"))
		{
			if (ft_checkcmdorbuilt(cmd[i]) == 1)
				ft_dofork(cmd[i], env);
			else if (ft_checkcmdorbuilt(cmd[i]) == 0)
				env = ft_dobuiltin(cmd[i], env);
		}
		i++;
	}
	return (env);
}

int		main(void)
{
	char	*cmd;
	char	**rcmd;
	t_env	*env;

	env = ft_getenv();
	clearterm(env);
	cmd = NULL;
	ft_putformat("Hi ! Happy to see you again ! 🤜 ✨🤛\n", GREEN, NULL, "BOLD");
	while (cmd == NULL || ft_strcmp("exit", cmd))
	{
		env = ft_putpath(env);
		get_next_line(0, &cmd);
		rcmd = ft_strsplit(cmd, ';');
		env = ft_parsingline(rcmd, env);
		ft_del2dtab(rcmd);
		free(cmd);
	}
	ft_dellst(env);
	return (0);
}
