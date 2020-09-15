/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 03:17:16 by grezette          #+#    #+#             */
/*   Updated: 2020/01/01 16:53:28 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libftprintf.h"

void	ft_struct_init(t_struct *var, int bol)
{
	if (bol)
		var->len = 0;
	var->bfor = -1;
	var->aftr = -1;
	var->zero = -1;
	var->pres = -1;
	var->blpr = 0;
}

int		ft_deep_real_printf(const char **s, va_list *ap, t_struct *var)
{
	if (**s == 'c' || **s == '%')
		return (ft_conv_c_prct(ap, var, **s));
	if (**s == 's')
		return (ft_conv_s(ap, var));
	if (**s == 'd' || **s == 'i' || **s == 'x' || **s == 'X' || **s == 'u')
		return (ft_conv_diuxx(ap, var, **s));
	if (**s == 'p')
		return (ft_conv_p(ap, var));
	else
	{
		va_end(*ap);
		return (-1);
	}
}

int		ft_real_printf(const char **s, va_list *ap, t_struct *var)
{
	if (**s == '%')
	{
		(*s)++;
		ft_pars_flag_mz(s, var);
		ft_pars_flag_nb(s, ap, var);
		ft_pars_flag_pres(s, ap, var);
		if (ft_deep_real_printf(s, ap, var))
			return (-1);
		ft_struct_init(var, 0);
		(*s)++;
	}
	return (0);
}

int		ft_printf(const char *s, ...)
{
	va_list		ap;
	t_struct	var;

	va_start(ap, s);
	ft_struct_init(&var, 1);
	while (*s)
	{
		if (ft_real_printf(&s, &ap, &var))
			return (-1);
		if (*s != '%' && *s)
			var.len += write(1, s++, 1);
	}
	va_end(ap);
	return (var.len);
}
