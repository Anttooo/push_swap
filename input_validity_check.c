/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validity_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:01:15 by oanttoor          #+#    #+#             */
/*   Updated: 2023/01/17 16:01:17 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_input(t_data *data, int i, char *arg);
int	atoi_has_overflowed(t_data *data, int i, char *arg);
int	atoi_max_int_overflow_or_non_numeric(t_data *data, int i, char *arg);
int	atoi_min_int_overflow(t_data *data, int i, char *arg);

void	check_input_validity(char *arg, t_data *data, int i)
{
	if (!is_valid_input(data, i, arg))
	{
		ft_printf("Error\n");
		freemem(data);
		exit(1);
	}
}

int	is_valid_input(t_data *data, int i, char *arg)
{
	int	e;

	e = 0;
	if (atoi_has_overflowed(data, i, arg))
		return (0);
	while (e < i)
	{
		if (data->a[i].value == data->a[e].value)
			return (0);
		e++;
	}
	return (1);
}

int	atoi_has_overflowed(t_data *data, int i, char *arg)
{
	if (atoi_max_int_overflow_or_non_numeric(data, i, arg))
		return (1);
	if (atoi_min_int_overflow(data, i, arg))
		return (1);
	return (0);
}

int	atoi_max_int_overflow_or_non_numeric(t_data *data, int i, char *arg)
{
	if (data->a[i].value == 0 && *arg != (char) '0')
		return (1);
	return (0);
}

int	atoi_min_int_overflow(t_data *data, int i, char *arg)
{
	if (data->a[i].value == -1 && ft_strncmp(arg, "-1", 2) != 0)
		return (1);
	return (0);
}
