/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settype.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 21:28:31 by vtenigin          #+#    #+#             */
/*   Updated: 2016/12/08 22:24:11 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// sSpdDioOuUxXcC

void	settype(char *fmt, t_env *env)
{
	setdefprec(fmt[env->i], env);
	if (fmt[env->i] == 's' || fmt[env->i] == 'S')
		slsconv(fmt[env->i], env);
	else if (fmt[env->i] == 'p')
		pconv(env);
	else if (fmt[env->i] == 'd' || fmt[env->i] == 'i' || fmt[env->i] == 'D')
		dconv(fmt[env->i], env);
	else if (fmt[env->i] == 'o' || fmt[env->i] == 'O')
		oconv(fmt[env->i], env);
	else if (fmt[env->i] == 'u' || fmt[env->i] == 'U')
		uconv(fmt[env->i], env);
	else if (fmt[env->i] == 'x' || fmt[env->i] == 'X')
		xconv(fmt[env->i], env);
	else if (fmt[env->i] == 'c' || fmt[env->i] == 'C')
		clcconv(fmt[env->i], env);
	else if (fmt[env->i] == '%')
		percentconv(env);
	else if (fmt[env->i] == 'f' || fmt[env->i] == 'F')
		fconv(env);
	else
		invtype(fmt[env->i], env);
}

void	setdefprec(char type, t_env *env)
{
	if (env->prec == -1 && (type == 'f' || type == 'F'))
		env->prec = 6;
	if (env->prec == -1 && !(type == 'c' || type == 's' || type == 'S'))
		env->prec = 1; // ?
}


void	invtype(char c, t_env *env)
{
	env->ret = env->width ? env->width : 1;
	if (!env->minus)
		if (env->zero)
			ft_repeat_char('0', env->width - 1);
		else
			ft_repeat_char(' ', env->width - 1);
	ft_putchar(c);
	if (env->minus)
		if (env->zero)
			ft_repeat_char('0', env->width - 1);
		else
			ft_repeat_char(' ', env->width - 1);
}

void	ft_repeat_char(char c, unsigned int n)
{
	while (n--)
		write(1, &c, 1);
}

void	percentconv(t_arg *a)
{
	a->ret = 1;
	a->f_m == 1 ? ft_putchar('%') : 0;
	while (a->ret < a->l)
	{
		a->f_zero && !a->f_m ? ft_putchar('0') : ft_putchar(' ');
		a->ret++;
	}
	a->f_m == 0 ? ft_putchar('%') : 0;
}
