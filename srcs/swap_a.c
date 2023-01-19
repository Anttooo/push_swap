/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:15:02 by oanttoor          #+#    #+#             */
/*   Updated: 2023/01/17 11:15:04 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.

void	swap_a(t_data *data)
{
	int	temp_holder;

	if (data->a_len >= 2)
	{
		temp_holder = data->a[0].value;
		data->a[0].value = data->a[1].value;
		data->a[1].value = temp_holder;
	}
	if (data->printing_enabled == 1)
		ft_printf("sa\n");
	data->move_counter.swap_a++;
}
