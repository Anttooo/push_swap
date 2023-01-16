#include "../push_swap.h"


// Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
void	push_to_a(t_data *data)
{
	int i;

	// i is first used to move all numbers back by one in the receiving stack, to make space for the new top nr.
	// that's why it starts from the index of the last number in there
	i = data->a_len;
	// If be is empty, we don't do anything.
	if (data->b_len > 0)
	{
		// This part moves the numbers back by one in a non-destructive way
		while (i > 0)
		{
			data->a[i].value = data->a[i - 1].value;
			i--;
		}
		// Move the top number from b to a
		data->a[0].value = data->b[0].value;
		// increment the counters for the length of both data
		data->b_len--;
		data->a_len++;
	}
	// This part moves the numbers forward in b by one
	i = 0;
	if (data->b_len > 0)
	{
		while (i < data->b_len)
		{
			data->b[i].value = data->b[i + 1].value;
			i++;
		}
	}
	if (data->printing_enabled == 1)
		ft_printf("pa\n");
	data->move_counter.push_a++;
}