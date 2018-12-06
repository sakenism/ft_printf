/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 12:53:52 by samukano          #+#    #+#             */
/*   Updated: 2018/11/11 12:53:52 by samukano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strndup(const char *s1, size_t n)
{
	char	*cpy;

	if (!(cpy = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	ft_strncpy(cpy, s1, n);
	cpy[n] = '\0';
	return (cpy);
}

static size_t	ft_wordcount(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_wordcount(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	tab[len] = NULL;
	i = 0;
	while (*s)
	{
		len = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			s++;
			len++;
		}
		if (*s || (!*s && len))
			tab[i++] = ft_strndup(s - len, len);
	}
	return (tab);
}
