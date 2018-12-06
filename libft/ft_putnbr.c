/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 00:10:12 by samukano          #+#    #+#             */
/*   Updated: 2018/11/11 00:10:13 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	d(long long nn)
{
	if (nn > 9)
		d(nn / 10);
	ft_putchar(nn % 10 + '0');
}

void			ft_putnbr(int n)
{
	long long nn;

	nn = n;
	if (nn < 0)
	{
		ft_putchar('-');
		nn = -nn;
	}
	d(nn);
}
