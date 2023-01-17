/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_indexes_helpers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:10:40 by oanttoor          #+#    #+#             */
/*   Updated: 2023/01/17 13:10:41 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	some_function_name(t_data *data, int *i);

void	compute_index_for_each(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->b_len)
	{
		some_function_name(data, &i);
	}
}

void	some_function_name(t_data *data, int *i)
{
	int	j;
	int	index;

	j = 0;
	index = 0;
	while (j < data->a_len)
	{
		if (j + data->zero_index < data->a_len)
		{
			if (data->b[*i].value > data->a[j + data->zero_index].value)
				index++;
		}
		else
		{
			if (data->b[*i].value > data->a[(j + data->zero_index) - \
							data->a_len].value)
				index++;
		}
		j++;
	}
	data->b[*i].index = index;
	*i = *i + 1;
}
