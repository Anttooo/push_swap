#include "../push_swap.h"


// Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
void	push_to_b(t_data *data)
{
	int i;

	// i is first used to move all numbers back by one in the receiving stack, to make space for the new top nr.
	// that's why it starts from the index of the last number in there
	i = data->b_len;
	// In case receiving stack is empty, return index to 0
	if (i < 0)
		i = 0;
	// If a is empty, we don't do anything.
	if (data->a_len > 0)
	{
		// This part moves the numbers back by one in a non-destructive way
		while (i > 0)
		{
			data->b[i].value = data->b[i - 1].value;
			i--;
		}
		// Move the top number from b to a
		data->b[0].value = data->a[0].value;
		// increment the counters for the length of both data
		data->b_len++;
		data->a_len--;
	}
	// This part moves the numbers forward in b by one
	i = 0;
	if (data->a_len > 0)
	{
		while (i < data->a_len)
		{
			data->a[i].value = data->a[i + 1].value;
			i++;
		}
	}
	if (data->printing_enabled == 1)
		ft_printf("pb\n");
	data->move_counter.push_b++;
}