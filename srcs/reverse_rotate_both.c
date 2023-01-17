/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_both.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:14:35 by oanttoor          #+#    #+#             */
/*   Updated: 2023/01/17 11:14:36 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_both(t_data *data)
{
	int	print_switched;

	if (data->printing_enabled == 1)
	{
		print_switched = 1;
		data->printing_enabled = 0;
	}
	else
		print_switched = 0;
	reverse_rotate_a(data);
	reverse_rotate_b(data);
	if (print_switched == 1)
	{
		ft_printf("rrr\n");
		data->printing_enabled = 1;
	}
	data->move_counter.rrr++;
	data->move_counter.rra--;
	data->move_counter.rrb--;
}
