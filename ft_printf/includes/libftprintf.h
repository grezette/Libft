/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grezette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 16:50:40 by grezette          #+#    #+#             */
/*   Updated: 2020/01/04 16:05:25 by grezette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "../../libft.h"

typedef struct	s_struct
{
	int			len;
	int			bfor;
	int			aftr;
	int			zero;
	int			pres;
	int			blpr;
}				t_struct;

int				ft_secur(va_list *ap);
int				ft_printf(const char *s, ...);
int				ft_conv_s(va_list *ap, t_struct *var);
int				ft_conv_p(va_list *ap, t_struct *var);
int				ft_conv_diuxx(va_list *ap, t_struct *var, unsigned char c);
int				ft_conv_c_prct(va_list *ap, t_struct *var, unsigned char c);

void			ft_pars_flag_mz(const char **s, t_struct *var);
void			ft_pars_flag_nb(const char **s, va_list *ap, t_struct *var);
void			ft_pars_flag_pres(const char **s, va_list *ap, t_struct *var);
void			ft_struct_init(t_struct *var, int bol);

#endif
