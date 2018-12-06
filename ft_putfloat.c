/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:38:58 by samukano          #+#    #+#             */
/*   Updated: 2018/11/30 14:38:58 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

long long	sz(int n)
{
	int			cnt;
	int			i;
	long long	ans;

	cnt = 0;
	i = 0;
	ans = 1;
	//printf("n = %d", n);
	while (n)
	{
		n /= 10;
		cnt++;
	}
	while (i < cnt - 1)
	{
		ans *= 10;
		i++;
	}
	//printf("ans = %lld", ans);
	return (ans);
}

int			minisz(long long n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

int			uminisz(unsigned long long n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

void		ft_putfloat(int ker1, int n, double f, char cha, int minus, int hash)
{
	int		num;
	double	digit;
	char	c;
	int		i;
	int		dot;
	int		tmp1;
	int		a[5000];

	i = 0;
	num = 0;
	dot = n > 0 ? 1 : 0;
	tmp1 = (int)(f);
	i = 0;
	f -= tmp1;
	f *= 10;
	if (!n && hash)
	{
		if (!minus)
			while (i + 1 + minisz(tmp1) < ker1)
			{
				ft_putchar(cha);
				i++;
			}
		ft_putnbr(f > 5.0 ? tmp1 + 1 : tmp1);
		ft_putchar('.');
		if (minus)
			while (i + 1 + minisz(tmp1) < ker1)
			{
				ft_putchar(cha);
				i++;
			}
		return ;
	}
	i = 0;
	while (i < 5000)
		a[i++] = 0;
	i = 0;
	while (f > 0 && i < n + 1)
	{
		digit = (int)(f);
		a[i] = digit;
		//printf("%f %f %d", f, digit, i);
		f -= digit;
		f *= 10.0;
		i++;
	}
	if (i == n + 1 && a[--i] >= 5)
		a[--i]++;
	while(i >= 1)
	{
		if(a[i] == 10)
		{
			a[i] = 0;
			a[i - 1]++;
		}
		else
			break ;
		i--;
		//printf("ker1 = %d i = %d\n", ker1, i);
	}
	if(a[i] == 10)
		a[i--] = 0;
	if (i++ == -1)
	{
	
		tmp1++;
		//printf("tmp = %d, ker1e = %d, mini = %d, n = %d\n", tmp1, ker1, minisz(tmp1), n);
		while(ker1 > n + dot + minisz(tmp1) + i++ && !minus)
			ft_putchar(cha);
		i--;
		ft_putnbr(tmp1);
		if (n > 0 || dot == 1)
			ft_putchar('.');
		//printf("i = %d", i);
		while (i++ < n)
			ft_putchar('0');
		return ;
	}
	i = 0;
	while(ker1 > n + dot + minisz(tmp1) + i++ && !minus)
	{
		ft_putchar(cha);
	}
	ft_putnbr(tmp1);
	if (n > 0 || dot == 1)
		ft_putchar('.');
	i = 0;
	while (i < n)
		ft_putchar((a[i++]) + '0');
	i = 0;
	while(ker1 > n + dot + minisz(tmp1) + i++ && minus)
			ft_putchar(cha);
}