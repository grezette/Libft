/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:28:47 by grezette          #+#    #+#             */
/*   Updated: 2019/11/10 16:28:49 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char			*d;
	const char		*s;
	const char		*ends;
	char			*endd;

	d = dst;
	s = src;
	if (d == 0 && s == 0)
		return (dst);
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
	{
		ends = s + (n - 1);
		endd = d + (n - 1);
		while (n--)
			*endd-- = *ends--;
	}
	return (dst);
}
