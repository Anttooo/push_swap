/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:20:49 by oanttoor          #+#    #+#             */
/*   Updated: 2023/01/17 10:20:50 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Prints the values of stack A and stack B
void	print_data(t_data *data)
{
	int	i;

	i = 0;
	ft_printf("STACK A: ");
	while (i < data->a_len)
	{
		ft_printf("%d ", data->a[i].value);
		i++;
	}
	ft_printf("\n");
	i = 0;
	ft_printf("STACK B: ");
	while (i < data->b_len)
	{
		ft_printf("%d ", data->b[i].value);
		i++;
	}
	ft_printf("\n");
}

/* Prints the result of the sort, if it was sorted or not, 
and the number of moves it took */
void	print_result(t_data *data)
{
	update_total_move_count(&data->move_counter);
	if (is_sorted(data) == 1 && data->a_len == data->org_len)
		ft_printf("\nSORTED in %d moves!\n", data->move_counter.total);
	else
		ft_printf("NOT SORTED in %d moves!\n", data->move_counter.total);
}

// updates the total count of moves performed
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
