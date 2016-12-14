/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:53:18 by vtenigin          #+#    #+#             */
/*   Updated: 2016/12/12 16:15:22 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Modifier          d, i           o, u, x, X            n
 // hh                signed char    unsigned char         signed char *
 // h                 short          unsigned short        short *
 // l (ell)           long           unsigned long         long *
 // ll (ell ell)      long long      unsigned long long    long long *
 // j                 intmax_t       uintmax_t             intmax_t *
 // t                 ptrdiff_t      (see note)            ptrdiff_t *
 // z                 (see note)     size_t                (see note)
 // q (deprecated)    quad_t         u_quad_t              quad_t *

void	fconv(t_env *env)
{
	char *f;

	f = ft_dtoa_base(va_arg(env->arg, double), 10, env->prec, env);
	env->ret = ft_strlen(f);
	ft_putstr(f);
}

// void	type_f(t_arg *a)
// {
// 	char *f;

// 	f = ft_dtoa_base(va_arg(a->ap, double), 10, a->p, a);
// 	a->ret = ft_strlen(f);
// 	ft_putstr(f);
// }

void	oconv(char type, t_env *env)
{
	unsigned long long	d;
	char				*s;

	d = va_arg(env->arg, unsigned long long);
	if (env->hh)
		d = (unsigned char)d;
	else if (env->h)
		d = (unsigned short int)d;
	else if (env->l || type == 'O')
		d = (unsigned long)d;
	else if (env->j)
		d = (uintmax_t)d;
	else if (env->z)
		d = (size_t)d;
	else if (!env->ll)
		d = (unsigned int)d;
	s = (env->zero && !env->minus) ? oconvzero(d, env) : oconvstd(d, env);
	env->ret = ft_strlen(s);
	ft_putstr(s);
	ft_strdel(&s);
}

// void	type_o(char type, t_arg *a)
// {
// 	unsigned long long	d;
// 	char				*s;

// 	d = va_arg(a->ap, unsigned long long);
// 	if (a->m_l || type == 'O')
// 		d = (unsigned long)d;
// 	else if (a->m_h)
// 		d = (unsigned short int)d;
// 	else if (a->m_hh)
// 		d = (unsigned char)d;
// 	else if (a->m_j)
// 		d = (uintmax_t)d;
// 	else if (a->m_z)
// 		d = (size_t)d;
// 	else if (!a->m_ll)
// 		d = (unsigned int)d;
// 	s = a->f_zero && !a->f_m ? type_o_zero(d, a) : type_o_std(d, a);
// 	a->ret = ft_strlen(s);
// 	ft_putstr(s);
// 	ft_strdel(&s);
// }

char	*oconvstd(unsigned long long d, t_env *env)
{
	char	*s;

	s = (env->prec == 0 && d == 0) ? ft_strnew(0) : ft_utoa_base(d, 8);
	env->ret = ft_strlen(s);
	while (env->ret < env->prec)
	{
		s = ft_cjoin(ft_strdup("0"), s);
		env->ret++;
	}
	env->ret += (env->h && s[0] != 0) ? 1 : 0;
	(env->h && s[0] != '0') ? s = ft_cjoin(ft_strdup("0"), s) : 0;
	while (env->ret < env->width)
	{
		s = env->minus ? ft_cjoin(s, ft_strdup(" ")) : ft_cjoin(ft_strdup(" "), s);
		env->ret++;
	}
	return (s);
}

// char	*type_o_std(unsigned long long d, t_arg *a)
// {
// 	char	*s;

// 	s = a->p == 0 && d == 0 ? ft_strnew(0) : ft_utoa_base(d, 8);
// 	a->ret = ft_strlen(s);
// 	while (a->ret < a->p)
// 	{
// 		s = ft_cjoin(ft_strdup("0"), s);
// 		a->ret++;
// 	}
// 	a->ret += a->f_h && s[0] != 0 ? 1 : 0;
// 	a->f_h && s[0] != '0' ? s = ft_cjoin(ft_strdup("0"), s) : 0;
// 	while (a->ret < a->l)
// 	{
// 		s = a->f_m ? ft_cjoin(s, ft_strdup(" ")) : ft_cjoin(ft_strdup(" "), s);
// 		a->ret++;
// 	}
// 	return (s);
// }

char	*oconvzero(unsigned long long d, t_env *env)
{
	char	*s;

	s = (env->prec == 0 && d == 0) ? ft_strnew(0) : ft_utoa_base(d, 8);
	env->ret = ft_strlen(s);
	if (env->prec != 1)
		while (env->ret++ < env->prec)
			s = ft_cjoin(ft_strdup("0"), s);
	else
		while (env->ret++ < env->width)
			s = ft_cjoin(ft_strdup("0"), s);
	env->ret += (env->h && s[0] != '0') ? 1 : 0;
	(env->h && s[0] != '0') ? s = ft_cjoin(ft_strdup("0"), s) : 0;
	while (env->ret <= env->width)
	{
		s = env->minus ? ft_cjoin(s, ft_strdup(" ")) : ft_cjoin(ft_strdup(" "), s);
		env->ret++;
	}
	return (s);
}

// char	*type_o_zero(unsigned long long d, t_arg *a)
// {
// 	char	*s;

// 	s = a->p == 0 && d == 0 ? ft_strnew(0) : ft_utoa_base(d, 8);
// 	a->ret = ft_strlen(s);
// 	if (a->p != 1)
// 		while (a->ret++ < a->p)
// 			s = ft_cjoin(ft_strdup("0"), s);
// 	else
// 		while (a->ret++ < a->l)
// 			s = ft_cjoin(ft_strdup("0"), s);
// 	a->ret += a->f_h && s[0] != '0' ? 1 : 0;
// 	a->f_h && s[0] != '0' ? s = ft_cjoin(ft_strdup("0"), s) : 0;
// 	while (a->ret <= a->l)
// 	{
// 		s = a->f_m ? ft_cjoin(s, ft_strdup(" ")) : ft_cjoin(ft_strdup(" "), s);
// 		a->ret++;
// 	}
// 	return (s);
// }

void	pconv(t_env *env)
{
	char				*s;

	s = ft_utoa_base(va_arg(env->arg, unsigned long long), 16);
	if (s[0] == '0')
		s[0] = 0;
	env->ret = ft_strlen(s);
	while (env->ret++ < env->prec)
		s = ft_cjoin(ft_strdup("0"), s);
	s = ft_cjoin(ft_strdup("0x"), s);
	env->ret += 1;
	while (env->ret < env->width)
	{
		if (env->zero)
			s = ft_cjoin(s, ft_strdup("0"));
		else
			s = (env->minus) ? ft_cjoin(s, ft_strdup(" ")) :
				ft_cjoin(ft_strdup(" "), s);
		env->ret++;
	}
	env->ret = ft_strlen(s);
	s = strtolower(s);
	ft_putstr(s);
	ft_strdel(&s);
}

// void	type_p(t_arg *a)
// {
// 	char				*s;

// 	s = ft_utoa_base(va_arg(a->ap, unsigned long long), 16);
// 	if (s[0] == '0')
// 		s[0] = 0;
// 	a->ret = ft_strlen(s);
// 	while (a->ret++ < a->p)
// 		s = ft_cjoin(ft_strdup("0"), s);
// 	s = ft_cjoin(ft_strdup("0x"), s);
// 	a->ret += 1;
// 	while (a->ret < a->l)
// 	{
// 		if (a->f_zero)
// 			s = ft_cjoin(s, ft_strdup("0"));
// 		else
// 			s = a->f_m ? ft_cjoin(s, ft_strdup(" ")) :
// 				ft_cjoin(ft_strdup(" "), s);
// 		a->ret++;
// 	}
// 	a->ret = ft_strlen(s);
// 	s = str_lower(s);
// 	ft_putstr(s);
// 	ft_strdel(&s);
// }
