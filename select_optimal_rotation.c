/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_optimal_rotation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:22:02 by oanttoor          #+#    #+#             */
/*   Updated: 2023/01/17 10:22:06 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
function that decides which direction to use for rotate when both 
rotate to different directions. Selects the shorter for both.
*/
void	use_both_directions(t_data *data, int i)
{
	if (data->b[i].required_moves.rra < data->b[i].required_moves.ra)
		data->b[i].required_moves.ra = 0;
	else
		data->b[i].required_moves.rra = 0;
	if (data->b[i].required_moves.rrb < data->b[i].required_moves.rb)
		data->b[i].required_moves.rb = 0;
	else
		data->b[i].required_moves.rrb = 0;
}

/* 
changes the values of required moves so that both stacks are sorted with
reverse rotate, using reverse_rotate_both when possible.
*/
void	use_reverse_rotate(t_data *data, int i)
{	
	data->b[i].required_moves.rb = 0;
	data->b[i].required_moves.ra = 0;
	if (data->b[i].required_moves.rrb >= data->b[i].required_moves.rra)
	{
		data->b[i].required_moves.rrb = data->b[i].required_moves.rrb - \
			data->b[i].required_moves.rra;
		data->b[i].required_moves.rrr = data->b[i].required_moves.rra;
		data->b[i].required_moves.rra = 0;
	}
	else
	{
		data->b[i].required_moves.rra = data->b[i].required_moves.rra - \
			data->b[i].required_moves.rrb;
		data->b[i].required_moves.rrr = data->b[i].required_moves.rrb;
		data->b[i].required_moves.rrb = 0;
	}
}

/* 
changes the values of required moves so that both stacks are sorted with
rotate, using rotate_both when possible.
*/
void	use_rotate(t_data *data, int i)
{
	data->b[i].required_moves.rrb = 0;
	data->b[i].required_moves.rra = 0;
	if (data->b[i].required_moves.rb >= data->b[i].required_moves.ra)
	{
		data->b[i].required_moves.rb = data->b[i].required_moves.rb - \
			data->b[i].required_moves.ra;
		data->b[i].required_moves.rr = data->b[i].required_moves.ra;
		data->b[i].required_moves.ra = 0;
	}
	else
	{
		data->b[i].required_moves.ra = data->b[i].required_moves.ra - \
			data->b[i].required_moves.rb;
		data->b[i].required_moves.rr = data->b[i].required_moves.rb;
		data->b[i].required_moves.rb = 0;
	}
}
