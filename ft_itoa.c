/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:30:42 by grezette          #+#    #+#             */
/*   Updated: 2019/11/10 11:57:00 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*rev_itoa(char *itoa)
{
	size_t	i;
	size_t	j;
	char	tmp;

	i = 0;
	j = ft_strlen(itoa) - 1;
	if (itoa[0] == '-')
		i++;
	while (i < j)
	{
		tmp = itoa[i];
		itoa[i] = itoa[j];
		itoa[j] = tmp;
		i++;
		j--;
	}
	return (itoa);
}

static int	size_itoa(int n)
{
	int len;

	len = 0;
	if (n == -2147483648)
		return (12);
	else if (n == 0)
		return (2);
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
	return (len + 1);
}

char		*ft_itoa(int n)
{
	char			*itoa;
	unsigned int	nbr;
	int				i;

	i = 0;
	if (!(itoa = (char *)malloc(sizeof(*itoa) * size_itoa(n))))
		return (NULL);
	if (n == 0)
		itoa[i++] = '0';
	if (n < 0)
	{
		itoa[i++] = '-';
		n = n * -1;
	}
	nbr = n;
	while (nbr)
	{
		itoa[i++] = nbr % 10 + '0';
		nbr /= 10;
	}
	itoa[i] = 0;
	itoa = rev_itoa(itoa);
	return (itoa);
}
