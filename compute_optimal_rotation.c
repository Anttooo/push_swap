/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_optimal_rotation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:19:56 by oanttoor          #+#    #+#             */
/*   Updated: 2023/01/17 10:19:57 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compute_optimal_rotations(t_data *data, int i)
{
	int	without_combination;
	int	reverse_rotate;
	int	rotate;

	without_combination = get_moves_with_both_directions(data, i);
	reverse_rotate = get_moves_with_reverse_rotate(data, i);
	rotate = get_moves_with_rotate(data, i);
	if (without_combination < reverse_rotate && without_combination < rotate)
		use_both_directions(data, i);
	else if (reverse_rotate < without_combination && reverse_rotate < rotate)
		use_reverse_rotate(data, i);
	else
		use_rotate(data, i);
}

int	get_moves_with_both_directions(t_data *data, int i)
{
	int	moves;

	moves = 0;
	if (data->b[i].required_moves.rra < data->b[i].required_moves.ra)
		moves = data->b[i].required_moves.rra;
	else
		moves = data->b[i].required_moves.ra;
	if (data->b[i].required_moves.rrb < data->b[i].required_moves.rb)
		moves = moves + data->b[i].required_moves.rrb;
	else
		moves = moves + data->b[i].required_moves.rb;
	return (moves);
}

int	get_moves_with_reverse_rotate(t_data *data, int i)
{
	int	moves;

	moves = 0;
	if (data->b[i].required_moves.rrb >= data->b[i].required_moves.rra)
		moves = data->b[i].required_moves.rrb;
	else
		moves = data->b[i].required_moves.rra;
	return (moves);
}

int	get_moves_with_rotate(t_data *data, int i)
{
	int	moves;

	moves = 0;
	if (data->b[i].required_moves.rb >= data->b[i].required_moves.ra)
		moves = data->b[i].required_moves.rb;
	else
		moves = data->b[i].required_moves.ra;
	return (moves);
}
