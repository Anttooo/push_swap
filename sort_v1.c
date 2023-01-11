#include "push_swap.h"

void	organise_b(t_stacks *stacks);
void	calculate_limits(t_stacks *stacks);
void	sort_b(t_stacks *stacks);

void	sort_v1(t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->split++;
	calculate_limits(stacks);
	// push all values below or equal to pivot into B
	while (i < stacks->a_len) 
	{
		// ft_printf("i: %d\n", i);
		// ft_printf("stacks->[a]: %d\n", stacks->a[i]);
		// ft_printf("stacks->a_len: %d\n", stacks->a_len);
		if (stacks->a[0].value <= stacks->upper_limit && stacks->a[0].value >= stacks->lower_limit)
		{
			// ft_printf("pa\n");
			push_to_b(stacks);
		}
		else
		{
			// ft_printf("ra\n");
			rotate_a(stacks);
			i++;
		}
	}
	sort_b(stacks);
}

void	calculate_limits(t_stacks *stacks)
{
	int	total_range;

	total_range = stacks->max - stacks->min;
	if (stacks->split == 1)
		stacks->upper_limit = stacks->max;
	else
		stacks->upper_limit = stacks->lower_limit - 1;
	if (stacks->split == stacks->nr_of_splits)
		stacks->lower_limit = stacks->min;
	else
		stacks->lower_limit = stacks->max - total_range / stacks->nr_of_splits * stacks->split - 1;
	// ft_printf("lower limit: %d, upper limit: %d\n", stacks->lower_limit, stacks->upper_limit);
}
