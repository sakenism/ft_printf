/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 23:38:21 by samukano          #+#    #+#             */
/*   Updated: 2018/11/10 23:38:22 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (*(s1 + i))
	{
		if (*(s1 + i) != *(s2 + i))
			return (0);
		i++;
	}
	if (*(s2 + i) == '\0')
		return (1);
	return (0);
}
