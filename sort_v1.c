#include "push_swap.h"

void	organise_b(t_stacks *stacks);
int	values_to_move(int	pivot, t_stacks *stacks);
void	calculate_limits(t_stacks *stacks);
int	calculate_values_to_push(t_stacks *stacks);
void	sort_b(t_stacks *stacks);

void	sort_v1(t_stacks *stacks)
{
	int	i;
	// int	pushed;
	// int	values_to_push;

	i = 0;
	// pushed = 0;
	stacks->decile++;
	calculate_limits(stacks);
	// values_to_push = calculate_values_to_push(stacks);
	// ft_printf("values to push: %d\n", values_to_push);
	// push all values below or equal to pivot into B
	// TODO: count the number of values that fit into the limits and stop once those have been pushed -> saves steps // adding this gives only a 2% decrease in number of moves and breaks some things
	while (i < stacks->a_len) // && pushed != values_to_push
	{
		// ft_printf("i: %d\n", i);
		// ft_printf("stacks->[a]: %d\n", stacks->a[i]);
		// ft_printf("stacks->a_len: %d\n", stacks->a_len);
		if (stacks->a[0].value <= stacks->upper_limit && stacks->a[0].value >= stacks->lower_limit)
		{
			// ft_printf("pa\n");
			push_to_b(stacks);
			// pushed++;
			// if (pushed == values_to_push)
			// 	ft_printf("last push at index %d\n", i);
		}
		else
		{
			// ft_printf("ra\n");
			rotate_a(stacks);
			i++;
		}
	}
	// ft_printf("pushed: %d after %d moves\n", pushed, i);
	sort_b(stacks);
}

void	calculate_limits(t_stacks *stacks)
{
	int	total_range;

	total_range = stacks->max - stacks->min;
	if (stacks->decile == 1)
		stacks->upper_limit = stacks->max;
	else
		stacks->upper_limit = stacks->lower_limit - 1;
	if (stacks->decile == stacks->splits)
		stacks->lower_limit = stacks->min;
	else
		stacks->lower_limit = stacks->max - total_range / stacks->splits * stacks->decile - 1;
	// ft_printf("lower limit: %d, upper limit: %d\n", stacks->lower_limit, stacks->upper_limit);
}

int	values_to_move(int	pivot, t_stacks *stacks)
{
	int	i;
	int	counter;
	
	i = 0;
	counter = 0;
	while (i < stacks->a_len)
	{
		if (stacks->a[i].value <= pivot)
			counter++;
		i++;
	}
	return (counter);
}

int	calculate_values_to_push(t_stacks *stacks)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < stacks->a_len)
	{
		if (stacks->a[i].value <= stacks->upper_limit && stacks->a[i].value >= stacks->lower_limit)
			counter++;
		i++;
	}
	return (counter);
}