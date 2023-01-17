/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:22:39 by oanttoor          #+#    #+#             */
/*   Updated: 2023/01/17 10:22:41 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_data *data);
void	initialise_stack_b(t_data *data);

void	sort_stack(t_data *data)
{
	initialise_stack_b(data);
	prepare_b(data);
	sort_a(data);
	while (is_sorted(data) != 1)
		complete_next_move(data);
	update_total_move_count(&data->move_counter);
	print_result(data); // TODO: remove this before submitting
}

void	initialise_stack_b(t_data *data)
{
	data->b = (t_list_item *)malloc(data->org_len * sizeof(t_list_item));
	if (data->b == NULL)
	{
		freemem(data);
		exit(1);
	}
}

int	is_sorted(t_data *data)
{
	int	i;

	i = 0;
	if (data->a_len < data->org_len)
		return (0);
	while (i < data->a_len - 1)
	{
		if (data->a[i].value < data->a[i + 1].value)
			i++;
		else
			return (0);
	}
	return (1);
}

void	update_total_move_count(t_moves *move_counter)
{
	int	*total;

	total = &move_counter->total;
	*total = 0;
	*total = *total + move_counter->push_a;
	*total = *total + move_counter->push_b;
	*total = *total + move_counter->rra;
	*total = *total + move_counter->rrb;
	*total = *total + move_counter->rrr;
	*total = *total + move_counter->ra;
	*total = *total + move_counter->rb;
	*total = *total + move_counter->rr;
	*total = *total + move_counter->swap_a;
	*total = *total + move_counter->swap_b;
	*total = *total + move_counter->swap_both;
}

void	update_total_move_count_for_index(t_data *data, int i)
{
	int	*total;

	total = &data->b[i].required_moves.total;
	*total = 0;
	*total = *total + data->b[i].required_moves.push_a;
	*total = *total + data->b[i].required_moves.push_b;
	*total = *total + data->b[i].required_moves.rra;
	*total = *total + data->b[i].required_moves.rrb;
	*total = *total + data->b[i].required_moves.rrr;
	*total = *total + data->b[i].required_moves.ra;
	*total = *total + data->b[i].required_moves.rb;
	*total = *total + data->b[i].required_moves.rr;
	*total = *total + data->b[i].required_moves.swap_a;
	*total = *total + data->b[i].required_moves.swap_b;
	*total = *total + data->b[i].required_moves.swap_both;
}
