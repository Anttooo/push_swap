#include "push_swap.h"

void	organise_b(t_stacks *stacks);

void	sort_v1(t_stacks *stacks)
{
	// split the stack into two based on average number
	if (stacks->a[0] > stacks->a[1] && stacks->a_len > 1)
	{
		ft_printf("sa\n");
		swap_a(stacks);
		ft_printf("pa\n");
		push_to_b(stacks);
	}
}