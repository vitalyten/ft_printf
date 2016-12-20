/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toabase.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:00:45 by vtenigin          #+#    #+#             */
/*   Updated: 2016/12/16 18:29:47 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_lltoa_base(long long value, int base)
{
	int				mod;
	int				len;
	char			*ret;
	long long		temp;

	if (base < 2 || base > 16)
		return (NULL);
	len = 1;
	temp = value;
	while (temp /= base)
		len++;
	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ret[len--] = '\0';
	while (len >= 0 && value / base)
	{
		mod = ft_abs(value % base);
		ret[len--] = (mod < 10) ? mod + '0' : mod + '7';
		value /= base;
	}
	mod = ft_abs(value % base);
	ret[len--] = (mod < 10) ? mod + '0' : mod + '7'; // ?
	return (ret);
}

char	*ft_ulltoa_base(unsigned long long value, int base)
{
	int					mod;
	int					len;
	char				*ret;
	unsigned long long	temp;

	if (base < 2 || base > 16)
		return (NULL);
	len = 1;
	temp = value;
	while (temp /= base)
		len++;
	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ret[len--] = '\0';
	while (len >= 0 && value / base)
	{
		mod = value % base;
		ret[len] = (mod < 10) ? mod + '0' : mod + '7';
		value /= base;
		len--;
	}
	mod = value % base;
	ret[len--] = (mod < 10) ? mod + '0' : mod + '7';
	return (ret);
}

// char	*ft_cjoin(char *s1, char *s2) // remove
// {
// 	char	*stock;

// 	if (s1 == NULL  && s2 == NULL)
// 		return (NULL);
// 	stock = ft_strjoin(s1, s2);
// 	if (s1)
// 		ft_strdel(&s1);
// 	if (s2)
// 		ft_strdel(&s2);
// 	return (stock);
// }

// char	*precision_zero(double value, int base, t_env *env)
// {
// 	char	*ret;

// 	value = ((10 * (value - (int)value)) > 5) ? value + 1 : value;
// 	ret = (env->h) ? ft_cjoin(ft_lltoa_base((int)value, base), ft_strdup("."))
// 		: ft_cjoin(NULL, ft_lltoa_base((int)value, base));
// 	return (ret);
// }

// char	*ft_dtoa_base(double value, int base, int precision, t_env *env)
// {
// 	char			*ret;
// 	double			tmp;

// 	if (base < 2 || base > 16)
// 		return (NULL);
// 	if (precision > 0)
// 	{
// 		ret = ft_cjoin(NULL, ft_lltoa_base((int)value, base));
// 		tmp = (value < 0) ? -1 * (value - (int)value) : value - (int)value;
// 		value = tmp;
// 		while ((value = value - (int)value) > 0 && precision > 0)
// 		{
// 			tmp = tmp * 10;
// 			value = tmp;
// 			precision--;
// 		}
// 		ret = ft_cjoin(ret, ft_strdup("."));
// 		tmp = (value > 0.5) ? tmp + 1 : tmp;
// 		ret = ft_cjoin(ret, ft_lltoa_base(tmp, base));
// 	}
// 	else
// 		ret = precision_zero(value, base, env);
// 	return (ret);
// }

// char	*ft_utoa_base(unsigned long long value, int base)
// {
// 	int					len;
// 	char				*ret;
// 	unsigned long long	tmp;

// 	if (base < 2 || base > 16)
// 		return (NULL);
// 	len = 1;
// 	tmp = value;
// 	while ((tmp = tmp / base))
// 		len++;
// 	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
// 		return (NULL);
// 	ret[len--] = '\0';
// 	while (len >= 0 && value / base != 0)
// 	{
// 		ret[len] = value % base < 10 ? value % base + '0' : value % base + '7';
// 		value /= base;
// 		len--;
// 	}
// 	ret[len--] = value % base < 10 ? value % base + '0' : value % base + '7';
// 	return (ret);
// }

// int	getlen(unsigned long long value, int base)
// {
// 	int	i;

// 	i = 0;
// 	while (value)
// 	{
// 		value /= base;
// 		i++;
// 	}
// 	return (i);
// }

// char getchar(int i)
// {
// 	char *tab = "0123456789ABCDEF";
// 	return (tab[i]);
// }

// char	*ft_lltoa_base(long long value, int base)
// {
// 	unsigned long long	n;
// 	char				*ret;
// 	int					len;

// 	if (!(base >= 2 && base <= 16))
// 		return (NULL);
// 	if (value == 0)
// 		return ("0");
// 	n = (value < 0) ? (unsigned long long)-value : (unsigned long long)value;
// 	len = getlen(n, base);
// 	if (value < 0 && base == 10)
// 		len++;
// 	ret = (char *)malloc(sizeof(char) * (len + 1));
// 	ret[len] = '\0';
// 	len--;
// 	while (n)
// 	{
// 		ret[len] = getchar(n % base);
// 		n /= base;
// 		len--;
// 	}
// 	if (value < 0 && base == 10)
// 		ret[0] = '-';
// 	return (ret);
// }


// char	*ft_ltoa_base(long long value, int base)
// {
// 	int				len;
// 	int				i;
// 	char			*ret;
// 	long long		tmp;

// 	if (base < 2 || base > 16)
// 		return (NULL);
// 	len = 1;
// 	tmp = value;
// 	while ((tmp = tmp / base))
// 		len++;
// 	if (!(ret = (char*)malloc(sizeof(char) * len + 1)))
// 		return (NULL);
// 	ret[len--] = '\0';
// 	while (len >= 0 && value / base != 0)
// 	{
// 		i = ft_abs(value % base);
// 		ret[len] = i < 10 ? i + '0' : i + '7';
// 		value /= base;
// 		len--;
// 	}
// 	i = ft_abs(value % base);
// 	ret[len--] = i < 10 ? i + '0' : i + '7';
// 	return (ret);
// }

// char	*ft_dtoa_base(double value, int base, int precision, t_arg *a)
// {
// 	char			*ret;
// 	double			tmp;

// 	if (base < 2 || base > 16)
// 		return (NULL);
// 	if (precision > 0)
// 	{
// 		ret = ft_cjoin(NULL, ft_ltoa_base((int)value, base));
// 		tmp = value < 0 ? -1 * (value - (int)value) : value - (int)value;
// 		value = tmp;
// 		while ((value = value - (int)value) > 0 && precision > 0)
// 		{
// 			tmp = tmp * 10;
// 			value = tmp;
// 			precision--;
// 		}
// 		ret = ft_cjoin(ret, ft_strdup("."));
// 		tmp = value > 0.5 ? tmp + 1 : tmp;
// 		ret = ft_cjoin(ret, ft_ltoa_base(tmp, base));
// 	}
// 	else
// 		ret = precision_zero(value, base, a);
// 	return (ret);
// }


// char	*precision_zero(double value, int base, t_arg *a)
// {
// 	char	*ret;

// 	value = (10 * (value - (int)value)) > 5 ? value + 1 : value;
// 	ret = a->f_h ? ft_cjoin(ft_ltoa_base((int)value, base), ft_strdup("."))
// 		: ft_cjoin(NULL, ft_ltoa_base((int)value, base));
// 	return (ret);
// }


