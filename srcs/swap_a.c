#include "../push_swap.h"

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.

void	swap_a(t_stacks *stacks)
{
	int	temp_holder;

	if (stacks->a_len >= 2)
	{
		temp_holder = stacks->a[0].value;
		stacks->a[0].value = stacks->a[1].value;
		stacks->a[1].value = temp_holder;
	}
	if (stacks->printing_enabled == 1)
		ft_printf("sa\n");
	stacks->move_count++;
	stacks->moves.swap_a++;
}