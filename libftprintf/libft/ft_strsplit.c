/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:32:01 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/05/08 13:32:05 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words_num(char const *s, char c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c && *s)
				s++;
			i++;
		}
		else
			s++;
	}
	return (i);
}

char		*ft_str_fill(char const *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_strequal_c(char const *s, char c)
{
	while (*s == c && *s)
		s++;
	return ((char *)s);
}

static char	*ft_strnequal_c(char const *s, char c)
{
	while (*s != c && *s)
		s++;
	return ((char *)s);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = ft_words_num(s, c);
	str = (char **)malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (j < i)
	{
		s = ft_strequal_c(s, c);
		str[j] = ft_str_fill(s, c);
		j++;
		s = ft_strnequal_c(s, c);
	}
	str[j] = NULL;
	return (str);
}
