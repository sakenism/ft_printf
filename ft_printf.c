/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:35:51 by samukano          #+#    #+#             */
/*   Updated: 2018/11/30 13:35:51 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			g_cnt = 0;
va_list		*g_arg;

long long	max(long long a, long long b)
{
	if(a > b)
		return (a);
	return (b);
}

void		cnt_puts(void)
{
	g_cnt++;
}

void		cnt_dec(void)
{
	g_cnt--;
}
void		plusd(long long a, int znak)
{
	unsigned long long ull;

	if (a == INTMAX_MIN)
		return ; 
	if (a >= 0 && znak)
	{
		ft_putchar('+');
	}
	if (a < 0)
	{
		ft_putchar('-');
	}
}

void		plusf(long double a, int znak)
{
	if (a >= 0.0 && znak)
		ft_putchar('+');
}

void		pr_pre(int n, int m, char c)
{
	while (n > m)
	{
		ft_putchar(c);
		n--;
	}
}

void		pr_zero(int n)
{
	while(n > 0)
	{
		ft_putchar('0');
		n--;
	}
}

void		ft_print_decimal(int ker1, int ker2, long long n, char cha, int minus)
{
	int	i;

	i = 0;
	if(ker1 > (ker2 > minisz(n)) ? minisz(n) : ker2 && !minus)
		while (i < ker1 - max(ker2, minisz(n)))
		{
			ft_putchar(cha);
			i++;
		}
	i = 0;
	//printf("%d\n", minisz(n));
	while (ker2 > minisz(n) + i)
	{
		ft_putchar(cha);
		i++;
	}
	ft_putll(n);
	i = 0;
	if(ker1 > max(minisz(n), ker2) && minus)
		while (i < ker1 - max(ker2, minisz(n)))
		{
			ft_putchar(cha);
			i++;
		}
}

int			beginning(char **ind, t_flags *t)
{
	if (**ind == ' ')
	{
		t->probel = 1;
		return (1);
	}
	if (**ind == '+')
	{
		t->znak = 1;
		return (1);
	}
	if (**ind == '-')
	{
	//	(*ind)++;
		t->nol = 0;
		t->minus = 1;
		t->cha = ' ';
		return (1);
	}
	if (**ind == '#')
	{
	//	(*ind)++;
		t->hash = 1;
		return (1);
	}
	if (**ind == '0' && !t->minus/* && !ft_isdigit(*(*ind + 1)) && !ft_isdigit(*(*ind - 1))*/)
	{
	//	(*ind)++;
		t->nol = 1;
		t->cha = '0';
		return (1);
	}
	if (**ind == '.')
	{
	//	(*ind)++;
		t->tochka = 1;
	}
	return (0);
}

void		checkprobel(t_flags *t, long long n, int ker1)
{
	if (!t->znak && n > 0 && t->probel)
		ft_putchar(' ');
}

void		clearflags(t_flags *t)
{
	t->nol = 0;
	t->znak = 0;
	t->probel = 0;
	t->ker1 = 0;
	t->ker2 = 0;
	t->tochka = 0;
	t->cnt = 0;
	t->minus = 0;
	t->cha = ' ';
	t->hash = 0;
	t->sign = 1;
}

int			kereksan(t_flags *t, char **ind, int *ker1, int *ker2)
{
	if (**ind >= '0' && **ind <= '9')
	{
		if(**ind == '0')
		{
			t->cha = '0';
			t->nol = 1;
		}
		*ker1 = ft_atoi(*ind);
		while (**ind >= '0' && **ind <= '9')
			(*ind)++;
	}
	if(**ind == '\0')
		return (-1);
	if (**ind == '.')
	{
		t->tochka = 1;
		(*ind)++;
		*ker2 = ft_atoi(*ind);
		while (**ind >= '0' && **ind <= '9')
			(*ind)++;
	}
	return (0);
}

int			first_check(char **ind, t_flags *t, int ker1, int ker2)
{
	long long			ll;
	long				l;
	double				db;
	int					sz;

	if (**ind == 'l' && *(*ind + 1) == 'l' && (*(*ind + 2) == 'd' || *(*ind + 2) == 'i'))
	{
		*ind += 2;
		ll = va_arg(*g_arg, long long);
		if (t->tochka)
		{
			t->cha = ' ';
			t->nol = 0;
		}
		sz = minisz(ll) + t->znak;
		if (ll < 0 && t->tochka && ker2 > minisz(ll))
			ker1--;
		if (!t->znak)
			sz = ll < 0 ? sz + 1: sz;
		if (!t->tochka)
			ker2 = sz - 1;
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && !t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		checkprobel(t, ll, ker1);
		plusd(ll, t->znak);
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), '0');
		if (t->tochka)
			pr_zero(ker2 - minisz(ll));
		//printf("k=%d %d\n", ker1, ker2);
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if(!(!ker1 && t->tochka && !ker2 && !ll))
			ft_putll(ll);
		//else if (!(t->tochka && !ll))
			//ft_putchar(' ');
		//printf(" %d %d\n", ker1, max(ker2 + t->znak, sz));
		if (t->minus && ker1 > (max(ker2 + t->znak, sz) ))
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
	//	printf("hey");
		//printf("sz = %d %d\n", ker1, ker2);
		return (1);
	}
	else if (**ind == 'l' && (*(*ind + 1) == 'd' || *(*ind + 2) == 'i'))
	{
		*ind += 1;
		l = va_arg(*g_arg, long);
		if (t->tochka)
		{
			t->cha = ' ';
			t->nol = 0;
		}
		sz = minisz(l) + t->znak;
		if (l < 0 && t->tochka && ker2 > minisz(l))
			ker1--;
		if (!t->znak)
			sz = l < 0 ? sz + 1: sz;
		if (!t->tochka)
			ker2 = sz - 1;
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && !t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		checkprobel(t, l, ker1);
		plusd(l, t->znak);
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), '0');
		if (t->tochka)
			pr_zero(ker2 - minisz(l));
		//printf("k=%d %d\n", ker1, ker2);
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if(!(!ker1 && t->tochka && !ker2 && !l))
			ft_putll(l);
		//else if (!(t->tochka && !l))
			//ft_putchar(' ');
		//printf(" %d %d\n", ker1, max(ker2 + t->znak, sz));
		if (t->minus && ker1 > (max(ker2 + t->znak, sz) ))
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
	//	printf("hey");
		//printf("sz = %d %d\n", ker1, ker2);
		return (1);
	}
	else if (**ind == 'l' && *(*ind + 1) == 'f')
	{
		db = va_arg(*g_arg, double);
		plusf(db, t->znak);
		checkprobel(t, (long long)(db), ker1);
		ft_putfloat(ker1, t->tochka ? ker2 : 6, db, t->cha, t->minus, t->hash);
		(*ind)++;
		return (1);
	}
	return (0);
}

int			second_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned int		ui;
	int					i;
	long double			ldb;
	int					sz;

	if (**ind == 'L' && *(*ind + 1) == 'f')
	{
		ldb = va_arg(*g_arg, long double);
		plusf(ldb, t->znak);
		checkprobel(t, (long long)(ldb), ker1);
		ft_putfloat(ker1, t->tochka ? ker2 : 6, ldb, t->cha, t->minus, t->hash);
		if (!ker2 && t->hash)
			ft_putchar('.');
		(*ind)++;
		return (1);
	}
	else if (**ind == 'u')
	{
		ui = va_arg(*g_arg, unsigned int);
		if (t->tochka)
		{
			t->cha = ' ';
			t->nol = 0;
		}
		//printf("%u\n", ui);
		sz = uminisz(ui) + t->znak;
		if (!t->tochka)
			ker2 = sz - 1;
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && !t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), '0');
		if (t->tochka)
			pr_zero(ker2 - uminisz(ui));
		//printf("k=%d %d\n", ker1, ker2);
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if(!(!ker1 && t->tochka && !ker2 && !ui))
			ft_putull(ui);
		//else if (!(t->tochka && !i))
			//ft_putchar(' ');
		//printf(" %d %d\n", ker1, max(ker2 + t->znak, sz));
		if (t->minus && ker1 > (max(ker2 + t->znak, sz) ))
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
	//	printf("hey");
		//printf("sz = %d %d\n", ker1, ker2);
		return (1);
	}
	else if (**ind == 'd' || **ind == 'i')
	{
		//printf("ker1 = %d ker2 = %d %c\n", ker1 ,ker2, **ind);
		i = va_arg(*g_arg, int);
		if (t->tochka)
		{
			t->cha = ' ';
			t->nol = 0;
		}
		sz = minisz(i) + t->znak;
		if (i < 0 && t->tochka && ker2 > minisz(i))
			ker1--;
		if (!t->znak)
			sz = i < 0 ? sz + 1: sz;
		if (!t->tochka)
			ker2 = sz - 1;
		//printf("%d\n", ker2 + t->znak);
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && !t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		checkprobel(t, i, ker1);
		plusd(i, t->znak);
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), '0');
		if (t->tochka)
			pr_zero(ker2 - minisz(i));
		//printf("k=%d %d\n", ker1, ker2);
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if(!(!ker1 && t->tochka && !ker2 && !i))
			ft_putll(i);
		//else if (!(t->tochka && !i))
			//ft_putchar(' ');
		//printf(" %d %d\n", ker1, max(ker2 + t->znak, sz));
		if (t->minus && ker1 > (max(ker2 + t->znak, sz) ))
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
	//	printf("hey");
		//printf("sz = %d %d\n", ker1, ker2);
		return (1);
	}/*

		i = va_arg(*g_arg, int);
		plusd(&i, &t);
		checkprobel(t, i, ker1);
		ft_print_decimal(ker1, t->tochka ? ker2 : minisz(i), i, t->cha, t->minus);
		return (1);
	}*/
	return (0);
}

int			third_check(char **ind, t_flags *t, int ker1, int ker2)
{
	double		db;
	char		*s;
	int			i;

	if (**ind == 'f')
	{
		db = va_arg(*g_arg, double);
		plusf(db, t->znak);
		checkprobel(t, (long long)(db), ker1);
		ft_putfloat(ker1, t->tochka ? ker2 : 6, db, t->cha, t->minus, t->hash);
		if (!ker2 && t->hash)
			ft_putchar('.');
		return (1);
	}
	else if (**ind == 's')
	{
		s = va_arg(*g_arg, char *);
		if (!s)
		{
			ft_putstr("(null)");
			return (1);
		}
		ft_putnstr(s, ker1, !t->tochka ? ft_strlen(s) : ker2, t->cha, t->minus);
		return (1);
	}
	else if (**ind == 'c')
	{
		if (!t->minus)
			pr_pre(ker1, 1, t->cha);
		i = va_arg(*g_arg, int);
		ft_putchar(i);
		if (t->minus)
			pr_pre(ker1, 1, t->cha);
		return (1);
	}
	return (0);
}

int			fourth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	void		*p;
	signed char	sch;
	short		sh;
	int			sz;

	if (**ind == 'p')
	{
		p = va_arg(*g_arg, void*);
		ft_print_memory(p);
		return (1);
	}
	else if (**ind == 'h' && *(*ind + 1) == 'h' && (*(*ind + 2) == 'd' || *(*ind + 2) == 'i'))
	{
		*ind += 2;
		sch = va_arg(*g_arg, int);
		if (t->tochka)
		{
			t->cha = ' ';
			t->nol = 0;
		}
		sz = minisz(sch) + t->znak;
		if (sch < 0 && t->tochka && ker2 > minisz(sch))
			ker1--;
		if (!t->znak)
			sz = sch < 0 ? sz + 1: sz;
		if (!t->tochka)
			ker2 = sz - 1;
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && !t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		checkprobel(t, sch, ker1);
		plusd(sch, t->znak);
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), '0');
		if (t->tochka)
			pr_zero(ker2 - minisz(sch));
		//printf("k=%d %d\n", ker1, ker2);
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if(!(!ker1 && t->tochka && !ker2 && !sch))
			ft_putll(sch);
		//else if (!(t->tochka && !sch))
			//ft_putchar(' ');
		//printf(" %d %d\n", ker1, max(ker2 + t->znak, sz));
		if (t->minus && ker1 > (max(ker2 + t->znak, sz) ))
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
	//	printf("hey");
		//printf("sz = %d %d\n", ker1, ker2);
		return (1);
	}
	else if (**ind == 'h' && (*(*ind + 1) == 'd' || *(*ind + 1) == 'i'))
	{
		*ind += 1;
		sh = va_arg(*g_arg, long long);
		if (t->tochka)
		{
			t->cha = ' ';
			t->nol = 0;
		}
		sz = minisz(sh) + t->znak;
		if (sh < 0 && t->tochka && ker2 > minisz(sh))
			ker1--;
		if (!t->znak)
			sz = sh < 0 ? sz + 1: sz;
		if (!t->tochka)
			ker2 = sz - 1;
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && !t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		checkprobel(t, sh, ker1);
		plusd(sh, t->znak);
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), '0');
		if (t->tochka)
			pr_zero(ker2 - minisz(sh));
		//printf("k=%d %d\n", ker1, ker2);
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if(!(!ker1 && t->tochka && !ker2 && !sh))
			ft_putll(sh);
		//else if (!(t->tochka && !sh))
			//ft_putchar(' ');
		//printf(" %d %d\n", ker1, max(ker2 + t->znak, sz));
		if (t->minus && ker1 > (max(ker2 + t->znak, sz) ))
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
	//	printf("hey");
		//printf("sz = %d %d\n", ker1, ker2);
		return (1);
	}
	return (0);
}

int			fifth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned int		ui;

	if (**ind == 'o')
	{
		//printf("%d\n", ker1 - t->hash, max(ker2, ft_strlen(ft_converter(i, 8))));
		ui = va_arg(*g_arg, unsigned int);
		if (!t->tochka)
			ker2 = ft_strlen(ft_converter(ui, 8) + t->hash);
		if (t->tochka)
			t->cha = ' ';
		if (!t->minus && ker1 > max(ker2, ft_strlen(ft_converter(ui, 8))))
			pr_pre(ker1 - t->hash, max(ker2, ft_strlen(ft_converter(ui, 8))), t->cha);
		if (ui != 0 && t->hash)
			ft_putchar('0');
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converter(ui, 8)));
		checkprobel(t, ui, ker1);
		if (ui != 0 || !t->tochka || t->hash)
			ft_putstr(ft_converter(ui, 8));
		else if (!t->hash && ker1 > 0)
			ft_putchar(' ');
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converter(ui, 8))))
			pr_pre(ker1 - t->hash, max(ker2, ft_strlen(ft_converter(ui, 8))), t->cha);
		return (1);
	}
	return (0);
}
	
int			sixth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned char		uc;

	if (**ind == 'h' && *(*ind + 1) == 'h' && *(*ind + 2) == 'o')
	{
		uc = va_arg(*g_arg, int);
		if (!t->tochka)
			ker2 = ft_strlen(ft_converterhh(uc, 8) + t->hash);
		if (t->tochka)
			t->cha = ' ';
		if (!t->minus && ker1 > max(ker2, ft_strlen(ft_converterhh(uc, 8))))
			pr_pre(ker1 - t->hash, max(ker2, ft_strlen(ft_converterhh(uc, 8))), t->cha);
		if (uc != 0 && t->hash)
			ft_putchar('0');
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converterhh(uc, 8)));
		checkprobel(t, uc, ker1);
		if (uc != 0 || !t->tochka || t->hash)
			ft_putstr(ft_converterhh(uc, 8));
		else if (!t->hash && ker1 > 0)
			ft_putchar(' ');
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converterhh(uc, 8))))
			pr_pre(ker1 - t->hash, max(ker2, ft_strlen(ft_converterhh(uc, 8))), t->cha);
		(*ind) += 2;
		return (1);
	}
	return (0);
}

int			seventh_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned short	ush;

	if (**ind == 'h' && *(*ind + 1) == 'o')
	{
		ush = va_arg(*g_arg, unsigned int);
		if (!t->tochka)
			ker2 = ft_strlen(ft_converterh(ush, 8) + t->hash);
		if (t->tochka)
			t->cha = ' ';
		if (!t->minus && ker1 > max(ker2, ft_strlen(ft_converterh(ush, 8))))
			pr_pre(ker1 - t->hash, max(ker2, ft_strlen(ft_converterh(ush, 8))), t->cha);
		if (ush != 0 && t->hash)
			ft_putchar('0');
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converterh(ush, 8)));
		checkprobel(t, ush, ker1);
		if (ush != 0 || !t->tochka || t->hash)
			ft_putstr(ft_converterh(ush, 8));
		else if (!t->hash && ker1 > 0)
			ft_putchar(' ');
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converterh(ush, 8))))
			pr_pre(ker1 - t->hash, max(ker2, ft_strlen(ft_converterh(ush, 8))), t->cha);
		(*ind) += 1;
		return (1);
	}
	return (0);
}

int			eighth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned long long			ull;

	if (**ind == 'l' && *(*ind + 1) == 'l' && *(*ind + 2) == 'o')
	{
		ull = va_arg(*g_arg, unsigned long long);
		if (!t->tochka)
			ker2 = ft_strlen(ft_converterll(ull, 8) + t->hash);
		if (t->tochka)
			t->cha = ' ';
		if (!t->minus && ker1 > max(ker2, ft_strlen(ft_converterll(ull, 8))))
			pr_pre(ker1 - t->hash, max(ker2, ft_strlen(ft_converterll(ull, 8))), t->cha);
		if (ull != 0 && t->hash)
			ft_putchar('0');
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converterll(ull, 8)));
		checkprobel(t, ull, ker1);
		if (ull != 0 || !t->tochka || t->hash)
			ft_putstr(ft_converterll(ull, 8));
		else if (!t->hash && ker1 > 0)
			ft_putchar(' ');
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converterll(ull, 8))))
			pr_pre(ker1 - t->hash, max(ker2, ft_strlen(ft_converterll(ull, 8))), t->cha);
		(*ind) += 2;
		return (1);
	}
	return (0);
}

int			ninth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned long		ul;

	if (**ind == 'l' && *(*ind + 1) == 'o')
	{
		ul = va_arg(*g_arg, unsigned long);
		if (!t->tochka)
			ker2 = ft_strlen(ft_converterl(ul, 8) + t->hash);
		if (t->tochka)
			t->cha = ' ';
		if (!t->minus && ker1 > max(ker2, ft_strlen(ft_converterl(ul, 8))))
			pr_pre(ker1 - t->hash, max(ker2, ft_strlen(ft_converterl(ul, 8))), t->cha);
		if (ul != 0 && t->hash)
			ft_putchar('0');
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converterl(ul, 8)));
		checkprobel(t, ul, ker1);
		if (ul != 0 || !t->tochka || t->hash)
			ft_putstr(ft_converterl(ul, 8));
		else if (!t->hash && ker1 > 0)
			ft_putchar(' ');
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converterl(ul, 8))))
			pr_pre(ker1 - t->hash, max(ker2, ft_strlen(ft_converterl(ul, 8))), t->cha);
		(*ind) += 1;
		return (1);
	}
	return (0);
}

int			tenth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned char			uc;
	unsigned long long		ull;
	unsigned short			ush;
	unsigned long			ul;
	int						sz;

	if (**ind == 'h' && *(*ind + 1) == 'h' && *(*ind + 2) == 'u')
	{
		*ind += 2;
		uc = va_arg(*g_arg, int);
		if (t->tochka)
		{
			t->cha = ' ';
			t->nol = 0;
		}
		//printf("%u\n", ui);
		sz = uminisz(uc) + t->znak;
		if (!t->tochka)
			ker2 = sz - 1;
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && !t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), '0');
		if (t->tochka)
			pr_zero(ker2 - uminisz(uc));
		//printf("k=%d %d\n", ker1, ker2);
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if(!(!ker1 && t->tochka && !ker2 && !uc))
			ft_putull(uc);
		//else if (!(t->tochka && !i))
			//ft_putchar(' ');
		//printf(" %d %d\n", ker1, max(ker2 + t->znak, sz));
		if (t->minus && ker1 > (max(ker2 + t->znak, sz) ))
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
	//	printf("hey");
		//printf("sz = %d %d\n", ker1, ker2);
		return (1);
	}
	else if (**ind == 'l' && *(*ind + 1) == 'l' && *(*ind + 2) == 'u')
	{
		*ind += 2;
		ull = va_arg(*g_arg, unsigned long long);
		if (t->tochka)
		{
			t->cha = ' ';
			t->nol = 0;
		}
		//printf("%u\n", ull);
		sz = uminisz(ull) + t->znak;
		if (!t->tochka)
			ker2 = sz - 1;
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && !t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), '0');
		if (t->tochka)
			pr_zero(ker2 - uminisz(ull));
		//printf("k=%d %d\n", ker1, ker2);
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if(!(!ker1 && t->tochka && !ker2 && !ull))
			ft_putull(ull);
		//else if (!(t->tochka && !i))
			//ft_putchar(' ');
		//printf(" %d %d\n", ker1, max(ker2 + t->znak, sz));
		if (t->minus && ker1 > (max(ker2 + t->znak, sz) ))
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
	//	printf("hey");
		//printf("sz = %d %d\n", ker1, ker2);
		return (1);
	}
	else if (**ind == 'l' && *(*ind + 1) == 'u')
	{
		*ind += 1;
		ul = va_arg(*g_arg, unsigned long);
		if (t->tochka)
		{
			t->cha = ' ';
			t->nol = 0;
		}
		//printf("%u\n", ul);
		sz = uminisz(ul) + t->znak;
		if (!t->tochka)
			ker2 = sz - 1;
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && !t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), '0');
		if (t->tochka)
			pr_zero(ker2 - uminisz(ul));
		//printf("k=%d %d\n", ker1, ker2);
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if(!(!ker1 && t->tochka && !ker2 && !ul))
			ft_putull(ul);
		//else if (!(t->tochka && !i))
			//ft_putchar(' ');
		//printf(" %d %d\n", ker1, max(ker2 + t->znak, sz));
		if (t->minus && ker1 > (max(ker2 + t->znak, sz) ))
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
	//	printf("hey");
		//printf("sz = %d %d\n", ker1, ker2);
		return (1);
	}
	else if (**ind == 'h' && *(*ind + 1) == 'u')
	{
		*ind += 1;
		ush = va_arg(*g_arg, unsigned int);
		if (t->tochka)
		{
			t->cha = ' ';
			t->nol = 0;
		}
		//printf("%u\n", ush);
		sz = uminisz(ush) + t->znak;
		if (!t->tochka)
			ker2 = sz - 1;
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && !t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), '0');
		if (t->tochka)
			pr_zero(ker2 - uminisz(ush));
		//printf("k=%d %d\n", ker1, ker2);
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if(!(!ker1 && t->tochka && !ker2 && !ush))
			ft_putull(ush);
		//else if (!(t->tochka && !i))
			//ft_putchar(' ');
		//printf(" %d %d\n", ker1, max(ker2 + t->znak, sz));
		if (t->minus && ker1 > (max(ker2 + t->znak, sz) ))
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
	//	printf("hey");
		//printf("sz = %d %d\n", ker1, ker2);
		return (1);
	}
	return (0);
}

int			eleventh_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned char		uc;

	if (**ind == 'h' && *(*ind + 1) == 'h' && *(*ind + 2) == 'x')
	{
		uc = va_arg(*g_arg, int);
		if (!t->tochka)
			ker2 = ft_strlen(ft_converterhh(uc, -16) + 2 * t->hash);
		if (t->tochka)
			t->cha = ' ';
		if (uc != 0 && t->hash && t->cha == '0')
			ft_putstr("0x");
		if (!t->minus && ker1 > max(ker2, ft_strlen(ft_converterhh(uc, -16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2, ft_strlen(ft_converterhh(uc, -16))), t->cha);
		if (uc != 0 && t->hash && t->cha == ' ')
			ft_putstr("0x");
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converterhh(uc, -16)));
		checkprobel(t, uc, ker1);
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if(!(!ker1 && t->tochka && !ker2 && !uc))
			ft_putstr(ft_converterhh(uc, -16));
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converterhh(uc, -16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2, ft_strlen(ft_converterhh(uc, -16))), t->cha);
		(*ind) += 2;
		return (1);
	}
	return (0);
}

int			twelfth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned long long		ull;	

	if (**ind == 'l' && *(*ind + 1) == 'l' && *(*ind + 2) == 'x')
	{
		ull = va_arg(*g_arg, unsigned long long);
		if (!t->tochka)
			ker2 = ft_strlen(ft_converterll(ull, -16) + 2 * t->hash);
		if (t->tochka)
			t->cha = ' ';
		if (ull != 0 && t->hash && t->cha == '0')
			ft_putstr("0x");
		if (!t->minus && ker1 > max(ker2, ft_strlen(ft_converterll(ull, -16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2, ft_strlen(ft_converterll(ull, -16))), t->cha);
		if (ull != 0 && t->hash && t->cha == ' ')
			ft_putstr("0x");
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converterll(ull, -16)));
		checkprobel(t, ull, ker1);
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if(!(!ker1 && t->tochka && !ker2 && !ull))
			ft_putstr(ft_converterll(ull, -16));
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converterll(ull, -16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2, ft_strlen(ft_converterll(ull, -16))), t->cha);
		(*ind) += 2;
		return (1);
	}
	return (0);
}

int			thirteenth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned int		ui;

	if(**ind == 'x')
	{
		ui = va_arg(*g_arg, unsigned int);
		if (!t->tochka)
			ker2 = ft_strlen(ft_converter(ui, -16) + 2 * t->hash);
		if (t->tochka)
			t->cha = ' ';
		if (ui != 0 && t->hash && t->cha == '0')
			ft_putstr("0x");
		if (!t->minus && ker1 > max(ker2, ft_strlen(ft_converter(ui, -16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2, ft_strlen(ft_converter(ui, -16))), t->cha);
		if (ui != 0 && t->hash && t->cha == ' ')
			ft_putstr("0x");
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converter(ui, -16)));
		checkprobel(t, ui, ker1);
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if(!(!ker1 && t->tochka && !ker2 && !ui))
			ft_putstr(ft_converter(ui, -16));
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converter(ui, -16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2, ft_strlen(ft_converter(ui, -16))), t->cha);
		return (1);
	}
	return (0);
}

int			fourteenth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned short		ush;

	if (**ind == 'h' && *(*ind + 1) == 'x')
	{
		ush = va_arg(*g_arg, int);
		if (!t->tochka)
			ker2 = ft_strlen(ft_converterh(ush, -16) + 2 * t->hash);
		if (t->tochka)
			t->cha = ' ';
		if (ush != 0 && t->hash && t->cha == '0')
			ft_putstr("0x");
		if (!t->minus && ker1 > max(ker2, ft_strlen(ft_converterh(ush, -16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2, ft_strlen(ft_converterh(ush, -16))), t->cha);
		if (ush != 0 && t->hash && t->cha == ' ')
			ft_putstr("0x");
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converterh(ush, -16)));
		checkprobel(t, ush, ker1);
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if(!(!ker1 && t->tochka && !ker2 && !ush))
			ft_putstr(ft_converterh(ush, -16));
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converterh(ush, -16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2, ft_strlen(ft_converterh(ush, -16))), t->cha);
		(*ind) += 1;
		return (1);
	}
	return (0);
}

int			fifteenth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned long		ul;

	if (**ind == 'l' && *(*ind + 1) == 'x')
	{
		ul = va_arg(*g_arg, unsigned long);
		//printf("%lx\n", ul);
		if (!t->tochka)
			ker2 = ft_strlen(ft_converterl(ul, -16) + 2 * t->hash);
		if (t->tochka)
			t->cha = ' ';
		if (ul != 0 && t->hash && t->cha == '0')
			ft_putstr("0x");
		if (!t->minus && ker1 > max(ker2, ft_strlen(ft_converterl(ul, -16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2, ft_strlen(ft_converterl(ul, -16))), t->cha);
		if (ul != 0 && t->hash && t->cha == ' ')
			ft_putstr("0x");
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converterl(ul, -16)));
		checkprobel(t, ul, ker1);
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if(!(!ker1 && t->tochka && !ker2 && !ul))
			ft_putstr(ft_converterl(ul, -16));
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converterl(ul, -16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2, ft_strlen(ft_converterl(ul, -16))), t->cha);
		(*ind) += 1;
		return (1);
	}
	return (0);
}

int			sixteenth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned short		ush;

	if (**ind == 'h' && *(*ind + 1) == 'X')
	{
		ush = va_arg(*g_arg, int);
		if (!t->tochka)
			ker2 = ft_strlen(ft_converterh(ush, 16) + 2 * t->hash);
		if (t->tochka)
			t->cha = ' ';
		if (ush != 0 && t->hash && t->cha == '0')
			ft_putstr("0X");
		if (!t->minus && ker1 > max(ker2, ft_strlen(ft_converterh(ush, 16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2, ft_strlen(ft_converterh(ush, 16))), t->cha);
		if (ush != 0 && t->hash && t->cha == ' ')
			ft_putstr("0X");
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converterh(ush, 16)));
		checkprobel(t, ush, ker1);
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if(!(!ker1 && t->tochka && !ker2 && !ush))
			ft_putstr(ft_converterh(ush, 16));
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converterh(ush, 16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2, ft_strlen(ft_converterh(ush, 16))), t->cha);
		(*ind) += 1;
		return (1);
	}
	return (0);
}

int			seventeenth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned long		ul;

	if (**ind == 'l' && *(*ind + 1) == 'X')
	{
		ul = va_arg(*g_arg, unsigned long);
		if (!t->tochka)
			ker2 = ft_strlen(ft_converterl(ul, 16) + 2 * t->hash);
		if (t->tochka)
			t->cha = ' ';
		if (ul != 0 && t->hash && t->cha == '0')
			ft_putstr("0X");
		if (!t->minus && ker1 > max(ker2, ft_strlen(ft_converterl(ul, 16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2, ft_strlen(ft_converterl(ul, 16))), t->cha);
		if (ul != 0 && t->hash && t->cha == ' ')
			ft_putstr("0X");
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converterl(ul, 16)));
		checkprobel(t, ul, ker1);
		if (ul != 0 || !t->tochka || t->hash)
			ft_putstr(ft_converterl(ul, 16));
		else if (!t->hash && ker1 > 0)
			ft_putchar(' ');
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converterl(ul, 16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2, ft_strlen(ft_converterl(ul, 16))), t->cha);
		(*ind) += 1;
		return (1);
	}
	return (0);
}

int			eightteenth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned long long		ull;

	if (**ind == 'l' && *(*ind + 1) == 'l' && *(*ind + 2) == 'X')
	{
		ull = va_arg(*g_arg, unsigned long long);
		if (!t->tochka)
			ker2 = ft_strlen(ft_converterll(ull, 16) + 2 * t->hash);
		if (t->tochka)
			t->cha = ' ';
		if (ull != 0 && t->hash && t->cha == '0')
			ft_putstr("0X");
		if (!t->minus && ker1 > max(ker2, ft_strlen(ft_converterll(ull, 16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2, ft_strlen(ft_converterll(ull, 16))), t->cha);
		if (ull != 0 && t->hash && t->cha == ' ')
			ft_putstr("0X");
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converterll(ull, 16)));
		checkprobel(t, ull, ker1);
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if(!(!ker1 && t->tochka && !ker2 && !ull))
			ft_putstr(ft_converterll(ull, 16));
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converterll(ull, 16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2, ft_strlen(ft_converterll(ull, 16))), t->cha);
		(*ind) += 2;
		return (1);
	}
	return (0);
}

int			nineteenth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned char		uc;
	if (**ind == 'h' && *(*ind + 1) == 'h' && *(*ind + 2) == 'X')
	{
		uc = va_arg(*g_arg, int);
		if (!t->tochka)
			ker2 = ft_strlen(ft_converterhh(uc, 16) + 2 * t->hash);
		if (t->tochka)
			t->cha = ' ';
		if (uc != 0 && t->hash && t->cha == '0')
			ft_putstr("0X");
		if (!t->minus && ker1 > max(ker2, ft_strlen(ft_converterhh(uc, 16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2, ft_strlen(ft_converterhh(uc, 16))), t->cha);
		if (uc != 0 && t->hash && t->cha == ' ')
			ft_putstr("0X");
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converterhh(uc, 16)));
		checkprobel(t, uc, ker1);
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if(!(!ker1 && t->tochka && !ker2 && !uc))
			ft_putstr(ft_converterhh(uc, 16));
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converterhh(uc, 16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2, ft_strlen(ft_converterhh(uc, 16))), t->cha);
		(*ind) += 2;
		return (1);
	}
	return (0);
}

int			twentith_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned int	ui;

	if(**ind == 'X')
	{
		ui = va_arg(*g_arg, unsigned int);
		if (!t->tochka)
			ker2 = ft_strlen(ft_converter(ui, 16) + 2 * t->hash);
		if (t->tochka)
			t->cha = ' ';
		if (ui != 0 && t->hash && t->cha == '0')
			ft_putstr("0X");
		if (!t->minus && ker1 > max(ker2, ft_strlen(ft_converter(ui, 16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2, ft_strlen(ft_converter(ui, 16))), t->cha);
		if (ui != 0 && t->hash && t->cha == ' ')
			ft_putstr("0X");
		if (t->tochka)
			pr_zero(ker2 - ft_strlen(ft_converter(ui, 16)));
		checkprobel(t, ui, ker1);
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if(!(!ker1 && t->tochka && !ker2 && !ui))
			ft_putstr(ft_converter(ui, 16));
		if (t->minus && ker1 > max(ker2, ft_strlen(ft_converter(ui, 16))))
			pr_pre(ker1 - 2 * t->hash, max(ker2, ft_strlen(ft_converter(ui, 16))), t->cha);
		return (1);
	}
	return (0);
}

int			twentyfirst_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned long long	ull;
	unsigned long		ul;
	int					sz;

	if (**ind == 'l' && *(*ind + 1) == 'u')
	{
		ul = va_arg(*g_arg, unsigned long);
		*ind += 1;
		if (t->tochka)
		{
			t->cha = ' ';
			t->nol = 0;
		}
		//printf("%u\n", ul);
		sz = uminisz(ul) + t->znak;
		if (!t->tochka)
			ker2 = sz - 1;
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && !t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
		if (!t->minus && ker1 > (max(ker2 + t->znak, sz)) && t->nol)
			pr_pre(ker1, (max(ker2 + t->znak, sz)), '0');
		if (t->tochka)
			pr_zero(ker2 - uminisz(ul));
		//printf("k=%d %d\n", ker1, ker2);
		if (ker1 && t->tochka && !ker2)
			ft_putchar(' ');
		else if(!(!ker1 && t->tochka && !ker2 && !ul))
			ft_putull(ul);
		//else if (!(t->tochka && !i))
			//ft_putchar(' ');
		//printf(" %d %d\n", ker1, max(ker2 + t->znak, sz));
		if (t->minus && ker1 > (max(ker2 + t->znak, sz) ))
			pr_pre(ker1, (max(ker2 + t->znak, sz)), ' ');
	//	printf("hey");
		//printf("sz = %d %d\n", ker1, ker2);
		return (1);
	}
	else if (**ind == 'l' && *(*ind + 1) == 'l' && *(*ind + 2) == 'b')
	{
		ull = va_arg(*g_arg, unsigned long long);
		if (!t->minus)
			pr_pre(ker1, ft_strlen(ft_converter(ull, 2)), t->cha);
		//uc = i;
		ft_putstr(ft_converter(ull, 2));
		if (t->minus)
			pr_pre(ker1, ft_strlen(ft_converter(ull, 2)), t->cha);
		*ind += 2;
		return (1);
	}
	return (0);
}

int			twentysecond_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned short		ush;
	unsigned long		ul;

	if (**ind == 'h' && *(*ind + 1) == 'b')
	{
		ush = va_arg(*g_arg, int);
		if (!t->minus)
			pr_pre(ker1, ft_strlen(ft_converter(ush, 2)), t->cha);
		ft_putstr(ft_converter(ush, 2));
		if (t->minus)
			pr_pre(ker1, ft_strlen(ft_converter(ush, 2)), t->cha);
		(*ind)++;
		return (1);
	}
	else if (**ind == 'l' && *(*ind + 1) == 'b')
	{
		ul = va_arg(*g_arg, unsigned long);
		if (!t->minus)
			pr_pre(ker1, ft_strlen(ft_converter(ul, 2)), t->cha);
		ft_putstr(ft_converter(ul, 2));
		if (t->minus)
			pr_pre(ker1, ft_strlen(ft_converter(ul, 2)), t->cha);
		(*ind)++;
		return (1);
	}
	return (0);
}

int			twentythird_check(char **ind, t_flags *t, int ker1, int ker2)
{
	unsigned char	uc;
	int				i;	

	if (**ind == 'h' && *(*ind + 1) == 'h' && *(*ind + 2) == 'b')
	{
		uc = va_arg(*g_arg, int);
		if (!t->minus)
			pr_pre(ker1, ft_strlen(ft_converter(uc, 2)), t->cha);
			ft_putstr(ft_converter(uc, 2));
		if (t->minus)
			pr_pre(ker1, ft_strlen(ft_converter(uc, 2)), t->cha);
		*ind += 2;
		return (1);
	}
	else if(**ind == 'b')
	{
		i = va_arg(*g_arg, int);
		if (!t->minus)
			pr_pre(ker1, ft_strlen(ft_converter(i, 2)), t->cha);
		ft_putstr(ft_converter(i, 2));
		if (t->minus)
			pr_pre(ker1, ft_strlen(ft_converter(i, 2)), t->cha);
		return (1);
	}
	return (0);
}


int			twentyfourth_check(char **ind, t_flags *t, int ker1, int ker2)
{
	int		i;

	while (**ind != '\0')
	{
		if (**ind == '%')
		{
			i = 0;
			if (!t->minus)
				while (i++ < ker1 - 1)
					ft_putchar(t->cha);
			ft_putchar('%');
			if (t->minus)
				while (i++ < ker1 - 1)
					ft_putchar(t->cha);
			break ;
		}
		(*ind)++;
	}
	if (**ind == '\0')
		return (-1);
	return (0);
}

void		zapusk2(char **ind, t_flags *t, int ker1, int ker2)
{
	int	sum;

	sum = 0;
	if (!sum)
		sum += twelfth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += thirteenth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += fourteenth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += fifteenth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += sixteenth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += seventeenth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += eightteenth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += nineteenth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += twentith_check(ind, t, ker1, ker2);
	if (!sum)
		sum += twentyfirst_check(ind, t, ker1, ker2);
	if (!sum)
		sum += twentysecond_check(ind, t, ker1, ker2);
	if (!sum)
		sum += twentythird_check(ind, t, ker1, ker2);
	if (!sum)
		sum += twentyfourth_check(ind, t, ker1, ker2);
}
void		zapusk(char **ind, t_flags *t, int ker1, int ker2)
{
	int	sum;

	sum = 0;
	sum += first_check(ind, t, ker1, ker2);
	if (!sum)
		sum += second_check(ind, t, ker1, ker2);
	if (!sum)
		sum += third_check(ind, t, ker1, ker2);
	if (!sum)
		sum += fourth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += fifth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += sixth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += seventh_check(ind, t, ker1, ker2);
	if (!sum)
		sum += eighth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += ninth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += tenth_check(ind, t, ker1, ker2);
	if (!sum)
		sum += eleventh_check(ind, t, ker1, ker2);
	if (!sum)
		zapusk2(ind, t, ker1, ker2);
}

int			ft_printf(char* ind, ...)
{
	int					ker1;
	int					ker2;
	va_list				arg;
	t_flags				t;

	va_start(arg, ind);
	g_arg = &arg;
	ker1 = 0;
	ker2 = 6;
	while (*ind != '\0')
	{
		clearflags(&t);
		//printf("%d\n", t.hash);
		while (*ind != '%' && *ind != '\0')
		{
			ft_putchar(*ind);
			ind++;
		}
		if((*ind) == '\0')
			break;
		ind++;
		while (beginning(&ind, &t))
			ind++;
		ker1 = ft_atoi(ind);
		while (*ind >= '0' && *ind <= '9')
			ind++;
		if (*ind == '.')
			t.tochka = 1;
		ker2 = t.tochka ? ft_atoi(ind) : 0;
		while (*ind >= '0' && *ind <= '9')
			ind++;
		//printf("%c ", *ind);
		//printf("hello\n");
		if (kereksan(&t, &ind, &ker1, &ker2) == -1)
			break;
		if(*ind == '\0')
			break;
		//printf("%d %d\n", ker1, ker2);
		zapusk(&ind, &t, ker1, ker2);
		ind++;
	}
	va_end(arg);
	return (g_cnt);
}