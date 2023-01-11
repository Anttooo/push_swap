#include "../push_swap.h"

void	rotate_both(t_stacks *stacks)
{
	rotate_a(stacks);
	rotate_b(stacks);
	stacks->moves.rotate_both++;
	stacks->move_count--;
	stacks->moves.rotate_a--;
	stacks->moves.rotate_b--;
}