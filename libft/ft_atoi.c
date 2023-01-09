/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:54:50 by oanttoor          #+#    #+#             */
/*   Updated: 2022/10/24 15:54:52 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static void	string_to_int(const char *str, int *i, long *integer, int sign);
static int	is_whitespace(char c);
static int	check_sign(const char *str, int *i, int *sign);
static void	handle_overflow(long *integer, int sign);

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	integer;

	i = 0;
	integer = 0;
	sign = 1;
	while (is_whitespace(str[i]) == 1)
		i = i + 1;
	check_sign(str, &i, &sign);
	string_to_int(str, &i, &integer, sign);
	return ((int)integer * sign);
}

static void	handle_overflow(long *integer, int sign)
{
	if (sign == -1)
		*integer = 0;
	else
		*integer = -1;
}

static int	is_whitespace(char c)
{
	if (((c < 14 && c > 8) || c == ' '))
		return (1);
	return (0);
}

static int	check_sign(const char *str, int *i, int *sign)
{
	if (str[*i] == '-')
	{
		*sign = -1;
		*i = *i + 1;
	}
	else if (str[*i] == '+')
		*i = *i + 1;
	return (*i);
}

static void	string_to_int(const char *str, int *i, long *integer, int sign)
{
	while (ft_isdigit(str[*i]))
	{
		*integer = *integer * 10 + (str[*i] - '0');
		if (*integer < 0)
		{
			handle_overflow(integer, sign);
			break ;
		}
		*i = *i + 1;
	}
}
