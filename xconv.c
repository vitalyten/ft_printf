/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:51:33 by vtenigin          #+#    #+#             */
/*   Updated: 2016/12/12 16:23:39 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	xconv(char type, t_env *env)
{
	unsigned long long	d;
	char				*s;

	d = va_arg(env->arg, unsigned long long);
	if (env->hh)
		d = (unsigned char)d;
	else if (env->h)
		d = (unsigned short int)d;
	else if (env->l)
		d = (unsigned long)d;
	else if (env->j)
		d = (uintmax_t)d;
	else if (env->z)
		d = (size_t)d;
	else if (!env->ll)
		d = (unsigned int)d;
	s = (env->zero && !env->minus) ? xconvzero(d, env) : xconvstd(d, env);
	env->ret = ft_strlen(s);
	if (type == 'x')
		s = strtolower(s);
	ft_putstr(s);
	ft_strdel(&s);
}

char	*xconvstd(unsigned long long d, t_env *env)
{
	char	*s;

	s = (env->prec == 0 && d == 0) ? ft_strnew(0) : ft_ulltoa_base(d, 16);
	env->ret = ft_strlen(s);
	while (env->ret < env->prec)
	{
		s = ft_cjoin(ft_strdup("0"), s);
		env->ret++;
	}
	(env->h && d) ? s = ft_cjoin(ft_strdup("0X"), s) : 0;
	env->ret += (env->h) ? 2 : 0;
	while (env->ret < env->width)
	{
		s = (env->minus) ? ft_cjoin(s, ft_strdup(" ")) : ft_cjoin(ft_strdup(" "), s);
		env->ret++;
	}
	return (s);
}

char	*xconvzero(unsigned long long d, t_env *env)
{
	char	*s;

	s = (env->prec == 0 && d == 0) ? ft_strnew(0) : ft_ulltoa_base(d, 16);
	env->ret = ft_strlen(s);
	if (env->prec != 1)
	{
		while (env->ret++ < env->prec)
			s = ft_cjoin(ft_strdup("0"), s);
		env->ret += (env->h) ? 2 : 0;
	}
	else
	{
		env->ret += (env->h) ? 2 : 0;
		while (env->ret++ < env->width)
			s = ft_cjoin(ft_strdup("0"), s);
	}
	(env->h && d) ? s = ft_cjoin(ft_strdup("0X"), s) : 0;
	while (env->ret <= env->width)
	{
		s = (env->minus) ? ft_cjoin(s, ft_strdup(" ")) : ft_cjoin(ft_strdup(" "), s);
		env->ret++;
	}
	return (s);
}

// void	type_x(char type, t_arg *a)
// {
// 	unsigned long long	d;
// 	char				*s;

// 	d = va_arg(a->ap, unsigned long long);
// 	if (a->m_l)
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
// 	s = a->f_zero && !a->f_m ? type_x_zero(d, a) : type_x_std(d, a);
// 	a->ret = ft_strlen(s);
// 	if (type == 'x')
// 		s = str_lower(s);
// 	ft_putstr(s);
// 	ft_strdel(&s);
// }



// char	*type_x_std(unsigned long long d, t_arg *a)
// {
// 	char	*s;

// 	s = a->p == 0 && d == 0 ? ft_strnew(0) : ft_utoa_base(d, 16);
// 	a->ret = ft_strlen(s);
// 	while (a->ret < a->p)
// 	{
// 		s = ft_cjoin(ft_strdup("0"), s);
// 		a->ret++;
// 	}
// 	a->f_h && d ? s = ft_cjoin(ft_strdup("0X"), s) : 0;
// 	a->ret += a->f_h ? 2 : 0;
// 	while (a->ret < a->l)
// 	{
// 		s = a->f_m ? ft_cjoin(s, ft_strdup(" ")) : ft_cjoin(ft_strdup(" "), s);
// 		a->ret++;
// 	}
// 	return (s);
// }

// char	*type_x_zero(unsigned long long d, t_arg *a)
// {
// 	char	*s;

// 	s = a->p == 0 && d == 0 ? ft_strnew(0) : ft_utoa_base(d, 16);
// 	a->ret = ft_strlen(s);
// 	if (a->p != 1)
// 	{
// 		while (a->ret++ < a->p)
// 			s = ft_cjoin(ft_strdup("0"), s);
// 		a->ret += a->f_h ? 2 : 0;
// 	}
// 	else
// 	{
// 		a->ret += a->f_h ? 2 : 0;
// 		while (a->ret++ < a->l)
// 			s = ft_cjoin(ft_strdup("0"), s);
// 	}
// 	a->f_h && d ? s = ft_cjoin(ft_strdup("0X"), s) : 0;
// 	while (a->ret <= a->l)
// 	{
// 		s = a->f_m ? ft_cjoin(s, ft_strdup(" ")) : ft_cjoin(ft_strdup(" "), s);
// 		a->ret++;
// 	}
// 	return (s);
// }

char	*strtolower(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	return (str);
}


// char	*str_lower(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		str[i] = ft_tolower(str[i]);
// 		i++;
// 	}
// 	return (str);
// }
