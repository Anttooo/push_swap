/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:14:54 by oanttoor          #+#    #+#             */
/*   Updated: 2023/01/17 11:14:55 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_both(t_data *data)
{
	int	print_switched;

	if (data->printing_enabled == 1)
	{
		print_switched = 1;
		data->printing_enabled = 0;
	}
	else
		print_switched = 0;
	rotate_a(data);
	rotate_b(data);
	if (print_switched == 1)
	{
		ft_printf("rr\n");
		data->printing_enabled = 1;
	}
	data->move_counter.rr++;
	data->move_counter.ra--;
	data->move_counter.rb--;
}
