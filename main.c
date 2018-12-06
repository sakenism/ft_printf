/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:50:08 by samukano          #+#    #+#             */
/*   Updated: 2018/11/30 13:50:08 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <math.h>

#define maxint 4242424242424242424242
int main()
{
	char c = '!';
	char *a = "sakenism\0";
	long long q = -42;
	int d = 1000001;
	int cnt = 0;
	int	cnnt = 0;
	//char *point = ft_converter(q, 16);
	double *p;
	long double e = (long double)(3.000000000000052);
	float db = 9998.543123521;
	//cnt =  printf("sakenism\n");
	
	//printf("%0+5d\n", 42);
	//ft_printf("%3.2d", -1);
	printf("u@moulitest: %.d %.0d\n", 42, 43);
	ft_printf("m@moulitest: %.d %.0d\n", 42, 43);
	//ft_printf("m%8.10o\n", 42);

	//cnt = printf("@moulitest: %#.o %#.0o\n", 0, 0);
	//cnnt = ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
	//printf("%d", ft_cnt_memory(p));
	
	//cnt = ft_printf("%x\n", -42);
	//printf("\n");
	//ft_printf("\n");
	//ft_print_memory(p);
	//printf("\n");
	//ft_printf("%15.15f", db);
	//printf("%d %d", cnt, cnnt);
	//system("leaks a.out");
}
