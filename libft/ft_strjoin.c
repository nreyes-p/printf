/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nreyes-p <nreyes-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:08:21 by nreyes-p          #+#    #+#             */
/*   Updated: 2023/01/24 19:16:43 by nreyes-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*res;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc((len1 + len2 + 1) * sizeof(*s1));
	if (res == NULL)
		return (0);
	ft_strlcpy(res, s1, (len1 + 1));
	ft_strlcat(res, (char *)s2, (len1 + len2 + 1));
	return (res);
}
