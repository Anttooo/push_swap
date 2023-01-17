/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:14:05 by oanttoor          #+#    #+#             */
/*   Updated: 2023/01/17 11:14:07 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_values_in_b(t_data *data);
void	move_values_in_a(t_data *data);

// Take the first element at the top of b and put it at the top of a. 
// Do nothing if b is empty.
void	push_to_a(t_data *data)
{
	move_values_in_a(data);
	move_values_in_b(data);
	if (data->printing_enabled == 1)
		ft_printf("pa\n");
	data->move_counter.push_a++;
}

void	move_values_in_b(t_data *data)
{
	int	i;

	i = 0;
	if (data->b_len > 0)
	{
		while (i < data->b_len)
		{
			data->b[i].value = data->b[i + 1].value;
			i++;
		}
	}
}

void	move_values_in_a(t_data *data)
{
	int	i;

	i = data->a_len;
	if (data->b_len > 0)
	{
		while (i > 0)
		{
			data->a[i].value = data->a[i - 1].value;
			i--;
		}
		data->a[0].value = data->b[0].value;
		data->b_len--;
		data->a_len++;
	}
}
