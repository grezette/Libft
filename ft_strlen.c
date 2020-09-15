/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:33:22 by grezette          #+#    #+#             */
/*   Updated: 2020/08/01 16:25:18 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (!s[i + 1])
			return (i + 1);
		if (!s[i + 2])
			return (i + 2);
		if (!s[i + 3])
			return (i + 3);
		if (!s[i + 4])
			return (i + 4);
		if (!s[i + 5])
			return (i + 5);
		if (!s[i + 6])
			return (i + 6);
		if (!s[i + 7])
			return (i + 7);
		i += 8;
	}
	return (i);
}
