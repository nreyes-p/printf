/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tithan <tithan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:03:01 by nreyes-p          #+#    #+#             */
/*   Updated: 2023/02/14 13:38:12 by tithan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_getlen(char const *s, char c)
{
	size_t	i;
	int		words;

	i = 0;
	words = 0;
	while (i < ft_strlen(s) && s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			words++;
		}
	}
	return (words);
}

static void	ft_freemem(char **res, int i)
{
	while (i >= 0)
	{
		if (res[i])
			free(res[i]);
		i--;
	}
	free(res);
}

static char	**ft_dosplit(char const *s, char c, char **res)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			while (*s != c && *s != '\0' && i++ >= 0)
				s++;
			res[n++] = ft_substr((s - (i - 1)), 0, (i - 1));
			if (!res[n - 1])
			{
				ft_freemem(res, (n - 1));
				return (NULL);
			}
			i = 1;
		}
		else
			s++;
	}
	res[n] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (0);
	res = (char **)malloc((ft_getlen(s, c) + 1) * sizeof(s));
	if (!res)
		return (NULL);
	res = ft_dosplit(s, c, res);
	return (res);
}
