#include "../push_swap.h"

// Shift up all elements of stack a by 1. The first element becomes the last one.

void	rotate_b(t_stacks *stacks)
{
	int	temp_holder;
	int	i;

	i = 0;
	if (stacks->b_len > 1)
	{
		temp_holder = stacks->b[0].value;
		while (i < stacks->b_len - 1)
		{
			stacks->b[i].value = stacks->b[i + 1].value;
			i++;
		}
		stacks->b[stacks->b_len - 1].value = temp_holder;
	}
	if (stacks->printing_enabled == 1)
		ft_printf("rb\n");
	stacks->move_counter.rb++;
}