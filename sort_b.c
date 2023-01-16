#include "push_swap.h"

void	a_index_for_b_values(t_stacks *stacks);
void	calculate_required_moves(t_stacks *stacks);
void	moves_to_rotate_a_to_correct_place(t_stacks *stacks, int i);
void	moves_to_rotate_b_to_correct_place(t_stacks *stacks, int i);
void	reset_move_counts(t_stacks *stacks, int i);
void	get_optimal_rotations(t_stacks *stacks, int i);
void	handle_one_with_least_moves(t_stacks *stacks);
int		get_moves_with_rotate(t_stacks *stacks, int i);
int		get_moves_with_reverse_rotate(t_stacks *stacks, int i);
int		get_moves_without_combination(t_stacks *stacks, int i);
void	use_rotate(t_stacks *stacks, int i);
void	use_reverse_rotate(t_stacks *stacks, int i);
void	rotate_without_combination(t_stacks *stacks, int i);

void	sort_b(t_stacks *stacks)
{
	// int	i;

	// i = 0;
	// ft_printf("required_moves sum: %d\n", required_moves_sum);
	while (stacks->b_len > 0)
	{
		// print_stacks(stacks);
		a_index_for_b_values(stacks);
		calculate_required_moves(stacks);
		handle_one_with_least_moves(stacks);
		// i++;
		// do_next_move(stacks);	
	}
	if (stacks->b_len == 0)
	{
		calculate_indexes_in_A(stacks);
		while (stacks->a[0].index != 0) // TODO: pick the direction with less steps
		{
			reverse_rotate_a(stacks);
			calculate_indexes_in_A(stacks);
		}
	}
}

void	a_index_for_b_values(t_stacks *stacks)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	stacks->zero_index = 0;
	// calculate the index of lowest value as the relative starting point
	calculate_indexes_in_A(stacks);
	while (i < stacks->a_len)
	{
		if (stacks->a[i].index == 0)
			stacks->zero_index = i;
		i++;
	}
	i = 0;
	// reset indexes of values in b
	while (i < stacks->b_len)
	{
		stacks->b[i].index = 0;
		i++;
	}
	i = 0;
	// calculate the relative indexes in a in relation to the zero_index value
	while (i < stacks->b_len)
	{
		j = 0;
		index = 0;
		while (j < stacks->a_len)
		{
			if (j + stacks->zero_index < stacks->a_len)
			{
				if (stacks->b[i].value > stacks->a[j + stacks->zero_index].value)
				{
					// ft_printf("1 Value in B: %d is larger than value with index %d at A: %d\n", stacks->b[i].value, j + stacks->zero_index, stacks->a[j + stacks->zero_index].value);
					index++;
				}
			}
			else
			{
				if (stacks->b[i].value > stacks->a[(j + stacks->zero_index) - stacks->a_len].value)
				{
					// ft_printf("2 Value in B: %d is larger than value with index %d at A: %d\n", stacks->b[i].value, (j + stacks->zero_index) - stacks->a_len, stacks->a[(j + stacks->zero_index) - stacks->a_len].value);
					index++;
				}
				else;
					// ft_printf("Number %d is smaller than number %d, so we stop here.\n", stacks->b[i].value, stacks->a[(j + stacks->zero_index) - stacks->a_len].value);
			}
			j++;
		}
		stacks->b[i].index = index;
		// ft_printf("number %d from B gets relative index %d in A, relative to zero index at index %d\n", stacks->b[i].value, index, stacks->zero_index);
		i++;
	}
}

void	calculate_required_moves(t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->index_with_least_moves_required = 0;
	while (i < stacks->b_len)
	{
		reset_move_counts(stacks, i);
		moves_to_rotate_b_to_correct_place(stacks, i);
		moves_to_rotate_a_to_correct_place(stacks, i);
		get_optimal_rotations(stacks, i);
		stacks->b[i].required_moves.push_a = 1;
		update_total_move_count_for_index(stacks, i);
		// TODO: add the system described below which checks if the instructions can be combined
		// ft_printf("To get %d to its place in A, %d moves would be required. ",stacks->b[i].value, stacks->b[i].required_moves.total);
		// ft_printf("(rotate a %d, reverse rotate a: %d, rotate b: %d, reverse rotate b: %d ", stacks->b[i].required_moves.rotate_a, stacks->b[i].required_moves.reverse_rotate_a, stacks->b[i].required_moves.rotate_b, stacks->b[i].required_moves.reverse_rotate_b);
		// ft_printf("rotate both %d, reverse rotate both: %d)\n", stacks->b[i].required_moves.rotate_both, stacks->b[i].required_moves.reverse_rotate_both);
		if (stacks->b[i].required_moves.total < stacks->b[stacks->index_with_least_moves_required].required_moves.total)
			stacks->index_with_least_moves_required = i;
		i++;
	}
	// ft_printf("Index which requires least moves: %d\n", stacks->index_with_least_moves_required);
}

void	handle_one_with_least_moves(t_stacks *stacks)
{
	// the index which requires least moves is stored in stacks->index_with_least_moves_required
	// ft_printf("selected index: %d\n", stacks->index_with_least_moves_required);
	// print_stacks(stacks);

	// Rotate A - TODO: add direction logic
	while (stacks->b[stacks->index_with_least_moves_required].required_moves.rotate_a > 0)
	{
		rotate_a(stacks);
		stacks->b[stacks->index_with_least_moves_required].required_moves.rotate_a--;
	}
	while (stacks->b[stacks->index_with_least_moves_required].required_moves.reverse_rotate_a > 0)
	{
		reverse_rotate_a(stacks);
		stacks->b[stacks->index_with_least_moves_required].required_moves.reverse_rotate_a--;
	}
	// Rotate B - TODO: add direction logic
	while (stacks->b[stacks->index_with_least_moves_required].required_moves.rotate_b > 0)
	{
		rotate_b(stacks);
		stacks->b[stacks->index_with_least_moves_required].required_moves.rotate_b--;
	}
	while (stacks->b[stacks->index_with_least_moves_required].required_moves.reverse_rotate_b > 0)
	{
		reverse_rotate_b(stacks);
		stacks->b[stacks->index_with_least_moves_required].required_moves.reverse_rotate_b--;
	}
	while (stacks->b[stacks->index_with_least_moves_required].required_moves.reverse_rotate_both > 0)
	{
		reverse_rotate_both(stacks);
		stacks->b[stacks->index_with_least_moves_required].required_moves.reverse_rotate_both--;
	}
	while (stacks->b[stacks->index_with_least_moves_required].required_moves.rotate_both > 0)
	{
		rotate_both(stacks);
		stacks->b[stacks->index_with_least_moves_required].required_moves.rotate_both--;
	}
	// Push to A
	push_to_a(stacks);
}

/* combining instructions
To figure out smallest amount of instructions for getting A and B to right position
- calculate sum of moves if picking smaller out of reverse and regular for both
- calculate sum of moves if selecting rotate for both but doing the overlapping amount of moves for both at the same time
	- The function would be: number of rotate both = smaller out of (rotations_A and rotations_B) + larger out of (rotations_A and rotations_B) - smaller out of those
- calculate sum of moves if selecting reverse rotate for both but doing the overlapping amount of moves for both at the same time
	- same function as above
*/

void	get_optimal_rotations(t_stacks *stacks, int i)
{
	int	without_combination;
	int	reverse_rotate;
	int	rotate;

	without_combination = get_moves_without_combination(stacks, i);
	reverse_rotate = get_moves_with_reverse_rotate(stacks, i);
	rotate = get_moves_with_rotate(stacks, i);
	if (without_combination < reverse_rotate && without_combination < rotate)
		rotate_without_combination(stacks, i);
	else if (reverse_rotate < without_combination && reverse_rotate < rotate)
		use_reverse_rotate(stacks, i);
	else
		use_rotate(stacks, i);

}

int	get_moves_without_combination(t_stacks *stacks, int i)
{
	int	moves;

	moves = 0;
	if (stacks->b[i].required_moves.reverse_rotate_a < stacks->b[i].required_moves.rotate_a)
		moves = stacks->b[i].required_moves.reverse_rotate_a;
	else
		moves = stacks->b[i].required_moves.rotate_a;
	if (stacks->b[i].required_moves.reverse_rotate_b < stacks->b[i].required_moves.rotate_b)
		moves = moves + stacks->b[i].required_moves.reverse_rotate_b;
	else
		moves = moves + stacks->b[i].required_moves.rotate_b;
	return (moves);
}

int	get_moves_with_reverse_rotate(t_stacks *stacks, int i)
{
	int	moves;
	
	moves = 0;
	if (stacks->b[i].required_moves.reverse_rotate_b >= stacks->b[i].required_moves.reverse_rotate_a)
	{
		moves = stacks->b[i].required_moves.reverse_rotate_b;
	}
	else 
		moves = stacks->b[i].required_moves.reverse_rotate_a;
	return (moves);
}

int	get_moves_with_rotate(t_stacks *stacks, int i)
{
	int	moves;
	
	moves = 0;
	if (stacks->b[i].required_moves.rotate_b >= stacks->b[i].required_moves.rotate_a)
	{
		moves = stacks->b[i].required_moves.rotate_b;
	}
	else 
		moves = stacks->b[i].required_moves.rotate_a;
	return (moves);
}

void	rotate_without_combination(t_stacks *stacks, int i)
{
	if (stacks->b[i].required_moves.reverse_rotate_a < stacks->b[i].required_moves.rotate_a)
		stacks->b[i].required_moves.rotate_a = 0;
	else
		stacks->b[i].required_moves.reverse_rotate_a = 0;
	if (stacks->b[i].required_moves.reverse_rotate_b < stacks->b[i].required_moves.rotate_b)
		stacks->b[i].required_moves.rotate_b = 0;
	else
		stacks->b[i].required_moves.reverse_rotate_b = 0;
}

void	use_reverse_rotate(t_stacks *stacks, int i)
{	
	stacks->b[i].required_moves.rotate_b = 0;
	stacks->b[i].required_moves.rotate_a = 0;
	if (stacks->b[i].required_moves.reverse_rotate_b >= stacks->b[i].required_moves.reverse_rotate_a)
	{
		stacks->b[i].required_moves.reverse_rotate_b = stacks->b[i].required_moves.reverse_rotate_b - stacks->b[i].required_moves.reverse_rotate_a;
		stacks->b[i].required_moves.reverse_rotate_both = stacks->b[i].required_moves.reverse_rotate_a;
		stacks->b[i].required_moves.reverse_rotate_a = 0;
	}
	else
	{
		stacks->b[i].required_moves.reverse_rotate_a = stacks->b[i].required_moves.reverse_rotate_a - stacks->b[i].required_moves.reverse_rotate_b;
		stacks->b[i].required_moves.reverse_rotate_both = stacks->b[i].required_moves.reverse_rotate_b;
		stacks->b[i].required_moves.reverse_rotate_b = 0;
	}
}

void	use_rotate(t_stacks *stacks, int i)
{
	stacks->b[i].required_moves.reverse_rotate_b = 0;
	stacks->b[i].required_moves.reverse_rotate_a = 0;
	if (stacks->b[i].required_moves.rotate_b >= stacks->b[i].required_moves.rotate_a)
	{
		stacks->b[i].required_moves.rotate_b = stacks->b[i].required_moves.rotate_b - stacks->b[i].required_moves.rotate_a;
		stacks->b[i].required_moves.rotate_both = stacks->b[i].required_moves.rotate_a;
		stacks->b[i].required_moves.rotate_a = 0;
	}
	else
	{
		stacks->b[i].required_moves.rotate_a = stacks->b[i].required_moves.rotate_a - stacks->b[i].required_moves.rotate_b;
		stacks->b[i].required_moves.rotate_both = stacks->b[i].required_moves.rotate_b;
		stacks->b[i].required_moves.rotate_b = 0;
	}
}

// To rotate a to correct place, the number at index 0 has to be the next one from the one being pushed, so larger.
// The correct relative index to have as [0] is the index of the number being pushed.
void	moves_to_rotate_a_to_correct_place(t_stacks *stacks, int i)
{
	int	absolute_index_in_a;

	if (stacks->b[i].index + stacks->zero_index > stacks->a_len)
		absolute_index_in_a = stacks->b[i].index + stacks->zero_index - stacks->a_len;
	else
		absolute_index_in_a = stacks->b[i].index + stacks->zero_index;
	stacks->b[i].required_moves.rotate_a = absolute_index_in_a;
	stacks->b[i].required_moves.reverse_rotate_a = (stacks->a_len - absolute_index_in_a);
}

// the i here is absolute index in B
void	moves_to_rotate_b_to_correct_place(t_stacks *stacks, int i)
{
	stacks->b[i].required_moves.rotate_b = i;
	stacks->b[i].required_moves.reverse_rotate_b = stacks->b_len - i;
}

void	reset_move_counts(t_stacks *stacks, int i)
{
	stacks->b[i].required_moves.push_a = 0;
	stacks->b[i].required_moves.push_b = 0;
	stacks->b[i].required_moves.reverse_rotate_a = 0;
	stacks->b[i].required_moves.reverse_rotate_b = 0;
	stacks->b[i].required_moves.reverse_rotate_both = 0;
	stacks->b[i].required_moves.rotate_a = 0;
	stacks->b[i].required_moves.rotate_b = 0;
	stacks->b[i].required_moves.rotate_both = 0;
	stacks->b[i].required_moves.swap_a = 0;
	stacks->b[i].required_moves.swap_b = 0;
	stacks->b[i].required_moves.swap_both = 0;
	stacks->b[i].required_moves.total = 0;
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
		push_to_a(stacks);
	}
	if (ft_strncmp("regular", rotation_direction, 15))
	{
		rotate_b(stacks);
	}
	else
	{
		reverse_rotate_b(stacks);
	}
}