#include "push_swap.h"

void	a_index_for_b_values(t_stacks *stacks);
void	calculate_required_moves(t_stacks *stacks);
int	moves_to_rotate_a_to_correct_place(t_stacks *stacks, int i);
void	do_next_move(t_stacks *stacks);

void	sort_b(t_stacks *stacks)
{
	int	i;

	i = 0;
	// ft_printf("required_moves sum: %d\n", required_moves_sum);
	while (stacks->b_len > 0 && i < 1)
	{
		a_index_for_b_values(stacks);
		calculate_required_moves(stacks);
		i++;
		// do_next_move(stacks);	
	}
}

/* to calculate correct index in a relative way to smallest value
- A has to be already sorted so that numbers forward from smallest value are always larger than it
- get the index of smallest value
- calculate the correct "required_moves" from smallest value
- calculate the index of that required_moves (it might be smaller or larger than the index of smallest value since it might go around if the smallest value is not the first one)
	- if i > zero_index, then something
	- if i < zero_index, then something
*/

// TODO: make this function work even if the smallest value is not at [0] location
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
		ft_printf("number %d from B gets relative index %d in A, relative to zero index at index %d\n", stacks->b[i].value, index, stacks->zero_index);
		i++;
	}
	// calculate the absolute indexes in A based on the relative index and the position of zero_index
}

void	calculate_required_moves(t_stacks *stacks)
{
	int	i;
	int	move_to_top_of_b;
	int	rotate_a_to_correct_place;
	int	push;

	i = 0;
	push = 1;
	while (i < stacks->b_len)
	{
		// TODO: add a check here if it should be rotated to forward or backward
		move_to_top_of_b = i;
		rotate_a_to_correct_place = moves_to_rotate_a_to_correct_place(stacks, i);
		// TODO: add the dystem described below which checks if the instructions can be combined
		stacks->b[i].required_moves = move_to_top_of_b + push + rotate_a_to_correct_place;
		ft_printf("For number %d in B, %d moves would be required.\n",stacks->b[i].value, stacks->b[i].required_moves);
		i++;
	}
	// Zero index in A has been calculated previously and indexes are in relation to that
	
	// the number of moves to get the value to the top of b is equal to the index of the value
	// moving to top of B = i or b_len - i (??),;
	// pushing to a = + 1
	// rotating A to correct index = correct index or a_len - correct index, whichever is smaller

	// I want to move both to the same direction to half the number of steps, so I should store the values for both directions,
	// Then calculate if the overlapping part / 2 + non-overlapping part is less steps in one of the directions than the two going to
	// different directions

	// ft_printf("zero_index: %d\n", zero_index);
	i = 0;
	while (i < stacks->b_len)
	{
		if (i > stacks->zero_index)
			stacks->b[i].required_moves = (i - stacks->zero_index) - stacks->b[i].index;
		else if (i < stacks->zero_index)
			stacks->b[i].required_moves = (stacks->b_len - stacks->zero_index) + i - stacks->b[i].index;
		else
			stacks->b[i].required_moves = 0;
		// ft_printf("number %d of B gets required_moves %d, with index %d\n", stacks->b[i].value, stacks->b[i].required_moves, stacks->b[i].index);
		i++;
	}
}

// To rotate a to correct place, the number at index 0 has to be the next one from the one being pushed, so larger.
// The correct relative index to have as [0] is the index of the number being pushed.
int	moves_to_rotate_a_to_correct_place(t_stacks *stacks, int i)
{
	int	moves;

	// TODO: add the check for shorter direction for both of these
	if (stacks->b[i].index + stacks->zero_index > stacks->a_len)
		moves = stacks->b[i].index + stacks->zero_index - stacks->a_len;
	else
		moves = stacks->b[i].index + stacks->zero_index;
	return (moves);
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