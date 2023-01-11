#include "push_swap.h"

void	get_indexes_for_median(t_stacks *stacks)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (i < stacks->a_len)
	{
		stacks->a[i].index = 0;
		i++;
	}
	i = 0;
	while (i < stacks->a_len)
	{
		j = 0;
		index = 0;
		while (j < stacks->a_len)
		{
			if (stacks->a[j].value < stacks->a[i].value)
				index++;
			j++;
		}
		stacks->a[i].index = index;
		ft_printf("number %d of A gets index %d\n", stacks->a[i].value, index);
		i++;
	}
}