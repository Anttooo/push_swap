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

// Main sorting function that controls the flow of sorting
void	sort_stack(t_data *data)
{
	initialise_stack_b(data);
	prepare_b(data);
	sort_a(data);
	while (is_sorted(data) != 1)
		complete_next_move(data);
}

// Allocates memory for stack 'b' and exits the program if allocation fails
void	initialise_stack_b(t_data *data)
{
	data->b = (t_list_item *)malloc(data->org_len * sizeof(t_list_item));
	if (data->b == NULL)
	{
		freemem(data);
		exit(1);
	}
}

// checks if stack 'a' is sorted
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

// updates the total count of moves for a specific index in stack 'b'
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
