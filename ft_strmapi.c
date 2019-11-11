/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:55:01 by grezette          #+#    #+#             */
/*   Updated: 2019/11/10 15:18:11 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapi;
	int		i;

	i = 0;
	if (!(s))
		return (NULL);
	if (!(mapi = (char *)malloc(sizeof(*mapi) * (ft_strlen(s) + 1))))
		return (0);
	while (s[i])
	{
		mapi[i] = (*f)(i, s[i]);
		i++;
	}
	mapi[i] = 0;
	return (mapi);
}
