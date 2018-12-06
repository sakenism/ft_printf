/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:43:00 by samukano          #+#    #+#             */
/*   Updated: 2018/11/12 13:43:00 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int n)
{
	int	nb;

	nb = 0;
	if (n < 0)
		return (-1);
	while (nb * nb <= n)
	{
		if (nb * nb == n)
			return (nb);
		nb++;
	}
	return (nb);
}
