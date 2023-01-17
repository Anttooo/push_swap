/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_indexes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:19:16 by oanttoor          #+#    #+#             */
/*   Updated: 2023/01/17 10:19:32 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_indexes_in_a(t_data *data)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (i < data->a_len)
	{
		data->a[i].index = 0;
		i++;
	}
	i = 0;
	while (i < data->a_len)
	{
		j = 0;
		index = 0;
		while (j < data->a_len)
		{
			if (data->a[j].value < data->a[i].value)
				index++;
			j++;
		}
		data->a[i].index = index;
		i++;
	}
}

void	compute_indexes_in_a_for_b_values(t_data *data)
{
	update_index_of_smallest_value_in_a(data);
	reset_stack_b_indexes(data);
	compute_index_for_each(data);
}

void	update_index_of_smallest_value_in_a(t_data *data)
{
	int	i;

	i = 0;
	data->zero_index = 0;
	calculate_indexes_in_a(data);
	while (i < data->a_len)
	{
		if (data->a[i].index == 0)
			data->zero_index = i;
		i++;
	}
}

void	reset_stack_b_indexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->b_len)
	{
		data->b[i].index = 0;
		i++;
	}
}
