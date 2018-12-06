/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 23:34:48 by samukano          #+#    #+#             */
/*   Updated: 2018/11/10 23:34:48 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mp;

	if (f == NULL || s == NULL)
		return (NULL);
	mp = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!mp)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mp[i] = f(i, s[i]);
		i++;
	}
	mp[i] = '\0';
	return (mp);
}
