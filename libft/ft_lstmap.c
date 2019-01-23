/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:14:03 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/09 17:34:14 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (!(lst) || !(*f))
		return (0);
	if (!(new = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	new = (*f)(lst);
	if (lst)
		new->next = ft_lstmap(lst->next, f);
	return (new);
}
