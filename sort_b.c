#include "push_swap.h"

void	calculate_indexes(t_stacks *stacks);
void	calculate_distances(t_stacks *stacks);
int		calculate_distance_sum(t_stacks *stacks);
void	do_next_move(t_stacks *stacks);

void	sort_b(t_stacks *stacks)
{
	int	i;

	i = 0;
	calculate_indexes(stacks);
	calculate_distances(stacks);
	// ft_printf("distance sum: %d\n", distance_sum);
	while (stacks->b_len > 0)
	{
		do_next_move(stacks);
		calculate_indexes(stacks);
		calculate_distances(stacks);
		// ft_printf("distance sum: %d\n", distance_sum);
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
		stacks->b[i].index = 0;
		i++;
	}
	i = 0;
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

	i = 0;
	stacks->zero_index = 0;
	while (i < stacks->b_len)
	{
		if (stacks->b[i].index == 0)
			stacks->zero_index = i;
		i++;
	}
	// ft_printf("zero_index: %d\n", zero_index);
	i = 0;
	while (i < stacks->b_len)
	{
		if (i > stacks->zero_index)
			stacks->b[i].distance = (i - stacks->zero_index) - stacks->b[i].index;
		else if (i < stacks->zero_index)
			stacks->b[i].distance = (stacks->b_len - stacks->zero_index) + i - stacks->b[i].index;
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

char	*check_shorter_rotation_direction(t_stacks *stacks)
{
	char	*direction;

	if (stacks->zero_index < stacks->b_len - stacks->zero_index)
		direction = "reverse";
	else
		direction = "regular";
	return (direction);
}

void	do_next_move(t_stacks *stacks)
{
	char	*rotation_direction;
	
	rotation_direction = check_shorter_rotation_direction(stacks);
	if (stacks->b[0].index == 0)
	{
		// ft_printf("pa\n");
		push_to_a(stacks);
	}
	if (ft_strncmp("regular", rotation_direction, 15))
	{
		// ft_printf("rb\n");
		rotate_b(stacks);
	}
	else
	{
		// ft_printf("rrb\n");
		reverse_rotate_b(stacks);
	}
}