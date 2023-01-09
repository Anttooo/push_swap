/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:52:33 by oanttoor          #+#    #+#             */
/*   Updated: 2022/11/15 15:52:35 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void	handle_types(char c, va_list *ptr, int *count);
void	process_str(const char *str, va_list *ptr, int *count);

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	ptr;

	count = 0;
	va_start(ptr, str);
	process_str(str, &ptr, &count);
	va_end(ptr);
	return (count);
}

void	process_str(const char *str, va_list *ptr, int *count)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
			{	
				*count = *count + 1;
				ft_putchar_fd('%', 1);
			}
			else
				handle_types(str[i], ptr, count);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			*count = *count + 1;
		}
		i++;
	}
}

// c = the type of the argument we're supposed to pass in
void	handle_types(char c, va_list *ptr, int *count)
{
	if (c == 'c')
		handle_c(va_arg(*ptr, int), count);
	if (c == 's')
		handle_s(va_arg(*ptr, char *), count);
	if (c == 'p')
		handle_p(va_arg(*ptr, void *), count);
	if (c == 'd' || c == 'i')
		handle_d(va_arg(*ptr, int), count);
	if (c == 'u')
		handle_u(va_arg(*ptr, unsigned int), count);
	if (c == 'x')
		handle_lower_x(va_arg(*ptr, unsigned int), count);
	if (c == 'X')
		handle_upper_x(va_arg(*ptr, unsigned int), count);
}
