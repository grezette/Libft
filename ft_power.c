/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:35:21 by grezette          #+#    #+#             */
/*   Updated: 2020/02/15 19:35:22 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_power(float nb, int power)
{
	float ret;

	ret = nb;
	if (!(power))
		return (1);
	else if (power > 0)
		while (power--)
			ret *= nb;
	else
		while (power++)
			ret /= nb;
	return (ret);
}
