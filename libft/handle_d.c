/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:53:04 by oanttoor          #+#    #+#             */
/*   Updated: 2022/11/17 10:53:06 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_d(int n, int *count)
{
	long	holder;

	holder = n;
	if (n < 0)
	{
		holder = -holder;
		*count = *count + 1;
		ft_putchar_fd('-', 1);
	}
	if (holder > 9)
	{
		handle_d(holder / 10, count);
		handle_d(holder % 10, count);
	}
	else
	{
		*count = *count + 1;
		ft_putchar_fd(holder + '0', 1);
	}
}
