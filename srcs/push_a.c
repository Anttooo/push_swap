#include "../push_swap.h"


// Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
void	push_to_a(t_stacks *stacks)
{
	int i;

	// i is first used to move all numbers back by one in the receiving stack, to make space for the new top nr.
	// that's why it starts from the index of the last number in there
	i = stacks->a_len;
	// If be is empty, we don't do anything.
	if (stacks->b_len > 0)
	{
		// This part moves the numbers back by one in a non-destructive way
		while (i > 0)
		{
			stacks->a[i].value = stacks->a[i - 1].value;
			i--;
		}
		// Move the top number from b to a
		stacks->a[0].value = stacks->b[0].value;
		// increment the counters for the length of both stacks
		stacks->b_len--;
		stacks->a_len++;
	}
	// This part moves the numbers forward in b by one
	i = 0;
	if (stacks->b_len > 0)
	{
		while (i < stacks->b_len)
		{
			stacks->b[i].value = stacks->b[i + 1].value;
			i++;
		}
	}
	if (stacks->printing_enabled == 1)
		ft_printf("pa\n");
	stacks->move_counter.push_a++;
}