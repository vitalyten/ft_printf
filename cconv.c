/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:55:22 by vtenigin          #+#    #+#             */
/*   Updated: 2016/12/10 20:33:37 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clcconv(char type, t_env *env)
{
	unsigned int	i;
	char			*s;
	char			**p;

	if (type == 'C' || env->l)
	{
		i = va_arg(env->arg, unsigned int);
		s = ft_utoa_base(i, 2);
		count_ret((p = unicode_masks(s)), env);
		(env->width > env->ret && !env->minus) ? ft_repeat_char(' ', env->width - env->ret) : 0;
		print_wchar(p);
		(env->width > env->ret && env->minus) ? ft_repeat_char(' ', env->width - env->ret) : 0;
		env->ret = (env->width > env->ret) ? env->width : env->ret;
	}
	else
		cconv(env);
}

void	cconv(t_env *env)
{
	char	c;

	c = va_arg(env->arg, int);
	env->ret++;
	(env->minus) ? ft_putchar(c) : 0;
	while (env->ret < env->width)
	{
		(env->zero) ? ft_putchar('0') : ft_putchar(' ');
		env->ret++;
	}
	(!env->minus) ? ft_putchar(c) : 0;
}
