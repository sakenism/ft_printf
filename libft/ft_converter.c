/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conerter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:07:58 by samukano          #+#    #+#             */
/*   Updated: 2018/11/30 14:07:58 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_converter(unsigned int num, int base) 
{
	char Representation[22];
	static char buffer[100]; 
	int	i;
	char *ptr; 

	ptr = &buffer[99]; 
	*ptr = '\0'; 
	i = 0;
	while (i < 10)
	{
		Representation[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		if(base > 0)
			Representation[i] = i - 10 + 'A';
		else
			Representation[i] = i - 10 + 'a';
		i++;
	}
	if (base < 0)
		base = -base;
	i = 0;
	/*while (i < 16)
	{
		ft_putchar(Representation[i]);
		i++;
	}*/
	do 
	{
		*--ptr = Representation[num % base];
		//printf("%c ", Representation[num % base]);
		//printf("%d ", num / base);
		num /= base;
	} while(num != 0);
	return (ptr);
}

char	*ft_converterll(unsigned long long num, int base) 
{
	char Representation[22];
	static char buffer[100]; 
	int	i;
	char *ptr; 

	ptr = &buffer[99]; 
	*ptr = '\0'; 
	i = 0;
	while (i < 10)
	{
		Representation[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		if(base > 0)
			Representation[i] = i - 10 + 'A';
		else
			Representation[i] = i - 10 + 'a';
		i++;
	}
	if (base < 0)
		base = -base;
	i = 0;
	/*while (i < 16)
	{
		ft_putchar(Representation[i]);
		i++;
	}*/
	do 
	{
		*--ptr = Representation[num % base];
		//printf("%c ", Representation[num % base]);
		//printf("%d ", num / base);
		num /= base;
	} while(num != 0);
	return (ptr);
}

char	*ft_converterhh(unsigned char num, int base) 
{
	char Representation[22];
	static char buffer[100]; 
	int	i;
	char *ptr; 

	ptr = &buffer[99]; 
	*ptr = '\0'; 
	i = 0;
	while (i < 10)
	{
		Representation[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		if(base > 0)
			Representation[i] = i - 10 + 'A';
		else
			Representation[i] = i - 10 + 'a';
		i++;
	}
	if (base < 0)
		base = -base;
	i = 0;
	/*while (i < 16)
	{
		ft_putchar(Representation[i]);
		i++;
	}*/
	do 
	{
		*--ptr = Representation[num % base];
		//printf("%c ", Representation[num % base]);
		//printf("%d ", num / base);
		num /= base;
	} while(num != 0);
	return (ptr);
}

char	*ft_converterh(unsigned short num, int base) 
{
	char Representation[22];
	static char buffer[100]; 
	int	i;
	char *ptr; 

	ptr = &buffer[99]; 
	*ptr = '\0'; 
	i = 0;
	while (i < 10)
	{
		Representation[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		if(base > 0)
			Representation[i] = i - 10 + 'A';
		else
			Representation[i] = i - 10 + 'a';
		i++;
	}
	if (base < 0)
		base = -base;
	i = 0;
	/*while (i < 16)
	{
		ft_putchar(Representation[i]);
		i++;
	}*/
	do 
	{
		*--ptr = Representation[num % base];
		//printf("%c ", Representation[num % base]);
		//printf("%d ", num / base);
		num /= base;
	} while(num != 0);
	return (ptr);
}

char	*ft_converterl(unsigned long num, int base) 
{
	char Representation[22];
	static char buffer[100]; 
	int	i;
	char *ptr; 

	ptr = &buffer[99]; 
	*ptr = '\0'; 
	i = 0;
	while (i < 10)
	{
		Representation[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		if(base > 0)
			Representation[i] = i - 10 + 'A';
		else
			Representation[i] = i - 10 + 'a';
		i++;
	}
	if (base < 0)
		base = -base;
	i = 0;
	/*while (i < 16)
	{
		ft_putchar(Representation[i]);
		i++;
	}*/
	do 
	{
		*--ptr = Representation[num % base];
		//printf("%c ", Representation[num % base]);
		//printf("%d ", num / base);
		num /= base;
	} while(num != 0);
	return (ptr);
}

