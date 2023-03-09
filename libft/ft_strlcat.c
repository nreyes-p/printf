/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreyes-p <nreyes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:15:36 by nreyes-p          #+#    #+#             */
/*   Updated: 2023/01/22 14:20:47 by nreyes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	dst_l;
	size_t	i;
	size_t	src_l;

	dst_l = ft_strlen(dest);
	src_l = ft_strlen(src);
	i = 0;
	if (size)
	{
		while (src[i] != '\0' && (i + dst_l) < (size - 1))
		{
			dest[dst_l + i] = src[i];
			i++;
		}
		dest[dst_l + i] = '\0';
		if (dst_l < size)
			return (dst_l + src_l);
	}
	else
		return (src_l);
	return (size + src_l);
}
