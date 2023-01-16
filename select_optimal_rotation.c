#include "push_swap.h"

void	use_both_directions(t_stacks *stacks, int i)
{
	if (stacks->b[i].required_moves.rra < stacks->b[i].required_moves.ra)
		stacks->b[i].required_moves.ra = 0;
	else
		stacks->b[i].required_moves.rra = 0;
	if (stacks->b[i].required_moves.rrb < stacks->b[i].required_moves.rb)
		stacks->b[i].required_moves.rb = 0;
	else
		stacks->b[i].required_moves.rrb = 0;
}

void	use_reverse_rotate(t_stacks *stacks, int i)
{	
	stacks->b[i].required_moves.rb = 0;
	stacks->b[i].required_moves.ra = 0;
	if (stacks->b[i].required_moves.rrb >= stacks->b[i].required_moves.rra)
	{
		stacks->b[i].required_moves.rrb = stacks->b[i].required_moves.rrb - stacks->b[i].required_moves.rra; // TODO: line too long
		stacks->b[i].required_moves.rrr = stacks->b[i].required_moves.rra;
		stacks->b[i].required_moves.rra = 0;
	}
	else
	{
		stacks->b[i].required_moves.rra = stacks->b[i].required_moves.rra - stacks->b[i].required_moves.rrb; // TODO: line too long
		stacks->b[i].required_moves.rrr = stacks->b[i].required_moves.rrb;
		stacks->b[i].required_moves.rrb = 0;
	}
}

void	use_rotate(t_stacks *stacks, int i)
{
	stacks->b[i].required_moves.rrb = 0;
	stacks->b[i].required_moves.rra = 0;
	if (stacks->b[i].required_moves.rb >= stacks->b[i].required_moves.ra)
	{
		stacks->b[i].required_moves.rb = stacks->b[i].required_moves.rb - stacks->b[i].required_moves.ra; // TODO: line too long
		stacks->b[i].required_moves.rr = stacks->b[i].required_moves.ra;
		stacks->b[i].required_moves.ra = 0;
	}
	else
	{
		stacks->b[i].required_moves.ra = stacks->b[i].required_moves.ra - stacks->b[i].required_moves.rb; // TODO: line too long
		stacks->b[i].required_moves.rr = stacks->b[i].required_moves.rb;
		stacks->b[i].required_moves.rb = 0;
	}
}