#include "push_swap.h"

void	reset_move_count(t_stacks *stacks, int i);
void	compute_moves_needed_for_stacks(t_stacks *stacks, int i);
void	compute_optimal_rotations(t_stacks *stacks, int i);
void	update_total_move_count_for_index(t_stacks *stacks, int i); // this is also declared in the .h file

void	complete_next_move(t_stacks *stacks) // TODO: rename (or restructure) this as the function handles multiple things at them moment and that's not reflected in the name
{
	while (stacks->b_len > 0)
	{
		compute_indexes_in_a_for_b_values(stacks);
		compute_optimal_move_for_each(stacks);
		execute_move_with_least_steps(stacks);
	}
	// this part is rotating A so that the smallest number is at index 0, it should be a separate function
	if (stacks->b_len == 0)
	{
		 
		while (stacks->a[0].index != 0) // TODO: pick the direction with less steps
		{
			reverse_rotate_a(stacks);
			calculate_indexes_in_A(stacks);
		}
	}
}

void	compute_optimal_move_for_each(t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->index_with_least_moves_required = 0;
	while (i < stacks->b_len)
	{
		reset_move_count(stacks, i);
		compute_moves_needed_for_stacks(stacks, i);
		compute_optimal_rotations(stacks, i);
		stacks->b[i].required_moves.push_a = 1;
		update_total_move_count_for_index(stacks, i); // TODO: rename
		if (stacks->b[i].required_moves.total < stacks->b[stacks->index_with_least_moves_required].required_moves.total) // TODO: line too long
			stacks->index_with_least_moves_required = i;
		i++;
	}
}


// To rotate a to correct place, the number at index 0 has to be the next one from the one being pushed, so larger.
// The correct relative index to have as [0] is the index of the number being pushed.
void	compute_moves_needed_for_stacks(t_stacks *stacks, int i)
{
	int	index_in_a;

	if (stacks->b[i].index + stacks->zero_index > stacks->a_len)
		index_in_a = stacks->b[i].index + stacks->zero_index - stacks->a_len;
	else
		index_in_a = stacks->b[i].index + stacks->zero_index;
	stacks->b[i].required_moves.ra = index_in_a;
	stacks->b[i].required_moves.rra = (stacks->a_len - index_in_a);
	stacks->b[i].required_moves.rb = i;
	stacks->b[i].required_moves.rrb = stacks->b_len - i;
}

void	reset_move_count(t_stacks *stacks, int i)
{
	stacks->b[i].required_moves.push_a = 0;
	stacks->b[i].required_moves.push_b = 0;
	stacks->b[i].required_moves.rra = 0;
	stacks->b[i].required_moves.rrb = 0;
	stacks->b[i].required_moves.rrr = 0;
	stacks->b[i].required_moves.ra = 0;
	stacks->b[i].required_moves.rb = 0;
	stacks->b[i].required_moves.rr = 0;
	stacks->b[i].required_moves.swap_a = 0;
	stacks->b[i].required_moves.swap_b = 0;
	stacks->b[i].required_moves.swap_both = 0;
	stacks->b[i].required_moves.total = 0;
}
