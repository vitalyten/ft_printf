/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:50:56 by vtenigin          #+#    #+#             */
/*   Updated: 2016/12/08 20:04:00 by vtenigin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbru(unsigned int nb)
{
	if (nb < 10)
	{
		ft_putchar(nb + 48);
		return ;
	}
	ft_putnbru(nb / 10);
	ft_putchar((nb % 10) + 48);
	return ;
}

void	setflags(char *fmt, t_env *env)
{
	env->i++;
	while (fmt[env->i] == '+' || fmt[env->i] == '-' || fmt[env->i] == ' '
		|| fmt[env->i] == '#' || fmt[env->i] == '0')
	{
		if (fmt[env->i] == '+')
			env->plus = 1;
		if (fmt[env->i] == '-')
			env->minus = 1;
		if (fmt[env->i] == ' ')
			env->space = 1;
		if (fmt[env->i] == '#')
			env->hash = 1;
		if (fmt[env->i] == '0')
			env->zero = 1;
		env->i++;
	}
	if (fmt[env->i])
		check_min_lenght(fmt, a);
}

int		ft_printf(char *fmt, ...)
{
	t_env	env;
	int		ret;

	ret = 0;
	env.i = 0;
	va_start(env.arg, fmt);
	while (fmt[env.i])
	{
		envreset(&env);
		if (fmt[env.i] == '%' && fmt[env.i + 1])
			setflags(fmt, &env);
		else
		{
			ft_putchar(fmt[env.i]);
			ret++;
		}
		ret += env.ret;
		env.i++;
	}
	va_end(env.arg);
	return (ret);
}

void	envreset(t_env *env)
{
	env->ret = 0;
	env->plus = 0;
	env->minus = 0;
	env->space = 0;
	env->hash = 0;
	env->f_none = 0;
	env->zero = 0;
	env->l = 0;
	env->m_hh = 0;
	env->m_h = 0;
	env->m_l = 0;
	env->m_ll = 0;
	env->m_j = 0;
	env->m_z = 0;
	env->p = -1;
}

// #include "libft/libft.h"
// #include <stdarg.h>

// void Myprintf(char *,...); 				//Our printf function
// char* convert(unsigned int, int); 		//Convert integer number into octal, hex, etc.


// int main()
// {
// 	Myprintf(" WWW.FIRMCODES.COM \n %d", 9);
// 	return 0;
// }

// void Myprintf(char* format,...)
// {
// 	char *traverse;
// 	unsigned int i;
// 	char *s;
// 	//Module 1: Initializing Myprintf's arguments
// 	va_list arg;
// 	va_start(arg, format);
// 	for(traverse = format; *traverse != '\0'; traverse++)
// 	{
// 		while( *traverse != '%' )
// 		{
// 			ft_putchar(*traverse);
// 			traverse++;
// 		}
// 		traverse++;
// 		//Module 2: Fetching and executing arguments
// 		switch(*traverse)
// 		{
// 			case 'c' : i = va_arg(arg,int);		//Fetch char argument
// 						ft_putchar(i);
// 						break;
// 			case 'd' : i = va_arg(arg,int); 		//Fetch Decimal/Integer argument
// 						if(i<0)
// 						{
// 							i = -i;
// 							ft_putchar('-');
// 						}
// 						puts(convert(i,10));
// 						break
// 			case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
// 						puts(convert(i,8));
// 						break;
// 			case 's': s = va_arg(arg,char *); 		//Fetch string
// 						puts(s);
// 						break;
// 			case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
// 						puts(convert(i,16));
// 						break;
// 		}
// 	}
// 	//Module 3: Closing argument list to necessary clean-up
// 	va_end(arg);
// }

// char *convert(unsigned int num, int base)
// {
// 	static char Representation[]= "0123456789ABCDEF";
// 	static char buffer[50];
// 	char *ptr;

// 	ptr = &buffer[49];
// 	*ptr = '\0';
// 	do
// 	{
// 		*--ptr = Representation[num%base];
// 		num /= base;
// 	}while(num != 0);
// 	return(ptr);
// }

// int		ft_max(int a, int b)
// {
// 	return ((a > b) ? a : b);
// }











