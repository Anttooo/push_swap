#include "../push_swap.h"

void	reverse_rotate_both(t_stacks *stacks)
{
	reverse_rotate_a(stacks);
	reverse_rotate_b(stacks);
	stacks->moves.reverse_rotate_both++;
	stacks->move_count--;
	stacks->moves.reverse_rotate_a--;
	stacks->moves.reverse_rotate_b--;
}