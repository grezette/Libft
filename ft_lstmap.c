/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:37:04 by grezette          #+#    #+#             */
/*   Updated: 2019/11/10 10:16:32 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *map;
	t_list *pam;

	if (!(lst) || !(f))
		return (0);
	pam = ft_lstnew((*f)(lst->content));
	map = pam;
	while (lst->next)
	{
		lst = lst->next;
		map->next = ft_lstnew((*f)(lst->content));
		if (!(map->next))
		{
			ft_lstclear(&pam, del);
			return (0);
		}
		map = map->next;
	}
	map->next = 0;
	return (pam);
}
