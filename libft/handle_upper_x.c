/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_upper_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:30:10 by oanttoor          #+#    #+#             */
/*   Updated: 2022/11/17 11:30:11 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_upper_x(unsigned int dec, int *count)
{
	if (dec > 15)
	{
		handle_upper_x(dec / 16, count);
		handle_upper_x(dec % 16, count);
	}
	else
	{
		*count = *count + 1;
		if (dec < 10)
			ft_putchar_fd(dec + '0', 1);
		else if (dec == 10)
			ft_putchar_fd('A', 1);
		else if (dec == 11)
			ft_putchar_fd('B', 1);
		else if (dec == 12)
			ft_putchar_fd('C', 1);
		else if (dec == 13)
			ft_putchar_fd('D', 1);
		else if (dec == 14)
			ft_putchar_fd('E', 1);
		else if (dec == 15)
			ft_putchar_fd('F', 1);
	}
}
