#include "push_swap.h"

void	calculate_indexes_in_A(t_stacks *stacks)
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
		// ft_printf("number %d of A gets index %d\n", stacks->a[i].value, index);
		i++;
	}
}

void	compute_indexes_in_a_for_b_values(t_stacks *stacks)
{
	update_index_of_smallest_value_in_a(stacks);
	reset_stack_b_indexes(stacks);
	compute_index_for_each(stacks);
}

void	update_index_of_smallest_value_in_a(t_stacks *stacks)
{
	int	i;

	i = 0;	
	stacks->zero_index = 0;
	calculate_indexes_in_A(stacks);
	while (i < stacks->a_len)
	{
		if (stacks->a[i].index == 0)
			stacks->zero_index = i;
		i++;
	}
}

void	reset_stack_b_indexes(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->b_len)
	{
		stacks->b[i].index = 0;
		i++;
	}
}

void	compute_index_for_each(t_stacks *stacks)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (i < stacks->b_len)
	{
		j = 0;
		index = 0;
		while (j < stacks->a_len)
		{
			if (j + stacks->zero_index < stacks->a_len)
			{
				if (stacks->b[i].value > stacks->a[j + stacks->zero_index].value) // TODO: line too long
					index++;
			}
			else
			{
				if (stacks->b[i].value > stacks->a[(j + stacks->zero_index) - stacks->a_len].value) // TODO: line too long
					index++;				
			}
			j++;
		}
		stacks->b[i].index = index;
		i++;
	}
}