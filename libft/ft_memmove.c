/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreyes-p <nreyes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:53:17 by nreyes-p          #+#    #+#             */
/*   Updated: 2023/01/19 19:23:18 by nreyes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*a;
	const char	*b;
	int			i;

	a = dest;
	b = src;
	i = 0;
	if ((a > b) && (a - b) < (int)n)
	{
		i = n - 1;
		while (i >= 0)
		{
			a[i] = b[i];
			i--;
		}
	}
	else if (a != b && n > 0)
	{
		while (i < (int)n)
		{
			a[i] = b[i];
			i++;
		}
	}
	return (dest);
}
