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

int	is_valid_input(t_data *data, int i, char **argv)
{
	int	e;

	e = 0;
	if (data->a[i].value == 0 && *argv[i + 1] != (char) '0')
		return (0);
	if (data->a[i].value == -1 && ft_strncmp(argv[i + 1], "-1", 2) != 0)
		return (0);
	while (e < i)
	{
		if (data->a[i].value == data->a[e].value)
			return (0);
		e++;
	}
	return (1);
}

void	check_input_validity(char **argv, t_data *data, int *i)
{
	if (!is_valid_input(data, *i, argv))
	{
		ft_printf("Error\n");
		freemem(data);
		exit(1);
	}
}
