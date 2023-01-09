#include "push_swap.h"

void	calculate_indexes(t_stacks *stacks);
void	calculate_distances(t_stacks *stacks);
int	calculate_distance_sum(t_stacks *stacks);
void	rotate_and_swap(t_stacks *stacks);

void	sort_b(t_stacks *stacks)
{
	int	distance_sum;
	int	i;

	i = 0;
	calculate_indexes(stacks);
	calculate_distances(stacks);
	distance_sum = calculate_distance_sum(stacks);
	// ft_printf("distance sum: %d\n", distance_sum);
	while (distance_sum > 0)
	{
		// TODO: optimise the order of things done within the rotate and swap so that it does not do stupid stuff
		rotate_and_swap(stacks);
		calculate_indexes(stacks);
		calculate_distances(stacks);
		distance_sum = calculate_distance_sum(stacks);
		// ft_printf("distance sum: %d\n", distance_sum);
	}
	while (stacks->b[i].index != 0)
		i++;
	while (i > 0)
	{
		// ft_printf("rb\n");
		rotate_b(stacks);
		i--;
	}
	while (stacks->b_len > 0)
	{
		// ft_printf("pa\n");
		push_to_a(stacks);
	}
}

void	calculate_indexes(t_stacks *stacks)
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
		while (j < stacks->b_len)
		{
			if (stacks->b[j].value > stacks->b[i].value)
				index++;
			j++;
		}
		stacks->b[i].index = index;
		// ft_printf("number %d of B gets index %d\n", stacks->b[i].value, index);
		i++;
	}
	// ft_printf("b_len %d\n", stacks->b_len);
}

void	calculate_distances(t_stacks *stacks)
{
	int	i;
	int	zero_index;

	i = 0;
	while (i < stacks->b_len)
	{
		if (stacks->b[i].index == 0)
			zero_index = i;
		i++;
	}
	// ft_printf("zero_index: %d\n", zero_index);
	i = 0;
	while (i < stacks->b_len)
	{
		if (i > zero_index)
			stacks->b[i].distance = (i - zero_index) - stacks->b[i].index;
		else if (i < zero_index)
			stacks->b[i].distance = (stacks->b_len - zero_index) + i - stacks->b[i].index;
		else
			stacks->b[i].distance = 0;
		// ft_printf("number %d of B gets distance %d, with index %d\n", stacks->b[i].value, stacks->b[i].distance, stacks->b[i].index);
		i++;
	}
}

int	calculate_distance_sum(t_stacks *stacks)
{
	int	i;
	int	sum;

	sum = 0;
	i = 0;
	while (i < stacks->b_len)
	{
		sum = sum + ft_abs(stacks->b[i].distance);
		i++;
	}
	return (sum);
}

void	rotate_and_swap(t_stacks *stacks)
{
	if (stacks->b[0].distance < 0 || stacks->b[1].distance > 0)
	{
		// ft_printf("sb\n");
		swap_b(stacks);
	}
	// ft_printf("rb\n");
	reverse_rotate_b(stacks);
}