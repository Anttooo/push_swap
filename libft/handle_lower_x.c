/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_lower_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:30:00 by oanttoor          #+#    #+#             */
/*   Updated: 2022/11/17 11:30:02 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_lower_x(unsigned int dec, int *count)
{
	if (dec > 15)
	{
		handle_lower_x(dec / 16, count);
		handle_lower_x(dec % 16, count);
	}
	else
	{
		*count = *count + 1;
		if (dec < 10)
			ft_putchar_fd(dec + '0', 1);
		else if (dec == 10)
			ft_putchar_fd('a', 1);
		else if (dec == 11)
			ft_putchar_fd('b', 1);
		else if (dec == 12)
			ft_putchar_fd('c', 1);
		else if (dec == 13)
			ft_putchar_fd('d', 1);
		else if (dec == 14)
			ft_putchar_fd('e', 1);
		else if (dec == 15)
			ft_putchar_fd('f', 1);
	}
}
