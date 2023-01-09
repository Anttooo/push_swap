#include "../push_swap.h"

// Shift up all elements of stack a by 1. The first element becomes the last one.

void	rotate_a(t_stacks *stacks)
{
	int	temp_holder;
	int	i;

	i = 0;
	if (stacks->a_len > 1)
	{
		temp_holder = stacks->a[0];
		while (i < stacks->a_len - 1)
		{
			stacks->a[i] = stacks->a[i + 1];
			i++;
		}
		stacks->a[stacks->a_len - 1] = temp_holder;
	}
}