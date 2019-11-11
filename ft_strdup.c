/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:33:15 by grezette          #+#    #+#             */
/*   Updated: 2019/11/10 17:02:41 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(*str) * (ft_strlen(s1) + 1))))
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1) + 1);
	return (str);
}
