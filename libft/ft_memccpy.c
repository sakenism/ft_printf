/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:44:02 by samukano          #+#    #+#             */
/*   Updated: 2018/11/10 11:44:02 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,
const void *restrict src, int c, size_t n)
{
	unsigned char *s;
	unsigned char *d;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (n--)
		if ((*d++ = *s++) == (unsigned char)c)
			return (d);
	return (NULL);
}
