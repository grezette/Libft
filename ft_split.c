/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:07:45 by grezette          #+#    #+#             */
/*   Updated: 2019/11/10 15:17:10 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_split3(char const *s, char c, int *i)
{
	char	*split;
	int		j;
	int		k;

	j = *i;
	k = 0;
	while (s[*i] != c && s[*i])
		*i = *i + 1;
	if (!(split = (char *)malloc(sizeof(*split) * (*i - j + 1))))
		return (NULL);
	while (k + j < *i)
	{
		split[k] = s[j + k];
		k++;
	}
	split[k] = 0;
	return (split);
}

static char	**ft_split2(char const *s, char c, int len)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(split = (char **)malloc(sizeof(*split) * (len + 1))))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		split[j] = ft_split3(s, c, &i);
		j++;
		while (s[i] == c && s[i])
			i++;
	}
	split[j] = NULL;
	return (split);
}

char		**ft_split(char const *s, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (!(s))
		return (NULL);
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == 0) && s[i] != c)
			len++;
		i++;
	}
	return (ft_split2(s, c, len));
}
