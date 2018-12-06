/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 22:34:28 by samukano          #+#    #+#             */
/*   Updated: 2018/11/10 22:34:28 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	itn;
	char	*q1;
	char	*it2;

	if (!*needle)
		return ((void *)haystack);
	while (len-- && *haystack)
	{
		if (*haystack == *needle)
		{
			itn = len;
			q1 = (void *)haystack + 1;
			it2 = (void *)needle + 1;
			while (itn-- && *q1 && *it2 && *q1 == *it2)
			{
				++q1;
				++it2;
			}
			if (!*it2)
				return ((void *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
