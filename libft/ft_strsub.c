/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 23:45:38 by samukano          #+#    #+#             */
/*   Updated: 2018/11/10 23:45:38 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*sb;

	sb = (char*)malloc(sizeof(char) * (len + 1));
	if (!sb || !s)
		return (NULL);
	i = 0;
	while (len--)
	{
		*(sb + i) = s[start + i];
		i++;
	}
	sb[i] = '\0';
	return (sb);
}
