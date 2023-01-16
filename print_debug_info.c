#include "push_swap.h"

void	print_stacks(t_stacks *stacks)
{
	int	i;

	i = 0;
	ft_printf("STACK A: ");
	while (i < stacks->a_len)
	{
		ft_printf("%d ", stacks->a[i].value);
		i++;
	}
	ft_printf("\n");
	i = 0;
	ft_printf("STACK B: ");
	while (i < stacks->b_len)
	{
		ft_printf("%d ", stacks->b[i].value);
		i++;
	}
	ft_printf("\n");
}

void	print_result(t_stacks *stacks)
{
	update_total_move_count(&stacks->move_counter);
	if (is_sorted(stacks) == 1 && stacks->a_len == stacks->org_len)
		ft_printf("\nSORTED in %d moves!\n", stacks->move_counter.total);
	else
		ft_printf("NOT SORTED in %d moves!\n", stacks->move_counter.total);
}