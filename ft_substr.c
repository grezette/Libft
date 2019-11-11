/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:19:35 by grezette          #+#    #+#             */
/*   Updated: 2019/11/10 17:09:50 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;

	if (!(s))
		return (NULL);
	if (start > ft_strlen(s))
		return (str = (char *)ft_calloc(1, 1));
	size = ft_strlen(&s[start]) + 1;
	if (size > len)
		size = len;
	if (!(str = (char *)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	ft_memcpy(str, &s[start], size);
	str[size] = 0;
	return (str);
}
