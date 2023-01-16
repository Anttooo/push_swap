
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

typedef struct s_stacks 
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
	int			index_with_least_moves_required;
}		t_stacks;

// add function definitions here
void	sort_stack(t_stacks *stacks);
void	freemem(t_stacks *stacks);
void	prepare_b(t_stacks *stacks);
void	complete_next_move(t_stacks *stacks);
void	sort_a(t_stacks *stacks);
void	calculate_indexes_in_A(t_stacks *stacks);
void	print_stacks(t_stacks *stacks);
void	update_total_move_count(t_moves *move_counter);
void	update_total_move_count_for_index(t_stacks *stacks, int i);
void	initialise_data(t_stacks *stacks, int argc);

// compute indexes in A
void	compute_indexes_in_a_for_b_values(t_stacks *stacks);
void	update_index_of_smallest_value_in_a(t_stacks *stacks);
void	reset_stack_b_indexes(t_stacks *stacks);
void	compute_index_for_each(t_stacks *stacks);


// compute optimal moves
void	compute_optimal_move_for_each(t_stacks *stacks);
void	compute_optimal_rotations(t_stacks *stacks, int i);

// functions for figuring out optimal rotation
int	get_moves_with_both_directions(t_stacks *stacks, int i);
int	get_moves_with_reverse_rotate(t_stacks *stacks, int i);
int	get_moves_with_rotate(t_stacks *stacks, int i);
void	use_both_directions(t_stacks *stacks, int i);
void	use_reverse_rotate(t_stacks *stacks, int i);
void	use_rotate(t_stacks *stacks, int i);

// Execute the move with least steps
void	execute_move_with_least_steps(t_stacks *stacks);
void	execute_instruction(t_stacks *stacks, void (*f)(t_stacks *), int moves);

// Debug printing, remove before submitting
void	print_stacks(t_stacks *stacks);
void	print_result(t_stacks *stacks);
int	is_sorted(t_stacks *stacks);

// Push swap language instructions, not included in the final version
void	push_to_a(t_stacks *stacks);
void	push_to_b(t_stacks *stacks);
void	swap_a(t_stacks *stacks);
void	swap_b(t_stacks *stacks);
void	swap_both(t_stacks *stacks);
void	rotate_a(t_stacks *stacks);
void	rotate_b(t_stacks *stacks);
void	rotate_both(t_stacks *stacks);
void	reverse_rotate_a(t_stacks *stacks);
void	reverse_rotate_b(t_stacks *stacks);
void	reverse_rotate_both(t_stacks *stacks);

#endif
