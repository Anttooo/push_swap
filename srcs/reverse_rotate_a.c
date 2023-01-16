#include "../push_swap.h"

// Shift down all elements of stack a by 1. The last element becomes the first one.

void	reverse_rotate_a(t_stacks *stacks)
{
	int	temp_holder;
	int	i;

	i = stacks->a_len - 1;
	if (stacks->a_len > 1)
	{
		temp_holder = stacks->a[i].value;
		while (i > 0)
		{
			stacks->a[i].value = stacks->a[i - 1].value;
			i--;
		}
		stacks->a[0].value = temp_holder;
	}
	if (stacks->printing_enabled == 1)
		ft_printf("rra\n");
	stacks->move_counter.rra++;
}