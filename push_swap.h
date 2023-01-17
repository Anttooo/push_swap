/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:46:59 by oanttoor          #+#    #+#             */
/*   Updated: 2023/01/17 10:47:00 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_moves
{
	int	push_a;
	int	push_b;
	int	rra;
	int	rrb;
	int	rrr;
	int	ra;
	int	rb;
	int	rr;
	int	swap_a;
	int	swap_b;
	int	swap_both;
	int	total;
}		t_moves;

typedef struct s_list_item
{
	int		value;
	int		index;
	t_moves	required_moves;
}		t_list_item;

typedef struct s_data
{
	t_list_item	*a;
	t_list_item	*b;
	t_moves		move_counter;
	int			b_len;
	int			a_len;
	int			org_len;
	int			max;
	int			min;
	int			split;
	int			nr_of_splits;
	int			upper_limit;
	int			lower_limit;
	int			zero_index;
	int			median;
	int			printing_enabled;
	int			optimal_item_to_move;
}		t_data;

// add function definitions here
void	sort_stack(t_data *data);
void	freemem(t_data *data);
void	prepare_b(t_data *data);
void	complete_next_move(t_data *data);
void	sort_a(t_data *data);
void	calculate_indexes_in_a(t_data *data);
void	print_data(t_data *data);
void	find_median(t_data *data);
void	update_total_move_count(t_moves *move_counter);
void	update_total_move_count_for_index(t_data *data, int i);
void	initialise_data(t_data *data, int argc);

// compute indexes in A
void	compute_indexes_in_a_for_b_values(t_data *data);
void	update_index_of_smallest_value_in_a(t_data *data);
void	reset_stack_b_indexes(t_data *data);
void	compute_index_for_each(t_data *data);

// compute optimal moves
void	compute_optimal_move_for_each(t_data *data);
void	compute_optimal_rotations(t_data *data, int i);

// functions for figuring out optimal rotation
int		get_moves_with_both_directions(t_data *data, int i);
int		get_moves_with_reverse_rotate(t_data *data, int i);
int		get_moves_with_rotate(t_data *data, int i);
void	use_both_directions(t_data *data, int i);
void	use_reverse_rotate(t_data *data, int i);
void	use_rotate(t_data *data, int i);

// Execute the move with least steps
void	execute_move_with_least_steps(t_data *data);
void	execute_instruction(t_data *data, void (*f)(t_data *), int moves);

// Debug printing, remove before submitting
void	print_data(t_data *data);
void	print_result(t_data *data);
int		is_sorted(t_data *data);

// Sort a
int		is_acb(int a, int b, int c);
int		is_bca(int a, int b, int c);
int		is_cab(int a, int b, int c);
int		is_bac(int a, int b, int c);
int		is_cba(int a, int b, int c);

// Push swap language instructions, not included in the final version
void	push_to_a(t_data *data);
void	push_to_b(t_data *data);
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	swap_both(t_data *data);
void	rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	rotate_both(t_data *data);
void	reverse_rotate_a(t_data *data);
void	reverse_rotate_b(t_data *data);
void	reverse_rotate_both(t_data *data);

#endif
