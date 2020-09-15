/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 23:16:02 by grezette          #+#    #+#             */
/*   Updated: 2020/01/04 12:10:21 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libftprintf.h"

int			ft_secur(va_list *ap)
{
	va_end(*ap);
	return (-1);
}

int			ft_conv_p(va_list *ap, t_struct *var)
{
	char	*s;
	char	*tmp;
	int		len;

	if (!(s = ft_itoa_base((long long)va_arg(*ap, void *), "0123456789abcdef")))
		return (ft_secur(ap));
	tmp = s;
	len = (int)ft_strlen(s) + 2;
	while (var->bfor-- > len)
		var->len += write(1, " ", 1);
	var->len += write(1, "0x", 2);
	while (*s && var->pres--)
		var->len += write(1, s++, 1);
	while (var->aftr-- > len)
		var->len += write(1, " ", 1);
	free(tmp);
	tmp = NULL;
	return (0);
}

int			ft_conv_c_prct(va_list *ap, t_struct *var, unsigned char c)
{
	c = (c == 'c') ? va_arg(*ap, int) : '%';
	if (var->bfor > -1 || var->pres > -1)
		while (var->bfor-- > 1 || var->zero-- > 1)
			var->len += write(1, " ", 1);
	while (var->zero-- > 1)
		var->len += write(1, "0", 1);
	var->len += write(1, &c, 1);
	while (var->aftr-- > 1)
		var->len += write(1, " ", 1);
	return (0);
}

int			ft_conv_s(va_list *ap, t_struct *var)
{
	char	*s;
	int		len;

	s = va_arg(*ap, char *);
	var->pres = (var->pres < -1) ? -1 : var->pres;
	len = var->pres;
	if (!s)
		s = "(null)";
	if ((int)ft_strlen(s) < var->pres || var->pres == -1)
		len = ft_strlen(s);
	if (var->zero > -1)
		return (ft_secur(ap));
	while (var->bfor-- > len)
		var->len += write(1, " ", 1);
	while (s && *s && var->pres--)
		var->len += write(1, s++, 1);
	while (var->aftr-- > len)
		var->len += write(1, " ", 1);
	return (0);
}
