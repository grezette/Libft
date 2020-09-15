/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_diuxx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 16:56:44 by grezette          #+#    #+#             */
/*   Updated: 2020/01/01 17:30:52 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libftprintf.h"

static int	ft_dirty(char *s, t_struct *var)
{
	int len;

	if (s[0] == '0' && var->pres == 0)
	{
		len = 0;
		return (len);
	}
	if (s[0] == '-')
		len = ((int)ft_strlen(s) - 1 > var->pres) ?
			(int)ft_strlen(s) : var->pres + 1;
	else
		len = ((int)ft_strlen(s) > var->pres) ? (int)ft_strlen(s) : var->pres;
	return (len);
}

static int	ft_conv_diuxx_2(t_struct *var, char *s)
{
	char	*tmp;
	int		len;
	int		nblen;

	tmp = s;
	len = ft_dirty(s, var);
	if (var->bfor > -1 || var->pres > -1)
		while (var->bfor-- > len || var->zero-- > len)
			var->len += write(1, " ", 1);
	if (s[0] == '-')
		var->len += write(1, s++, 1);
	while (var->zero-- > len)
		var->len += write(1, "0", 1);
	nblen = ft_strlen(s);
	while (var->pres-- > nblen)
		var->len += write(1, "0", 1);
	while (*s && len)
		var->len += write(1, s++, 1);
	while (var->aftr-- > len)
		var->len += write(1, " ", 1);
	free(tmp);
	tmp = NULL;
	return (0);
}

int			ft_conv_diuxx(va_list *ap, t_struct *var, unsigned char c)
{
	char	*s;

	if (!var->blpr)
		var->pres = -1;
	if (c == 'd' || c == 'i')
		if (!(s = ft_itoa_base(va_arg(*ap, int), "0123456789")))
			return (ft_secur(ap));
	if (c == 'u')
		if (!(s = ft_itoa_base(va_arg(*ap, unsigned int), "0123456789")))
			return (ft_secur(ap));
	if (c == 'x')
		if (!(s = ft_itoa_base(va_arg(*ap, unsigned int), "0123456789abcdef")))
			return (ft_secur(ap));
	if (c == 'X')
		if (!(s = ft_itoa_base(va_arg(*ap, unsigned int), "0123456789ABCDEF")))
			return (ft_secur(ap));
	return (ft_conv_diuxx_2(var, s));
}
