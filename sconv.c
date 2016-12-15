/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 22:05:53 by vtenigin          #+#    #+#             */
/*   Updated: 2016/12/12 18:27:27 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percentconv(t_env *env)
{
	env->ret = 1;
	env->minus == 1 ? ft_putchar('%') : 0;
	while (env->ret < env->width)
	{
		env->zero && !env->minus ? ft_putchar('0') : ft_putchar(' ');
		env->ret++;
	}
	env->minus == 0 ? ft_putchar('%') : 0;
}

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

void	slsconv(char type, t_env *env)
{
	wchar_t	*ws;

	if (type == 'S' || env->l)
	{
		ws = va_arg(env->arg, wchar_t*);
		lsconv(ws, env);
	}
	else
		sconv(env);
}

// void	type_s_ls(char type, t_arg *a)
// {
// 	wchar_t			*ws;

// 	if (type == 'S' || a->m_l)
// 	{
// 		ws = va_arg(a->ap, wchar_t*);
// 		type_ls(ws, a);
// 	}
// 	else
// 		type_s(a);
// }

void	lsconv(wchar_t *ws, t_env *env)
{
	unsigned int	w;
	int				i;
	char			**p;
	char			*s;
	char			*t;

	i = -1;
	t = !ws ? ft_strdup("(null)") : ft_strnew(0);
	while (ws && ws[++i] && (env->prec != -1 ? env->ret < env->prec : 1))
	{
		w = (unsigned int)ws[i];
		s = ft_ulltoa_base(w, 2);
		retcount((p = getunicode(s)), env);
		if (env->prec == -1 || (env->prec != -1 && env->ret <= env->prec))
			t = ft_cjoin((char*)t, (char*)stock_wchar(p));
	}
	env->ret = ft_strlen(t);
	env->minus ? write(1, t, env->ret) : 0;
	if ((i = env->width - env->ret))
		env->zero && !env->minus ? ft_repeat_char('0', i) : ft_repeat_char(' ', i);
	!env->minus ? write(1, t, env->ret) : 0;
	ft_strdel(&t);
	env->ret = env->width > env->ret ? env->width : env->ret;
}

// void	type_ls(wchar_t *ws, t_arg *a)
// {
// 	unsigned int	w;
// 	int				i;
// 	char			**p;
// 	char			*s;
// 	char			*t;

// 	i = -1;
// 	t = !ws ? ft_strdup("(null)") : ft_strnew(0);
// 	while (ws && ws[++i] && (a->p != -1 ? a->ret < a->p : 1))
// 	{
// 		w = (unsigned int)ws[i];
// 		s = ft_utoa_base(w, 2);
// 		count_ret((p = unicode_masks(s)), a);
// 		if (a->p == -1 || (a->p != -1 && a->ret <= a->p))
// 			t = ft_cjoin((char*)t, (char*)stock_wchar(p));
// 	}
// 	a->ret = ft_strlen(t);
// 	a->f_m ? write(1, t, a->ret) : 0;
// 	if ((i = a->l - a->ret))
// 		a->f_zero && !a->f_m ? ft_repeat_char('0', i) : ft_repeat_char(' ', i);
// 	!a->f_m ? write(1, t, a->ret) : 0;
// 	ft_strdel(&t);
// 	a->ret = a->l > a->ret ? a->l : a->ret;
// }

void	sconv(t_env *env)
{
	char	*s;
	int		i;
	int		j;

	j = -1;
	if (!(s = ft_strdup(va_arg(env->arg, char *))))
		s = ft_strdup("(null)");
	if (!s[0])
		ft_repeat_char(' ', env->width);
	env->ret = !s[0] || env->prec == 0 ? env->width : ft_strlen(s);
	i = env->prec >= 0 && env->prec < env->ret ? env->width - env->prec : env->width - env->ret;
	if (!env->minus && s[0])
		env->zero ? ft_repeat_char('0', i) : ft_repeat_char(' ', i);
	while (s[++j] && env->prec > 0 && s[0] && j < env->prec)
	{
		env->prec < env->ret ? env->ret = env->prec : 0;
		ft_putchar(s[j]);
	}
	env->prec == -1 ? ft_putstr(s) : 0;
	if (env->minus && s[0])
		ft_repeat_char(' ', i);
	if (i > 0 && s[0] && env->prec != 0)
		env->ret += i;
	ft_strdel(&s);
}

// void	type_s(t_arg *a)
// {
// 	char	*s;
// 	int		i;
// 	int		j;

// 	j = -1;
// 	if (!(s = ft_strdup(va_arg(a->ap, char *))))
// 		s = ft_strdup("(null)");
// 	if (!s[0])
// 		ft_repeat_char(' ', a->l);
// 	a->ret = !s[0] || a->p == 0 ? a->l : ft_strlen(s);
// 	i = a->p >= 0 && a->p < a->ret ? a->l - a->p : a->l - a->ret;
// 	if (!a->f_m && s[0])
// 		a->f_zero ? ft_repeat_char('0', i) : ft_repeat_char(' ', i);
// 	while (s[++j] && a->p > 0 && s[0] && j < a->p)
// 	{
// 		a->p < a->ret ? a->ret = a->p : 0;
// 		ft_putchar(s[j]);
// 	}
// 	a->p == -1 ? ft_putstr(s) : 0;
// 	if (a->f_m && s[0])
// 		ft_repeat_char(' ', i);
// 	if (i > 0 && s[0] && a->p != 0)
// 		a->ret += i;
// 	ft_strdel(&s);
// }
