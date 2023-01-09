/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:04:37 by oanttoor          #+#    #+#             */
/*   Updated: 2022/11/16 17:04:39 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_s(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		*count = *count + 6;
		ft_putstr_fd("(null)", 1);
	}
	else
	{
		while (str[i] != '\0')
		{
			ft_putchar_fd(str[i], 1);
			*count = *count + 1;
			i++;
		}
	}
}
