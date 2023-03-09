/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreyes-p <nreyes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:09:25 by nreyes-p          #+#    #+#             */
/*   Updated: 2023/02/07 18:38:27 by nreyes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		if (little[n] == big[i])
		{
			while (i < len && big[i] != '\0' && little[n] == big[i])
			{
				if (n == ft_strlen(little) - 1)
					return ((char *)(big + i - n));
				n++;
				i++;
			}
			i -= n;
			n = 0;
		}
		i++;
	}
	return (0);
}
