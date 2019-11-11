/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:20:44 by grezette          #+#    #+#             */
/*   Updated: 2019/11/10 14:16:30 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char			*d;
	char			*s;
	unsigned int	dn;
	unsigned int	sn;

	d = dst;
	s = (char *)src;
	dn = 0;
	sn = 0;
	if (!dst && !dstsize)
		return (ft_strlen(src));
	while (s[sn])
		sn++;
	while (*d)
	{
		d++;
		if ((unsigned long)(d - dst) >= dstsize)
			return (dstsize + sn);
	}
	dn = d - dst;
	while (*s && (unsigned long)(d - dst) < dstsize - 1)
		*d++ = *s++;
	*d = 0;
	return (dn + sn);
}
