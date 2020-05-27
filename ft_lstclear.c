/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:38:24 by grezette          #+#    #+#             */
/*   Updated: 2019/11/10 14:01:20 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *l;
	t_list *tmp;

	l = *lst;
	if (lst)
	{
		while (l)
		{
			(*del)(l->content);
			tmp = l;
			l = l->next;
			free(tmp);
		}
		*lst = NULL;
	}
}
