#include "../push_swap.h"


// Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
void	push_to_b(t_stacks *stacks)
{
	int i;

	// i is first used to move all numbers back by one in the receiving stack, to make space for the new top nr.
	// that's why it starts from the index of the last number in there
	i = stacks->b_len;
	// In case receiving stack is empty, return index to 0
	if (i < 0)
		i = 0;
	// If a is empty, we don't do anything.
	if (stacks->a_len > 0)
	{
		// This part moves the numbers back by one in a non-destructive way
		while (i > 0)
		{
			stacks->b[i].value = stacks->b[i - 1].value;
			i--;
		}
		// Move the top number from b to a
		stacks->b[0].value = stacks->a[0].value;
		// increment the counters for the length of both stacks
		stacks->b_len++;
		stacks->a_len--;
	}
	// This part moves the numbers forward in b by one
	i = 0;
	if (stacks->a_len > 0)
	{
		while (i < stacks->a_len)
		{
			stacks->a[i].value = stacks->a[i + 1].value;
			i++;
		}
	}
	if (stacks->printing_enabled == 1)
		ft_printf("pb\n");
	stacks->move_count++;
	stacks->moves.push_b++;
}