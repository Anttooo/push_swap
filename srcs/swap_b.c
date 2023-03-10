/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:15:06 by oanttoor          #+#    #+#             */
/*   Updated: 2023/01/17 11:15:07 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.

void	swap_b(t_data *data)
{
	int	temp_holder;

	if (data->b_len >= 2)
	{
		temp_holder = data->b[0].value;
		data->b[0].value = data->b[1].value;
		data->b[1].value = temp_holder;
	}
	if (data->printing_enabled == 1)
		ft_printf("sb\n");
	data->move_counter.swap_b++;
}
