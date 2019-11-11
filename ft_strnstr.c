/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:33:36 by grezette          #+#    #+#             */
/*   Updated: 2019/11/10 17:06:14 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	if (!haystack && !len)
		return (0);
	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len && len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && haystack[i + j] && i + j < len)
		{
			if (!(needle[j + 1]))
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
