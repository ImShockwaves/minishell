/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_pow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 09:27:54 by ccharrie          #+#    #+#             */
/*   Updated: 2017/11/09 21:53:11 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_pow(int nb, int power)
{
	int res;

	if (power < 0)
	{
		return (res = 0);
	}
	if (power == 0)
	{
		res = 1;
	}
	else
	{
		res = nb * ft_recursive_pow(nb, power - 1);
	}
	return (res);
}
