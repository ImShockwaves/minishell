/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:41:12 by ccharrie          #+#    #+#             */
/*   Updated: 2017/12/02 19:03:15 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list *lst, t_list *new)
{
	t_list *tmp;

	tmp = lst;
	if (lst == NULL)
		lst = new;
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
		lst = tmp;
	}
}
