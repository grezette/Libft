/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:56:16 by grezette          #+#    #+#             */
/*   Updated: 2019/11/10 17:10:42 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	size;

	size = 1;
	if (s1)
		size = ft_strlen(s1) + 1;
	if (s2)
		size += ft_strlen(s2);
	if (!(join = (char *)malloc(sizeof(*join) * size)))
		return (NULL);
	if (s1)
		ft_memcpy(join, s1, ft_strlen(s1));
	if (s2)
		ft_memcpy(&join[size - ft_strlen(s2) - 1], s2, ft_strlen(s2));
	join[size - 1] = 0;
	return (join);
}
