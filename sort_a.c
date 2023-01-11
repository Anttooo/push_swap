#include "push_swap.h"

void	sort_a(t_stacks *stacks)
{
	if (stacks->a[0].value < stacks->a[1].value && stacks->a[1].value < stacks->a[2].value);
		// already sorted do nothing
	else if (stacks->a[0].value < stacks->a[1].value && stacks->a[2].value < stacks->a[1].value)
	{
		// ft_printf("ra\n");
		rotate_a(stacks);
		// ft_printf("sa\n");
		swap_a(stacks);
		// ft_printf("rra\n");
		reverse_rotate_a(stacks);
	}
	else if (stacks->a[2].value < stacks->a[1].value && stacks->a[0].value < stacks->a[1].value)
	{
		// ft_printf("sa\n");
		reverse_rotate_a(stacks);
	}
}