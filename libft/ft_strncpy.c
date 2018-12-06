/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:41:13 by samukano          #+#    #+#             */
/*   Updated: 2018/11/10 12:41:13 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && *(src + i))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if (*(src + i) == '\0')
		while (i < len)
			*(dst + i++) = '\0';
	return (dst);
}
