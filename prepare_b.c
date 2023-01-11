#include "push_swap.h"

void	organise_b(t_stacks *stacks);
void	calculate_limits(t_stacks *stacks);
void	push_split_into_b(t_stacks *stacks);
void	find_median(t_stacks *stacks);

void	prepare_b(t_stacks *stacks)
{
	find_median(stacks);
	// push first lower 50% of values and then upper 50%
	// first split = 0
	while (stacks->split < 2)
		push_split_into_b(stacks);
	ft_printf("All but 3 numbers have been moved to B!\n");
}

void	push_split_into_b(t_stacks *stacks)
{
	int	i;

	i = 0;
	calculate_limits(stacks);
	while (i <= stacks->a_len)
	{
		// If value at index 0 is between limits, push it to b. Else rotate
		if (stacks->a[0].value == stacks->max || stacks->a[0].value == stacks->min || stacks->a[0].value == stacks->median)
		{
			ft_printf("test 1, i: %d, a_len: %d, at zero index: %d\n", i, stacks->a_len, stacks->a[0].value);
			// ft_printf("ra\n");
			rotate_a(stacks);
			i++;
		}
		else if (stacks->a[0].value <= stacks->upper_limit && stacks->a[0].value >= stacks->lower_limit)
		{
			ft_printf("test 2, i: %d, a_len: %d, at zero index: %d\n", i, stacks->a_len, stacks->a[0].value);
			// print_stacks(stacks);
			// ft_printf("pa\n");
			push_to_b(stacks);
		}
		else
		{
			ft_printf("test 3, i: %d, a_len: %d, at zero index: %d\n", i, stacks->a_len, stacks->a[0].value);
			// ft_printf("ra\n");
			rotate_a(stacks);
			i++;
		}
	}
	stacks->split++;
}

// TODO: this could probably be optimised by finding the median rather than dividing by 2
void	calculate_limits(t_stacks *stacks)
{
	int	total_range;
	total_range = stacks->max - stacks->min;
	if (stacks->split == 0)
	{
		stacks->lower_limit = stacks->min;
		stacks->upper_limit = stacks->median;
	}
	else
	{
		stacks->lower_limit = stacks->median + 1;
		stacks->upper_limit = stacks->max;
	}
	ft_printf("lower limit: %d, upper limit: %d\n", stacks->lower_limit, stacks->upper_limit);
}

void	find_median(t_stacks *stacks)
{
	int	i;
	int	middle_value;

	i = 0;
	middle_value = stacks->a_len / 2 - 1;
	ft_printf("middle value: %d\n", middle_value);
	get_indexes_for_median(stacks);
	while (i < stacks->a_len)
	{
		if (stacks->a[i].index == middle_value)
		{
			stacks->median = stacks->a[i].value;
			ft_printf("median value: %d\n", stacks->median);
			break;
		}
		else
			i++;
	}
}