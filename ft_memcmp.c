/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:32:37 by grezette          #+#    #+#             */
/*   Updated: 2019/11/09 14:44:02 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char *one;
	unsigned const char *tow;
	size_t				i;

	if (!(n))
		return (0);
	one = s1;
	tow = s2;
	i = 0;
	while (i < n - 1 && one[i] == tow[i])
		i++;
	return ((int)(one[i] - tow[i]));
}
