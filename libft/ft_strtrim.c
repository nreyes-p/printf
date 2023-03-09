/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreyes-p <nreyes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:17:54 by nreyes-p          #+#    #+#             */
/*   Updated: 2023/01/24 20:00:48 by nreyes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_totrim(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = ft_strlen(s1);
	while (i < len && ft_totrim(s1[i], set))
		i++;
	while (i < len && ft_totrim(s1[len - 1], set))
		len--;
	res = ft_substr(s1, i, (len - i));
	if (res == NULL)
		return (0);
	return (res);
}
