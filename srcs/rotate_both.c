#include "../push_swap.h"

void	rotate_both(t_stacks *stacks)
{
	int	print_switched;

	if (stacks->printing_enabled == 1)
	{
		print_switched = 1;
		stacks->printing_enabled = 0;
	}
	else
		print_switched = 0;
	rotate_a(stacks);
	rotate_b(stacks);
	if (print_switched == 1)
	{
		ft_printf("rr\n");
		stacks->printing_enabled = 1;
	}
	stacks->move_counter.rotate_both++;
	stacks->move_counter.total--;
	stacks->move_counter.rotate_a--;
	stacks->move_counter.rotate_b--;
}