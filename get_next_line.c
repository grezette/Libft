/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:03:15 by grezette          #+#    #+#             */
/*   Updated: 2020/01/26 13:42:27 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_that_line(char **line, char *buff, int fctr, int len)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = *line;
	i = -1;
	j = -1;
	if (!(*line = (char *)malloc(sizeof(**line) * (BUFFER_SIZE * fctr + 1))))
	{
		free(tmp);
		return (-1);
	}
	while (tmp && tmp[++i])
		(*line)[i] = tmp[i];
	i = (i < 0) ? 0 : i;
	while (++j < len)
		(*line)[i + j] = buff[j];
	(*line)[i + j] = 0;
	j = (buff[j]) ? j + 1 : j;
	i = 0;
	while (buff[j])
		buff[i++] = buff[j++];
	buff[i] = 0;
	free(tmp);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1];
	int			len;
	int			fctr;
	int			ret;

	fctr = 0;
	ret = 1;
	if (!(*line = NULL) && (BUFFER_SIZE < 1 || read(fd, buff, 0)))
		return (-1);
	while (ret)
	{
		if (!(buff[0]))
		{
			ret = read(fd, buff, BUFFER_SIZE);
			buff[ret] = 0;
		}
		len = 0;
		while (buff[len] && buff[len] != '\n')
			len++;
		if (buff[len] == '\n')
			return (ft_get_that_line(line, buff, ++fctr, len));
		if (ft_get_that_line(line, buff, ++fctr, len) == -1)
			return (-1);
	}
	return (0);
}
