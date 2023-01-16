#include "push_swap.h"

void	execute_instruction(t_stacks *stacks, void (*f)(t_stacks *), int moves)
{
	while (moves > 0)
	{
		f(stacks);
		moves--;
	}
}

void	execute_move_with_least_steps(t_stacks *stacks)
{
	int	i;

	i = stacks->index_with_least_moves_required;
	execute_instruction(stacks, rotate_a, stacks->b[i].required_moves.ra);
	execute_instruction(stacks, rotate_b, stacks->b[i].required_moves.rb);
	execute_instruction(stacks, rotate_both, stacks->b[i].required_moves.rr);
	execute_instruction(stacks, reverse_rotate_a, stacks->b[i].required_moves.rra); // TODO: line too long
	execute_instruction(stacks, reverse_rotate_b, stacks->b[i].required_moves.rrb); // TODO: line too long
	execute_instruction(stacks, reverse_rotate_both, stacks->b[i].required_moves.rrr); // TODO: line too long
	// Push to A
	push_to_a(stacks);
}