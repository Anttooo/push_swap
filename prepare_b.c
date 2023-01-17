/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:20:35 by oanttoor          #+#    #+#             */
/*   Updated: 2023/01/17 10:20:36 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_limits(t_data *data);
void	push_split_into_b(t_data *data);
int		count_values_to_move(t_data *data);
void	keep_min_max_median_push_rest(t_data *data, int *i, int *pushed);

void	prepare_b(t_data *data)
{
	find_median(data);
	while (data->split < 2 && data->a_len > 3)
	{
		calculate_limits(data);
		push_split_into_b(data);
		data->split++;
	}
}

void	push_split_into_b(t_data *data)
{
	int	i;
	int	values_to_push;
	int	pushed;

	i = 0;
	values_to_push = count_values_to_move(data);
	pushed = 0;
	while (i <= data->a_len && pushed < values_to_push)
		keep_min_max_median_push_rest(data, &i, &pushed);
}

void	keep_min_max_median_push_rest(t_data *data, int *i, int *pushed)
{
	if (data->a[0].value == data->max || data->a[0].value == data->min || \
		data->a[0].value == data->median)
	{
		rotate_a(data);
		*i = *i + 1;
	}
	else if (data->a[0].value <= data->upper_limit && \
		data->a[0].value >= data->lower_limit)
	{
		*pushed = *pushed + 1;
		push_to_b(data);
	}
	else
	{
		rotate_a(data);
		*i = *i + 1;
	}
}

int	count_values_to_move(t_data *data)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i <= data->a_len)
	{
		if (data->a[i].value == data->max || data->a[i].value == data->min \
			|| data->a[i].value == data->median)
			counter = counter + 0;
		else if (data->a[i].value <= data->upper_limit \
			&& data->a[i].value >= data->lower_limit)
			counter++;
		i++;
	}
	return (counter);
}

void	calculate_limits(t_data *data)
{
	if (data->split == 0)
	{
		data->lower_limit = data->min;
		data->upper_limit = data->median;
	}
	else
	{
		data->lower_limit = data->median + 1;
		data->upper_limit = data->max;
	}
}
