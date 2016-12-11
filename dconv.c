/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:54:35 by vtenigin          #+#    #+#             */
/*   Updated: 2016/12/09 18:46:27 by vtenigin         ###   ########.fr       */
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


void	dconv(char type, t_env *env)
{
	long long	d;
	char		*s;

	d = va_arg(env->arg, long long);
	if (env->hh)
		d = (signed char)d;
	else if (env->h)
		d = (short int)d;
	else if (env->l || type == 'D')
		d = (long)d;
	else if (env->j)
		d = (intmax_t)d;
	else if (env->z)
		d = (size_t)d; // ?
	else if (!env->ll)
		d = (int)d;
	s = (env->zero && !env->minus) ? dconvzero(d, a) : dconvstd(d, a);
	env->ret = ft_strlen(s);
	ft_putstr(s);
	ft_strdel(&s);
}

char	*dconvstd(long long d, t_env *env)
{
	char	*s;
	int		i;

	s = (env->prec == 0 && d == 0) ? ft_strnew(0) : ft_ltoa_base(d, 10);
	i = ft_strlen(s);
	env->ret = (d < 0 || env->plus || env->space) ? i + 1 : i;
	while (i++ < env->prec)
	{
		s = ft_cjoin(ft_strdup("0"), s);
		env->ret++;
	}
	s = (env->p && d >= 0) ? ft_cjoin(ft_strdup("+"), s) : s;
	s = (env->space && d >= 0 && !env->plus) ? ft_cjoin(ft_strdup(" "), s) : s;
	s = (d < 0) ? ft_cjoin(ft_strdup("-"), s) : s;
	while (env->ret < env->width)
	{
		s = (env->minus) ? ft_cjoin(s, ft_strdup(" ")) : ft_cjoin(ft_strdup(" "), s);
		env->ret++;
	}
	return (s);
}

char	*dconvzero(long long d, t_arg *a)
{
	char	*s;
	int		i;

	s = (env->prec == 0 && d == 0) ? ft_strnew(0) : ft_ltoa_base(d, 10);
	i = ft_strlen(s);
	env->ret = (d < 0 || env->plus || env->space) ? i + 1 : i;
	if (env->prec != -1)
		while (i++ < env->prec && env->ret++ < env->width)
			s = ft_cjoin(ft_strdup("0"), s);
	else
		while (env->ret++ < env->width)
			s = ft_cjoin(ft_strdup("0"), s);
	s = (env->plus && d >= 0) ? ft_cjoin(ft_strdup("+"), s) : s;
	s = (env->space && d >= 0 && !env->plus) ? ft_cjoin(ft_strdup(" "), s) : s;
	s = (d < 0) ? ft_cjoin(ft_strdup("-"), s) : s;
	while (env->ret < env->width)
	{
		s = env->minus ? ft_cjoin(s, ft_strdup(" ")) : ft_cjoin(ft_strdup(" "), s);
		env->ret++;
	}
	return (s);
}
