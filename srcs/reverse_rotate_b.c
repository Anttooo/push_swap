#include "../push_swap.h"

// Shift down all elements of stack a by 1. The last element becomes the first one.

void	reverse_rotate_b(t_stacks *stacks)
{
	int	temp_holder;
	int	i;

	i = stacks->b_len - 1;
	if (stacks->b_len > 1)
	{
		temp_holder = stacks->b[i];
		while (i > 0)
		{
			stacks->b[i] = stacks->b[i - 1];
			i--;
		}
		stacks->b[0] = temp_holder;
	}
}