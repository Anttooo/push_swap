/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:09:41 by oanttoor          #+#    #+#             */
/*   Updated: 2022/10/24 16:09:42 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	count_len(int n);
static void	int_to_str(int n, char *str, int str_index);

char	*ft_itoa(int n)
{
	char	*str;
	int		str_len;

	str_len = count_len(n) + 1;
	str = (char *)malloc(str_len * sizeof(char));
	if (str == NULL)
		return (NULL);
	*(str + str_len - 1) = '\0';
	int_to_str(n, str, str_len - 2);
	return (str);
}

static void	int_to_str(int n, char *str, int str_index)
{
	long	holder;

	holder = n;
	if (n < 0)
	{
		holder = -holder;
		*(str) = '-';
	}
	if (holder > 9)
	{
		int_to_str(holder / 10, str, str_index - 1);
		int_to_str(holder % 10, str, str_index);
	}
	else
	{
		*(str + str_index) = holder + 48;
	}
}

int	count_len(int n)
{
	long	holder;
	int		counter;

	counter = 0;
	holder = n;
	if (n < 0)
	{
		holder = -holder;
		counter++;
	}
	while (holder > 9)
	{
		holder = holder / 10;
		counter++;
	}
	counter++;
	return (counter);
}
