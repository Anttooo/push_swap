/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:13:19 by oanttoor          #+#    #+#             */
/*   Updated: 2022/11/17 11:13:22 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_u(unsigned int n, int *count)
{
	if (n > 9)
	{
		handle_u(n / 10, count);
		handle_u(n % 10, count);
	}
	else
	{
		*count = *count + 1;
		ft_putchar_fd(n + '0', 1);
	}
}
