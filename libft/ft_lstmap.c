/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tithan <tithan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:44:17 by nreyes-p          #+#    #+#             */
/*   Updated: 2023/02/14 17:05:06 by tithan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*new;
	void	*content;

	res = NULL;
	if (f == NULL || lst == NULL || del == NULL)
		return (0);
	while (lst)
	{
		content = f(lst->content);
		if (!content)
			break ;
		new = ft_lstnew(content);
		if (!new)
			break ;
		ft_lstadd_back(&res, new);
		lst = lst->next;
	}
	if (lst)
	{
		ft_lstclear(&res, del);
		del(content);
		return (0);
	}
	return (res);
}
