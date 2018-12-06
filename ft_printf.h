/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuliia <myuliia@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:13:22 by myuliia           #+#    #+#             */
/*   Updated: 2018/11/18 19:52:46 by myuliia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>

# define UI unsigned int
# define maxll -9223372036854775808

typedef struct			s_flags
{
	int					nol;
	int					znak;
	int					tochka;
	int					cnt;
	int					minus;
	int					hash;
	int					probel;
	int					ker1;
	int					ker2;
	int					sign;
	char				cha;
}						t_flags;

int					ft_printf(char* str, ...);
void				ft_putfloat(int ker1, int n, double f, char cha, int minus, int hash);
int					minisz(long long n);
void				cnt_puts(void);
int					uminisz(unsigned long long n);
void				cnt_dec(void);
long long			max(long long a, long long b);

#endif
