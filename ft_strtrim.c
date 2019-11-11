/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:15:23 by grezette          #+#    #+#             */
/*   Updated: 2019/11/10 17:11:19 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, const char *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

static int	trim_len(char const *s1, char const *set)
{
	size_t begin;
	size_t end;

	begin = 0;
	end = ft_strlen(s1) - 1;
	while (!(is_set(s1[begin], set)) && s1[begin])
		begin++;
	while (!(is_set(s1[end], set)) && end >= 0)
		end--;
	return (end - begin + 1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	i;

	i = 0;
	if (!(s1))
		return (NULL);
	while (!(is_set(s1[i], set)) && s1[i])
		i++;
	if (i >= ft_strlen(s1))
		return (trim = (char *)ft_calloc(1, 1));
	if (!(trim = (char *)malloc(sizeof(*trim) * (trim_len(s1, set) + 1))))
		return (NULL);
	ft_memcpy(trim, &s1[i], trim_len(s1, set));
	trim[trim_len(s1, set)] = 0;
	return (trim);
}
