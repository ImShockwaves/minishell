/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstbasic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:14:07 by ccharrie          #+#    #+#             */
/*   Updated: 2018/01/20 13:49:10 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**ft_list2tab(t_env *env)
{
	t_env	*begin;
	char	**res;
	char	*tmp;
	int		i;

	begin = env;
	i = 0;
	if (!(res = (char **)malloc(sizeof(char *) * ft_lstlen(env) + 1)))
		return (NULL);
	while (env)
	{
		tmp = ft_strdup(env->name);
		tmp = ft_strjoinndels1(tmp, "=");
		tmp = ft_strjoinndels1(tmp, env->value);
		res[i] = ft_strdup(tmp);
		ft_strdel(&tmp);
		i++;
		env = env->next;
	}
	res[i] = 0;
	env = begin;
	return (res);
}

t_env		*envnew(char *name, char *value)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	env->name = ft_strdup(name);
	env->value = ft_strdup(value);
	env->next = NULL;
	return (env);
}

void		lstaddend(t_env **lst, t_env *new)
{
	t_env	*tmp;

	tmp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = new;
		*lst = tmp;
	}
}

int			ft_lstlen(t_env *lst)
{
	int		res;
	t_env	*begin;

	res = 0;
	begin = lst;
	while (lst)
	{
		lst = lst->next;
		res++;
	}
	lst = begin;
	return (res);
}

void		ft_dellst(t_env *env)
{
	t_env	*nextlink;

	if (env)
	{
		ft_strdel(&env->name);
		ft_strdel(&env->value);
		nextlink = env->next;
		free(env);
		ft_dellst(nextlink);
	}
}
