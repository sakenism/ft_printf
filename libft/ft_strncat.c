/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 22:12:57 by samukano          #+#    #+#             */
/*   Updated: 2018/11/10 22:12:57 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*ptr;

	ptr = s1 + ft_strlen(s1);
	while (*s2 && n--)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (s1);
}
