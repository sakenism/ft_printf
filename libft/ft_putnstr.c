/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 21:51:07 by samukano          #+#    #+#             */
/*   Updated: 2018/12/02 21:51:08 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char const *s, int ker1, int ker2, char cha, int minus)
{
	int	i;
	int	san;

	i = 0;
	if (!s)
		return ;
	san = (ker2 > ft_strlen(s) ? ft_strlen(s) : ker2);
	while (ker1 > i + san && !minus)
	{
		ft_putchar(cha);
		i++;
	}
	i = 0;
	while (*(s + i) && ker2 > 0)
	{
		ker2--;
		ft_putchar(*(s + i));
		i++;
	}
	i = 0;
	while (ker1 > i + san && minus)
	{
		ft_putchar(cha);
		i++;
	}
}
