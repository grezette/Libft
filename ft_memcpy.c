/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:46 by grezette          #+#    #+#             */
/*   Updated: 2019/11/10 16:19:39 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned const char *s;
	unsigned char		*d;

	if (!(src) && !(dst))
		return (NULL);
	s = src;
	d = dst;
	while (n--)
		*d++ = *s++;
	return (dst);
}
