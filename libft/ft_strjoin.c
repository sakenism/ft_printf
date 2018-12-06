/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 23:48:40 by samukano          #+#    #+#             */
/*   Updated: 2018/11/10 23:48:40 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	k = 0;
	new = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (*(s1 + i))
	{
		*(new + k++) = *(s1 + i++);
	}
	i = 0;
	while (*(s2 + i))
	{
		*(new + k++) = *(s2 + i++);
	}
	*(new + k) = '\0';
	return (new);
}
