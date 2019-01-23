/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 16:21:19 by ccharrie          #+#    #+#             */
/*   Updated: 2018/02/05 16:09:58 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		clearterm(t_env *env)
{
	char		**argv;
	pid_t		pid;
	int			status;
	char		**tabenv;

	pid = fork();
	tabenv = ft_list2tab(env);
	if (!(argv = (char **)malloc(sizeof(char *) * 2)))
		return (0);
	argv[0] = ft_strdup("/usr/bin/clear");
	argv[1] = NULL;
	if (pid == -1)
	{
		ft_putformat("error : unable to fork 🤔", LIGHT_RED, NULL, "BOLD");
		return (0);
	}
	else if (pid == 0)
	{
		execve(argv[0], argv, tabenv);
		exit(1);
	}
	else
		waitpid(pid, &status, 0);
	ft_del2tab(tabenv, argv);
	return (0);
}

void	execcmd(char **args, char **env)
{
	execve(args[0], args, env);
	if (ft_strcmp(args[0], "exit"))
	{
		ft_putformat(args[0], LIGHT_RED, NULL, "BOLD");
		if (access(args[0], F_OK) == -1)
		{
			ft_putformat(" error : command not found,", RED, NULL, "BOLD");
			ft_putformat(" everyone make mistakes😉\n", RED, NULL, "BOLD");
		}
		else if (access(args[0], X_OK) == -1)
		{
			ft_putformat(" error : permission denied😔\n",
					LIGHT_RED, NULL, "BOLD");
		}
	}
}

void	findthebin(char **args, char **path, char **env)
{
	int				i;
	DIR				*dir;
	struct dirent	*file;
	char			*tmp;

	i = 0;
	while (path[i])
	{
		dir = opendir(path[i]);
		while ((file = readdir(dir)))
		{
			if (ft_strcmp(file->d_name, args[0]) == 0)
			{
				tmp = ft_strjoin(path[i], "/");
				args[0] = ft_strjoinnfree(tmp, args[0]);
				execve(args[0], args, env);
			}
		}
		closedir(dir);
		i++;
	}
	ft_putformat(args[0], RED, NULL, "BOLD");
	ft_putformat(" error : command not found, everyone make mistakes 😉\n",
			RED, NULL, "BOLD");
}

void	execbincmd(char **args, t_env *env)
{
	char	**path;
	t_env	*begin;
	char	**tenv;

	begin = env;
	path = NULL;
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
	tenv = ft_list2tab(env);
	findthebin(args, path, tenv);
	ft_del2dtab(path);
	ft_del2dtab(tenv);
}

void	forknexec(char **cmd, char **path, char **env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		ft_putformat("error : unable to fork 🤔", LIGHT_RED, NULL, "BOLD");
	else if (pid == 0)
	{
		findthebin(cmd, path, env);
		exit(1);
	}
	else
		waitpid(pid, &status, 0);
}
