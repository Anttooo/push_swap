#include "../push_swap.h"

// Shift down all elements of stack a by 1. The last element becomes the first one.

void	reverse_rotate_a(t_stacks *stacks)
{
	int	temp_holder;
	int	i;

	i = stacks->a_len - 1;
	if (stacks->a_len > 1)
	{
		temp_holder = stacks->a[i];
		while (i > 0)
		{
			stacks->a[i] = stacks->a[i - 1];
			i--;
		}
		stacks->a[0] = temp_holder;
	}
}