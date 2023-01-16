#include "../push_swap.h"

void	reverse_rotate_both(t_stacks *stacks)
{
	int	print_switched;

	if (stacks->printing_enabled == 1)
	{
		print_switched = 1;
		stacks->printing_enabled = 0;
	}
	else
		print_switched = 0;
	reverse_rotate_a(stacks);
	reverse_rotate_b(stacks);
	if (print_switched == 1)
	{
		ft_printf("rrr\n");
		stacks->printing_enabled = 1;
	}
	stacks->move_counter.rrr++;
	stacks->move_counter.rra--;
	stacks->move_counter.rrb--;
}