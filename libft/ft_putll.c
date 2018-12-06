/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:08:10 by samukano          #+#    #+#             */
/*   Updated: 2018/12/01 20:08:12 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		llabs(long long x)
{
	if (x >= 0)
		return (x);
	return (-x);
}

static	void	d(long long nn)
{
	if (nn > 9)
		d(llabs(nn / 10));
	ft_putchar(llabs(nn % 10) + '0');
}

void			ft_putll(long long n)
{
	long long		 		nn;

	if (n == INTMAX_MIN)
	{
		ft_putstr("-9223372036854775808");
		return ;
	}
	nn = n >= 0 ? n : -n;
	d(nn);
}

static	void	ud(unsigned long long nn)
{
	if (nn > 9)
		d((nn / 10));
	ft_putchar((nn % 10) + '0');
}

void			ft_putull(unsigned long long n)
{
	unsigned long long		nn;

	nn = n;
	if (n == INTMAX_MIN)
	{
		ft_putstr("-9223372036854775808");
		return ;
	}
	ud(nn);
}
