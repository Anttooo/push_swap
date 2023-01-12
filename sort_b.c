#include "push_swap.h"

void	a_index_for_b_values(t_stacks *stacks);
void	calculate_required_moves(t_stacks *stacks);
int	moves_to_rotate_a_to_correct_place(t_stacks *stacks, int i);
int	moves_to_rotate_b_to_correct_place(t_stacks *stacks, int i);
void	handle_one_with_least_moves(t_stacks *stacks);

void	sort_b(t_stacks *stacks)
{
	// int	i;

	// i = 0;
	// ft_printf("required_moves sum: %d\n", required_moves_sum);
	while (stacks->b_len > 0)
	{
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
		// ft_printf("number %d from B gets relative index %d in A, relative to zero index at index %d\n", stacks->b[i].value, index, stacks->zero_index);
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
	stacks->index_with_least_moves_required = 0;
	while (i < stacks->b_len)
	{
		// TODO: add a check here if it should be rotated to forward or backward
		move_to_top_of_b = ft_abs(moves_to_rotate_b_to_correct_place(stacks, i));
		rotate_a_to_correct_place = ft_abs(moves_to_rotate_a_to_correct_place(stacks, i));
		// TODO: add the dystem described below which checks if the instructions can be combined
		stacks->b[i].required_moves.total = move_to_top_of_b + push + rotate_a_to_correct_place;
		// ft_printf("To get %d to its place in A, %d moves would be required.\n",stacks->b[i].value, stacks->b[i].required_moves);
		if (stacks->b[i].required_moves.total < stacks->b[stacks->index_with_least_moves_required].required_moves.total)
			stacks->index_with_least_moves_required = i;
		
		i++;
	}
	// ft_printf("Index which requires least moves: %d\n", stacks->index_with_least_moves_required);
}

/* combining instructions
To figure out smallest amount of instructions for getting A and B to right position
- calculate number of rotations needed for B using regular and reverse rotation
- calculate number of rotations needed for B using regular and reverse rotation
- calculate sum of moves if picking smaller out of reverse and regular for both
- calculate sum of moves if selecting rotate for both but doing the overlapping amount of moves for both at the same time
	- The function would be: number of rotate both = smaller out of (rotations_A and rotations_B) + larger out of (rotations_A and rotations_B) - smaller out of those
- calculate sum of moves if selecting reverse rotate for bobth but doing the overlapping amount of moves for both at the same time
	- same function as above

*/


void	handle_one_with_least_moves(t_stacks *stacks)
{
	int	b_rotations_needed;
	int	a_rotations_needed;
	int	i;

	
	// the index which requires least moves is stored in stacks->index_with_least_moves_required
	b_rotations_needed = moves_to_rotate_b_to_correct_place(stacks, stacks->index_with_least_moves_required);
	// ft_printf("B will be rotate %d times\n", b_rotations_needed);
	// the number of moves for a needed can be calculated with the function
	a_rotations_needed = moves_to_rotate_a_to_correct_place(stacks, stacks->index_with_least_moves_required);
	// ft_printf("A will be rotate %d times\n", a_rotations_needed);
	// TODO: add rotation combination logic

	// Rotate A - TODO: add direction logic
	i = a_rotations_needed;
	while (i != 0)
	{
		if (i > 0)
		{
			rotate_a(stacks);
			i--;
		}
		else
		{
			reverse_rotate_a(stacks);
			i++;
		}
	}
	i = b_rotations_needed;
	// Rotate B - TODO: add direction logic
	while (i != 0)
	{
		if (i > 0)
		{
			rotate_b(stacks);
			i--;
		}
		else
		{
			reverse_rotate_b(stacks);
			i++;
		}
	}
	// Push to A
	push_to_a(stacks);
}

// To rotate a to correct place, the number at index 0 has to be the next one from the one being pushed, so larger.
// The correct relative index to have as [0] is the index of the number being pushed.
int	moves_to_rotate_a_to_correct_place(t_stacks *stacks, int i)
{
	int	moves;
	int	absolute_index_in_a;

	// the i here is absolute index in B and index is the correct relative index in A
	// TODO: add the check for shorter direction for both of these
	// if going to beginning of array is faster
	if (stacks->b[i].index + stacks->zero_index > stacks->a_len)
		absolute_index_in_a = stacks->b[i].index + stacks->zero_index - stacks->a_len;
	else
		absolute_index_in_a = stacks->b[i].index + stacks->zero_index;
	if (absolute_index_in_a < (stacks->a_len - absolute_index_in_a))
	{
		moves = absolute_index_in_a;
		// ft_printf("Use regular rotate with A, it will require %d moves\n", moves);
	}
	else
	{
		moves = -1 * (stacks->a_len - absolute_index_in_a);
		// ft_printf("The right absolute index in A is %d\n", absolute_index_in_a);
		// ft_printf("Use reverse rotate with A, it will require %d moves\n", moves);
	}
	return (moves);
}

int	moves_to_rotate_b_to_correct_place(t_stacks *stacks, int i)
{
	int	moves;

	// the i here is absolute index in B
	// if i is closer to beginning of array
	if (i < (stacks->b_len - i))
	{
		moves = i;
		// ft_printf("Use regular rotate with B, it will require %d moves\n", moves);
	}
	else // if i is closer to end of array
	{
		moves = -1 * (stacks->b_len - i);
		// ft_printf("Use reverse rotate with B, it will require %d moves\n", moves);
	}
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