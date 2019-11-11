/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:32:26 by grezette          #+#    #+#             */
/*   Updated: 2019/11/10 15:23:11 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t sn;

	if (!(src))
	{
		dst = NULL;
		return (0);
	}
	sn = ft_strlen(src);
	if (sn + 1 < dstsize)
		ft_memcpy(dst, src, sn + 1);
	else if (dstsize)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	return (sn);
}
