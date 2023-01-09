#include "../push_swap.h"

// Shift up all elements of stack a by 1. The first element becomes the last one.

void	rotate_a(t_stacks *stacks)
{
	int	temp_holder;
	int	i;

	i = 0;
	if (stacks->a_len > 1)
	{
		temp_holder = stacks->a[0].value;
		while (i < stacks->a_len - 1)
		{
			stacks->a[i].value = stacks->a[i + 1].value;
			i++;
		}
		stacks->a[stacks->a_len - 1].value = temp_holder;
	}
	stacks->move_count++;
	stacks->moves.rotate_a++;
}