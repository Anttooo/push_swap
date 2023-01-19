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
int	sign_has_changed_due_to_overflow(t_data *data, char *arg, int i);
int	includes_only_digits(char *arg);

void	check_input_validity(char *arg, t_data *data, int i)
{
	char	*error_message;

	error_message = "Error\n";
	if (!is_valid_input(data, i, arg))
	{
		ft_putstr_fd(error_message, 2);
		freemem(data);
		exit(1);
	}
}

int	is_valid_input(t_data *data, int i, char *arg)
{
	int	e;

	e = 0;
	if (includes_only_digits(arg) != 1)
		return (0);
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
	if (sign_has_changed_due_to_overflow(data, arg, i) == 1)
		return (1);
	if (data->a[i].value == 0 && *arg != (char) '0')
		return (1);
	if (data->a[i].value == -1 && ft_strncmp(arg, "-1", 2) != 0)
		return (1);
	return (0);
}

int	includes_only_digits(char *arg)
{
	int	j;

	j = 0;
	while (arg[j])
	{
		if (j == 0 && (arg[j] == '-'))
			j++;
		if (ft_isdigit(arg[j]) != 1)
			return (0);
		j++;
	}
	return (1);
}

int	sign_has_changed_due_to_overflow(t_data *data, char *arg, int i)
{
	int	j;
	int	is_negative_number;

	j = 0;
	is_negative_number = 0;
	while (arg[j])
	{
		if (j == 0 && (arg[j] == '-'))
		{
			is_negative_number = 1;
			j++;
		}
		if (ft_isdigit(arg[j]) != 1)
			return (0);
		j++;
	}
	if (is_negative_number == 1 && data->a[i].value > -1)
		return (1);
	if (is_negative_number == 0 && data->a[i].value < 0)
		return (1);
	return (0);
}