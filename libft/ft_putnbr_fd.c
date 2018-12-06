/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 12:21:27 by samukano          #+#    #+#             */
/*   Updated: 2018/11/11 12:21:27 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	a_rec(long long nn, int fd)
{
	if (nn > 9)
		a_rec(nn / 10, fd);
	ft_putchar_fd(nn % 10 + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	long long nn;

	nn = n;
	if (nn < 0)
	{
		nn = -nn;
		ft_putchar_fd('-', fd);
	}
	a_rec(nn, fd);
}
