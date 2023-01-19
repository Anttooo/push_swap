/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:14:13 by oanttoor          #+#    #+#             */
/*   Updated: 2023/01/17 11:14:14 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_b_move_values_in_b(t_data *data);
void	push_b_move_values_in_a(t_data *data);

// Take the first element at the top of a and put it at the top of b. 
// Do nothing if a is empty.
void	push_to_b(t_data *data)
{
	push_b_move_values_in_b(data);
	push_b_move_values_in_a(data);
	if (data->printing_enabled == 1)
		ft_printf("pb\n");
	data->move_counter.push_b++;
}

void	push_b_move_values_in_b(t_data *data)
{
	int	i;

	i = data->b_len;
	if (i < 0)
		i = 0;
	if (data->a_len > 0)
	{
		while (i > 0)
		{
			data->b[i].value = data->b[i - 1].value;
			i--;
		}
		data->b[0].value = data->a[0].value;
		data->b_len++;
		data->a_len--;
	}
}

void	push_b_move_values_in_a(t_data *data)
{
	int	i;

	i = 0;
	if (data->a_len > 0)
	{
		while (i < data->a_len)
		{
			data->a[i].value = data->a[i + 1].value;
			i++;
		}
	}
}
