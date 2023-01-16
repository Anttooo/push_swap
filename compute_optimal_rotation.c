#include "push_swap.h"

void	compute_optimal_rotations(t_stacks *stacks, int i)
{
	int	without_combination;
	int	reverse_rotate;
	int	rotate;

	without_combination = get_moves_with_both_directions(stacks, i);
	reverse_rotate = get_moves_with_reverse_rotate(stacks, i);
	rotate = get_moves_with_rotate(stacks, i);
	if (without_combination < reverse_rotate && without_combination < rotate)
		use_both_directions(stacks, i);
	else if (reverse_rotate < without_combination && reverse_rotate < rotate)
		use_reverse_rotate(stacks, i);
	else
		use_rotate(stacks, i);

}

int	get_moves_with_both_directions(t_stacks *stacks, int i)
{
	int	moves;

	moves = 0;
	if (stacks->b[i].required_moves.rra < stacks->b[i].required_moves.ra)
		moves = stacks->b[i].required_moves.rra;
	else
		moves = stacks->b[i].required_moves.ra;
	if (stacks->b[i].required_moves.rrb < stacks->b[i].required_moves.rb)
		moves = moves + stacks->b[i].required_moves.rrb;
	else
		moves = moves + stacks->b[i].required_moves.rb;
	return (moves);
}

int	get_moves_with_reverse_rotate(t_stacks *stacks, int i)
{
	int	moves;
	
	moves = 0;
	if (stacks->b[i].required_moves.rrb >= stacks->b[i].required_moves.rra)
	{
		moves = stacks->b[i].required_moves.rrb;
	}
	else 
		moves = stacks->b[i].required_moves.rra;
	return (moves);
}

int	get_moves_with_rotate(t_stacks *stacks, int i)
{
	int	moves;
	
	moves = 0;
	if (stacks->b[i].required_moves.rb >= stacks->b[i].required_moves.ra)
	{
		moves = stacks->b[i].required_moves.rb;
	}
	else 
		moves = stacks->b[i].required_moves.ra;
	return (moves);
}
