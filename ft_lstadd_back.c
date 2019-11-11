/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:59:10 by grezette          #+#    #+#             */
/*   Updated: 2019/11/09 16:32:42 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *lst;

	if (!(*alst))
		*alst = new;
	else
	{
		lst = *alst;
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
}
