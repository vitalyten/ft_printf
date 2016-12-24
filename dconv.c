/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:54:35 by vtenigin          #+#    #+#             */
/*   Updated: 2016/12/22 19:59:28 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dconv(char type, t_env *env)
{
	long long	d;
	char		*str;

	d = va_arg(env->arg, long long);
	if (env->j)
		d = (intmax_t)d;
	else if (env->l || type == 'D')
		d = (long)d;
	else if (env->hh && type == 'D')
		d = (unsigned short)d;
	else if (env->hh)
		d = (signed char)d;
	else if (env->h && type == 'D')
		d = (unsigned short)d;
	else if (env->z)
		d = (size_t)d;
	else if (env->h)
		d = (short)d;
	else if (!env->ll)
		d = (int)d;
	if (env->zero && !env->minus && env->prec == -1)
		str = dconvzero(d, env);
	else
		str = dconvstd(d, env);
	env->ret = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
}

char	*dconvstd(long long d, t_env *env)
{
	char	*str;

	str = (env->prec == 0 && d == 0) ? ft_strnew(0) : ft_lltoa_base(d, 10);
	env->ret = ft_strlen(str);
	while (env->ret < env->prec)
	{
		str = sjoinfree(ft_strdup("0"), str);
		env->ret++;
	}
	if (d < 0 || env->plus || env->space)
		env->ret++;
	if (env->plus && d >= 0)
		str = sjoinfree(ft_strdup("+"), str);
	if (env->space && d >= 0 && !env->plus)
		str = sjoinfree(ft_strdup(" "), str);
	if (d < 0)
		str = sjoinfree(ft_strdup("-"), str);
	while (env->ret++ < env->width)
		str = (env->minus) ? sjoinfree(str, ft_strdup(" ")) : sjoinfree(ft_strdup(" "), str);
	return (str);
}

char	*dconvzero(long long d, t_env *env)
{
	char	*str;
	int		len;

	str = ft_lltoa_base(d, 10);
	len = ft_strlen(str);
	env->ret = len;
	if (d < 0 || env->plus || env->space)
		env->ret++;
	while (len++ < env->prec || env->ret++ < env->width)
		str = sjoinfree(ft_strdup("0"), str);
	if (env->plus && d >= 0)
		str = sjoinfree(ft_strdup("+"), str);
	if (env->space && d >= 0)
		str = sjoinfree(ft_strdup(" "), str);
	if (d < 0)
		str = sjoinfree(ft_strdup("-"), str);
	return (str);
}

 // Modifier          d, i           o, u, x, X            n
 // hh                signed char    unsigned char         signed char *
 // h                 short          unsigned short        short *
 // l (ell)           long           unsigned long         long *
 // ll (ell ell)      long long      unsigned long long    long long *
 // j                 intmax_t       uintmax_t             intmax_t *
 // t                 ptrdiff_t      (see note)            ptrdiff_t *
 // z                 (see note)     size_t                (see note)
 // q (deprecated)    quad_t         u_quad_t              quad_t *


// void	type_d(char type, t_arg *a)
// {
// 	long long	d;
// 	char		*s;

// 	d = va_arg(a->ap, long long);
// 	if (a->m_l || type == 'D')
// 		d = (long)d;
// 	else if (a->m_h)
// 		d = (short int)d;
// 	else if (a->m_hh)
// 		d = (signed char)d;
// 	else if (a->m_j)
// 		d = (intmax_t)d;
// 	else if (a->m_z)
// 		d = (ssize_t)d;
// 	else if (!a->m_ll)
// 		d = (int)d;
// 	s = a->f_zero && !a->f_m ? type_d_zero(d, a) : type_d_std(d, a);
// 	a->ret = ft_strlen(s);
// 	ft_putstr(s);
// 	ft_strdel(&s);
// }

// char	*type_d_std(long long d, t_arg *a)
// {
// 	char	*s;
// 	int		i;

// 	s = a->p == 0 && d == 0 ? ft_strnew(0) : ft_ltoa_base(d, 10);
// 	i = ft_strlen(s);
// 	a->ret = d < 0 || a->f_p || a->f_sp ? i + 1 : i;
// 	while (i++ < a->p)
// 	{
// 		s = ft_cjoin(ft_strdup("0"), s);
// 		a->ret++;
// 	}
// 	s = a->f_p && d >= 0 ? ft_cjoin(ft_strdup("+"), s) : s;
// 	s = a->f_sp && d >= 0 && !a->f_p ? ft_cjoin(ft_strdup(" "), s) : s;
// 	s = d < 0 ? ft_cjoin(ft_strdup("-"), s) : s;
// 	while (a->ret < a->l)
// 	{
// 		s = a->f_m ? ft_cjoin(s, ft_strdup(" ")) : ft_cjoin(ft_strdup(" "), s);
// 		a->ret++;
// 	}
// 	return (s);
// }

// char	*type_d_zero(long long d, t_arg *a)
// {
// 	char	*s;
// 	int		i;

// 	s = a->p == 0 && d == 0 ? ft_strnew(0) : ft_ltoa_base(d, 10);
// 	i = ft_strlen(s);
// 	a->ret = d < 0 || a->f_p || a->f_sp ? i + 1 : i;
// 	if (a->p != -1)
// 		while (i++ < a->p && a->ret++ < a->l)
// 			s = ft_cjoin(ft_strdup("0"), s);
// 	else
// 		while (a->ret++ < a->l)
// 			s = ft_cjoin(ft_strdup("0"), s);
// 	s = a->f_p && d >= 0 ? ft_cjoin(ft_strdup("+"), s) : s;
// 	s = a->f_sp && d >= 0 && !a->f_p ? ft_cjoin(ft_strdup(" "), s) : s;
// 	s = d < 0 ? ft_cjoin(ft_strdup("-"), s) : s;
// 	while (a->ret < a->l)
// 	{
// 		s = a->f_m ? ft_cjoin(s, ft_strdup(" ")) : ft_cjoin(ft_strdup(" "), s);
// 		a->ret++;
// 	}
// 	return (s);
// }
