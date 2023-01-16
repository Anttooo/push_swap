#include "push_swap.h"

void	reset_move_count(t_data *data, int i);
void	compute_moves_needed_for_data(t_data *data, int i);
void	compute_optimal_rotations(t_data *data, int i);
void	update_total_move_count_for_index(t_data *data, int i); // this is also declared in the .h file

void	complete_next_move(t_data *data) // TODO: rename (or restructure) this as the function handles multiple things at them moment and that's not reflected in the name
{
	while (data->b_len > 0)
	{
		compute_indexes_in_a_for_b_values(data);
		compute_optimal_move_for_each(data);
		execute_move_with_least_steps(data);
	}
	// this part is rotating A so that the smallest number is at index 0, it should be a separate function
	if (data->b_len == 0)
	{
		 
		while (data->a[0].index != 0) // TODO: pick the direction with less steps
		{
			reverse_rotate_a(data);
			calculate_indexes_in_A(data);
		}
	}
}

void	compute_optimal_move_for_each(t_data *data)
{
	int	i;

	i = 0;
	data->optimal_item_to_move = 0;
	while (i < data->b_len)
	{
		reset_move_count(data, i);
		compute_moves_needed_for_data(data, i);
		compute_optimal_rotations(data, i);
		data->b[i].required_moves.push_a = 1;
		update_total_move_count_for_index(data, i); // TODO: rename
		if (data->b[i].required_moves.total < data->b[data->optimal_item_to_move].required_moves.total) // TODO: line too long
			data->optimal_item_to_move = i;
		i++;
	}
}


// To rotate a to correct place, the number at index 0 has to be the next one from the one being pushed, so larger.
// The correct relative index to have as [0] is the index of the number being pushed.
void	compute_moves_needed_for_data(t_data *data, int i)
{
	int	index_in_a;

	if (data->b[i].index + data->zero_index > data->a_len)
		index_in_a = data->b[i].index + data->zero_index - data->a_len;
	else
		index_in_a = data->b[i].index + data->zero_index;
	data->b[i].required_moves.ra = index_in_a;
	data->b[i].required_moves.rra = (data->a_len - index_in_a);
	data->b[i].required_moves.rb = i;
	data->b[i].required_moves.rrb = data->b_len - i;
}

void	reset_move_count(t_data *data, int i)
{
	data->b[i].required_moves.push_a = 0;
	data->b[i].required_moves.push_b = 0;
	data->b[i].required_moves.rra = 0;
	data->b[i].required_moves.rrb = 0;
	data->b[i].required_moves.rrr = 0;
	data->b[i].required_moves.ra = 0;
	data->b[i].required_moves.rb = 0;
	data->b[i].required_moves.rr = 0;
	data->b[i].required_moves.swap_a = 0;
	data->b[i].required_moves.swap_b = 0;
	data->b[i].required_moves.swap_both = 0;
	data->b[i].required_moves.total = 0;
}
