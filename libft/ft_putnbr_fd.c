/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:11:16 by oanttoor          #+#    #+#             */
/*   Updated: 2022/10/24 16:11:17 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	holder;

	holder = n;
	if (n < 0)
	{
		holder = -holder;
		ft_putchar_fd('-', fd);
	}
	if (holder > 9)
	{
		ft_putnbr_fd(holder / 10, fd);
		ft_putnbr_fd(holder % 10, fd);
	}
	else
	{
		ft_putchar_fd(holder + '0', fd);
	}
}
