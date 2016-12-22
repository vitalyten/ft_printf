/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:22:34 by vtenigin          #+#    #+#             */
/*   Updated: 2016/12/16 18:34:07 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	fconv(t_env *env)
// {
// 	char *f;

// 	f = ft_dtoa_base(va_arg(env->arg, double), 10, env->prec, env);
// 	env->ret = ft_strlen(f);
// 	ft_putstr(f);
// }

void	percentconv(t_env *env)
{
	env->ret = 1;
	if (env->minus)
		ft_putchar('%');
	while (env->ret < env->width)
	{
		(env->zero && !env->minus) ? ft_putchar('0') : ft_putchar(' ');
		env->ret++;
	}
	if (!env->minus)
		ft_putchar('%');
}

void	pconv(t_env *env)
{
	unsigned long long	x;
	char				*str;

	x = va_arg(env->arg, unsigned long long);
	str = (env->prec == 0 && x == 0) ? ft_strnew(0) : ft_ulltoa_base(x, 16);
	env->ret = ft_strlen(str);

	if (env->prec > 0)
		while (env->ret < env->prec)
		{
			str = ft_strjoin("0", str);
			env->ret++;
		}
	else
		while (env->zero && !env->minus && env->prec != 0
			&& !(env->prec == 0 && x == 0) && env->ret < env->width - 2)
		{
			str = ft_strjoin("0", str);
			env->ret++;
		}
	env->ret += 2;
	str = ft_strjoin("0X", str);
	while (env->ret < env->width)
	{
		str = (env->minus) ? ft_strjoin(str, " ") : ft_strjoin(" ", str);
		env->ret++;
	}
	str = ft_strtolower(str);
	ft_putstr(str);
	ft_strdel(&str);
}

// void	pconv(t_env *env)
// {
// 	char				*str;
// 	unsigned long long	p;

// 	p = va_arg(env->arg, unsigned long long);
// 	str = ft_ulltoa_base(p, 16);
// 	if (str[0] == '0')
// 		str[0] = 0;
// 	env->ret = ft_strlen(str);
// 	while (env->ret++ < env->prec)
// 		str = ft_cjoin("0", str);
// 	str = ft_cjoin("0x", str);
// 	env->ret += 1;
// 	while (env->ret < env->width)
// 	{
// 		if (env->zero)
// 			str = ft_cjoin(str, ft_strdup("0"));
// 		else
// 			str = (env->minus) ? ft_cjoin(str, ft_strdup(" ")) :
// 				ft_cjoin(ft_strdup(" "), str);
// 		env->ret++;
// 	}
// 	env->ret = ft_strlen(str);
// 	str = strtolower(str);
// 	ft_putstr(str);
// 	ft_strdel(&str);
// }

// void	pconv(t_env *env)
// {
// 	char				*str;
// 	unsigned long long	p;

// 	p = va_arg(env->arg, unsigned long long);
// 	str = ft_ulltoa_base(p, 16);
// 	if (str[0] == '0')
// 		str[0] = 0;
// 	env->ret = ft_strlen(str);
// 	while (env->ret++ < env->prec)
// 		str = ft_cjoin("0", str);
// 	str = ft_cjoin("0x", str);
// 	env->ret += 1;
// 	while (env->ret < env->width)
// 	{
// 		if (env->zero)
// 			str = ft_cjoin(str, ft_strdup("0"));
// 		else
// 			str = (env->minus) ? ft_cjoin(str, ft_strdup(" ")) :
// 				ft_cjoin(ft_strdup(" "), str);
// 		env->ret++;
// 	}
// 	env->ret = ft_strlen(str);
// 	str = strtolower(str);
// 	ft_putstr(str);
// 	ft_strdel(&str);
// }


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



// void	type_percent(t_arg *a)
// {
// 	a->ret = 1;
// 	a->f_m == 1 ? ft_putchar('%') : 0;
// 	while (a->ret < a->l)
// 	{
// 		a->f_zero && !a->f_m ? ft_putchar('0') : ft_putchar(' ');
// 		a->ret++;
// 	}
// 	a->f_m == 0 ? ft_putchar('%') : 0;
// }

// void	type_f(t_arg *a)
// {
// 	char *f;

// 	f = ft_dtoa_base(va_arg(a->ap, double), 10, a->p, a);
// 	a->ret = ft_strlen(f);
// 	ft_putstr(f);
// }
