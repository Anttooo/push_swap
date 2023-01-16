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