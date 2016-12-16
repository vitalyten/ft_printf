/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:59:11 by vtenigin          #+#    #+#             */
/*   Updated: 2016/12/12 16:09:24 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			printuc(char **uc)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (uc[i])
	{
		c = atocbin(uc[i]);
		write(1, &c, 1);
		i++;
	}
	free(uc);
}

unsigned char	atocbin(char *str)
{
	int				len;
	unsigned char	uc;

	uc = 0;
	len = ft_strlen(str);
	while (--len >= 0)
	{
		uc *= 2;
		uc += str[len] - '0';
	}
	return (uc);
}

unsigned char	*stock_wchar(char **to_print)
{
	unsigned char	*s;
	unsigned char	c;
	int				i;

	i = -1;
	while (to_print[++i])
		;
	s = (unsigned char *)malloc(i);
	i = 0;
	while (to_print[i])
	{
		c = atocbin(to_print[i]);
		s[i] = c;
		ft_strdel(&to_print[i]);
		i++;
	}
	s[i] = '\0';
	if (to_print)
		free(to_print);
	return (s);
}

// unsigned char	bin_a_to_u(char *s)
// {
// 	int				i;
// 	unsigned char	bin;
// 	unsigned char	ret;

// 	ret = 0;
// 	bin = 1;
// 	i = ft_strlen(s);
// 	while (--i >= 0)
// 	{
// 		ret += (bin * (s[i] - '0'));
// 		bin *= 2;
// 	}
// 	return (ret);
// }

// unsigned char	*stock_wchar(char **to_print)
// {
// 	unsigned char	*s;
// 	unsigned char	c;
// 	int				i;

// 	i = -1;
// 	while (to_print[++i])
// 		;
// 	s = (unsigned char *)malloc(i);
// 	i = 0;
// 	while (to_print[i])
// 	{
// 		c = bin_a_to_u(to_print[i]);
// 		s[i] = c;
// 		ft_strdel(&to_print[i]);
// 		i++;
// 	}
// 	s[i] = '\0';
// 	if (to_print)
// 		free(to_print);
// 	return (s);
// }

// void			print_wchar(char **to_print)
// {
// 	unsigned char	c;
// 	int				i;

// 	i = 0;
// 	while (to_print[i])
// 	{
// 		c = bin_a_to_u(to_print[i]);
// 		write(1, &c, 1);
// 		ft_strdel(&to_print[i]);
// 		i++;
// 	}
// 	if (to_print)
// 		free(to_print);
// }

