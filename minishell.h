/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:34:49 by ccharrie          #+#    #+#             */
/*   Updated: 2018/02/05 16:09:29 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <dirent.h>

# include "libft/libft.h"

# define BUF_SIZE 100000

typedef struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

/*
**	integer functions
*/

int					ft_checkpath(char **args);
int					clearterm(t_env *env);
int					ft_checkvarname(t_env *env, char *args);
int					ft_checkcmdorbuilt(char *cmd);
int					ft_lstlen(t_env *list);

/*
**	void functions
*/

void				forknexec(char **cmd, char **path, char **env);
void				ft_parsingenv(char **args, t_env *env);
void				ft_docmd(char *cmd, t_env *env);
void				ft_doenv(char **args, t_env *env);
void				execcmd(char **args, char **tenv);
void				lstaddend(t_env **lst, t_env *new);
void				ft_dellst(t_env *env);
void				ft_changevarvalue(t_env *env, char *newvalue);
void				execbincmd(char **args, t_env *env);
void				findthebin(char **args, char **path, char **env);

/*
**	char functions
*/

char				**ft_list2tab(t_env *env);
char				**getpath(t_env *env);

/*
**	list functions
*/

t_env				*ft_getenv(void);
t_env				*ft_docd(char **args, t_env *env);
t_env				*ft_unsetvar(char **args, t_env *env);
t_env				*ft_dounsetenv(char **args, t_env *env);
t_env				*ft_setvarvalue(t_env *env, char **args);
t_env				*ft_dosetenv(char **args, t_env *env);
t_env				*ft_dobuiltin(char *cmd, t_env *env);
t_env				*envnew(char *name, char *value);
t_env				*ft_putpath(t_env *env);
t_env				*ft_gohome(t_env *env);

#endif
