#include "../push_swap.h"

void	swap_both(t_stacks *stacks)
{
	int	print_switched;

	if (stacks->printing_enabled == 1)
	{
		print_switched = 1;
		stacks->printing_enabled = 0;
	}
	else
		print_switched = 0;
	swap_a(stacks);
	swap_b(stacks);
	if (print_switched == 1)
	{
		ft_printf("ss\n");
		stacks->printing_enabled = 1;
	}
	stacks->moves.swap_both++;
	stacks->move_count--;
	stacks->moves.swap_a--;
	stacks->moves.swap_b--;
}