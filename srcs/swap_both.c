#include "../push_swap.h"

void	swap_both(t_stacks *stacks)
{
	swap_a(stacks);
	swap_b(stacks);
	stacks->moves.swap_both++;
	stacks->move_count--;
	stacks->moves.swap_a--;
	stacks->moves.swap_b--;
}