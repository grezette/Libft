/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 01:39:21 by grezette          #+#    #+#             */
/*   Updated: 2020/01/04 16:06:12 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_rev_char(char *s)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	j = ft_strlen(s) - 1;
	if (s[i] == '-')
		i++;
	while (i < j)
	{
		tmp = s[i];
		s[i++] = s[j];
		s[j--] = tmp;
	}
	return (s);
}

static int		ft_intlen(long long int n)
{
	int len;

	len = 0;
	if (!n)
		return (0);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa_base(long long int n, char *s)
{
	char	*itoa;
	int		i;

	i = 0;
	if (!(itoa = (char *)malloc(sizeof(*itoa) * (ft_intlen(n) + 1))))
		return (NULL);
	if (n < 0)
	{
		itoa[i++] = '-';
		n *= -1;
	}
	if (n == 0)
		itoa[i++] = s[0];
	while (n > 0)
	{
		itoa[i++] = s[n % (int)ft_strlen(s)];
		n /= ft_strlen(s);
	}
	itoa[i] = 0;
	itoa = ft_rev_char(itoa);
	return (itoa);
}
