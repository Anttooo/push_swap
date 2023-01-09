#include "../push_swap.h"

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.

void	swap_b(t_stacks *stacks)
{
	int	temp_holder;

	if (stacks->b_len >= 2)
	{
		temp_holder = stacks->b[0].value;
		stacks->b[0].value = stacks->b[1].value;
		stacks->b[1].value = temp_holder;
	}
	stacks->move_count++;
	stacks->moves.swap_b++;
}