/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:32:26 by oanttoor          #+#    #+#             */
/*   Updated: 2022/11/17 09:32:29 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dec_to_hex(unsigned long dec, int *count);

void	handle_p(void *p, int *count)
{
	void			**address;
	unsigned long	decimal_address;

	address = &p;
	decimal_address = *(unsigned long *)address;
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	*count = *count + 2;
	dec_to_hex(decimal_address, count);
}

void	dec_to_hex(unsigned long dec, int *count)
{
	if (dec > 15)
	{
		dec_to_hex(dec / 16, count);
		dec_to_hex(dec % 16, count);
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

/* 
DEC to HEX
0 = 0
1 = 1
2 = 2
3 = 3
4 = 4
5 = 5
6 = 5
7 = 7
8 = 8
9 - 9
10 = A
11 = B
12 = C
13 = D
14 = E
15 = F
16 = 10
17 = 11
26 = 1A
31 = 1F
32 = 20
 */