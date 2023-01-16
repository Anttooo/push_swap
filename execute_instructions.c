#include "push_swap.h"

void	execute_instruction(t_data *data, void (*f)(t_data *), int moves)
{
	while (moves > 0)
	{
		f(data);
		moves--;
	}
}

void	execute_move_with_least_steps(t_data *data)
{
	int	i;

	i = data->optimal_item_to_move;
	execute_instruction(data, rotate_a, data->b[i].required_moves.ra);
	execute_instruction(data, rotate_b, data->b[i].required_moves.rb);
	execute_instruction(data, rotate_both, data->b[i].required_moves.rr);
	execute_instruction(data, reverse_rotate_a, data->b[i].required_moves.rra); // TODO: line too long
	execute_instruction(data, reverse_rotate_b, data->b[i].required_moves.rrb); // TODO: line too long
	execute_instruction(data, reverse_rotate_both, data->b[i].required_moves.rrr); // TODO: line too long
	// Push to A
	push_to_a(data);
}