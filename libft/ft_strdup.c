/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:19:17 by samukano          #+#    #+#             */
/*   Updated: 2018/11/10 12:19:18 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		n;
	char	*ans;

	n = 0;
	while (*(n + s1))
	{
		n++;
	}
	ans = (char*)malloc((n + 1));
	if (ans != NULL)
	{
		n = 0;
		while (*(n + s1))
		{
			*(ans + n) = *(s1 + n);
			n++;
		}
		*(ans + n) = '\0';
	}
	return (ans);
}
