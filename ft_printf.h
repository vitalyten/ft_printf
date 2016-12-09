/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 22:42:58 by vtenigin          #+#    #+#             */
/*   Updated: 2016/12/08 19:37:52 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct		s_env
{
	va_list		arg;
	int			ret;
	int			i;
	int			plus;
	int			minus;
	int			space;
	int			hash;
	int			zero;
	int			f_none;
	int			l;
	int			p;
	int			m_h;
	int			m_hh;
	int			m_l;
	int			m_ll;
	int			m_z;
	int			m_j;
}					t_env;

/*
**		tools
*/

void				ft_putnbru(unsigned int nb);
char				*ft_utoa_base(unsigned long long value, int base);
char				*ft_ltoa_base(long long value, int base);
char				*ft_dtoa_base(double value, int base, int precision,
		t_arg *a);
void				ft_repeat_char(char c, int nbr);
char				*str_lower(char *str);
void				count_ret(char **to_print, t_arg *a);

/*
**		type conversion
*/

void				type_d(char type, t_arg *a);
void				type_x(char type, t_arg *a);
void				type_u(char type, t_arg *a);
void				type_o(char type, t_arg *a);
void				type_s_ls(char type, t_arg *a);
void				type_c_lc(char type, t_arg *a);
void				type_percent(t_arg *a);
void				type_f(t_arg *a);
void				type_p(t_arg *a);

/*
**		flags
*/

void				check_flags(char *format, t_arg *a);
void				check_min_lenght(char *format, t_arg *a);
void				check_precision(char *format, t_arg *a);
void				set_default_precision(char type, t_arg *a);
void				check_modifier(char *format, t_arg *a);

/*
**		unicode
*/

char				**unicode_masks(char *wc);
void				masks_fill(char *mask, char *wc);
void				print_wchar(char **to_print);
unsigned char		*stock_wchar(char **to_print);

int					ft_printf(char *format, ...);
void				check_type(char *format, t_arg *a);

#endif
