/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:52:12 by vtenigin          #+#    #+#             */
/*   Updated: 2016/12/12 16:20:21 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	uconv(char type, t_env *env)
{
	unsigned long long	u;
	char				*str;

	u = va_arg(env->arg, unsigned long long);
	if (env->hh)
		u = (unsigned char)u;
	else if (env->h)
		u = (unsigned short int)u;
	else if (env->l || type == 'U')
		u = (unsigned long)u;
	else if (env->j)
		u = (uintmax_t)u;
	else if (env->z)
		u = (size_t)u;
	else if (!env->ll)
		u = (unsigned int)u;
	if (env->zero && !env->minus && env->prec == -1)
		str = uconvzero(u, env);
	else
		str = uconvstd(u, env);
	env->ret = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
}

char	*uconvstd(unsigned long long u, t_env *env)
{
	char	*str;

	str = (env->prec == 0 && u == 0) ? ft_strnew(0) : ft_ulltoa_base(u, 10);
	env->ret = ft_strlen(str);
	while (env->ret < env->prec)
	{
		str = ft_strjoin("0", str);
		env->ret++;
	}
	while (env->ret++ < env->width)
		str = (env->minus) ? ft_strjoin(str, " ") : ft_strjoin(" ", str);
	return (str);
}

char	*uconvzero(unsigned long long u, t_env *env)
{
	char	*str;

	str = ft_ulltoa_base(u, 10);
	env->ret = ft_strlen(str);
	while (env->ret < env->prec || env->ret < env->width)
	{
		str = ft_strjoin("0", str);
		env->ret++;
	}
	return (str);
}

// void	type_u(char type, t_arg *a)
// {
// 	unsigned long long	d;
// 	char				*s;

// 	d = va_arg(a->ap, unsigned long long);
// 	if (a->m_l || type == 'U')
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
// 	s = a->f_zero && !a->f_m ? type_u_zero(d, a) : type_u_std(d, a);
// 	a->ret = ft_strlen(s);
// 	ft_putstr(s);
// 	ft_strdel(&s);
// }

// char	*type_u_std(unsigned long long d, t_arg *a)
// {
// 	char	*s;

// 	s = a->p == 0 && d == 0 ? ft_strnew(0) : ft_utoa_base(d, 10);
// 	a->ret = ft_strlen(s);
// 	while (a->ret < a->p)
// 	{
// 		s = ft_cjoin(ft_strdup("0"), s);
// 		a->ret++;
// 	}
// 	while (a->ret < a->l)
// 	{
// 		s = a->f_m ? ft_cjoin(s, ft_strdup(" ")) : ft_cjoin(ft_strdup(" "), s);
// 		a->ret++;
// 	}
// 	return (s);
// }

// char	*type_u_zero(unsigned long long d, t_arg *a)
// {
// 	char	*s;

// 	s = a->p == 0 && d == 0 ? ft_strnew(0) : ft_utoa_base(d, 10);
// 	a->ret = ft_strlen(s);
// 	if (a->p != 1)
// 		while (a->ret < a->p && a->ret < a->l)
// 		{
// 			s = ft_cjoin(ft_strdup("0"), s);
// 			a->ret++;
// 		}
// 	else
// 		while (a->ret++ < a->l)
// 			s = ft_cjoin(ft_strdup("0"), s);
// 	while (a->ret < a->l)
// 	{
// 		s = a->f_m ? ft_cjoin(s, ft_strdup(" ")) : ft_cjoin(ft_strdup(" "), s);
// 		a->ret++;
// 	}
// 	return (s);
// }
