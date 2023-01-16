#include "../push_swap.h"

// Shift down all elements of stack a by 1. The last element becomes the first one.

void	reverse_rotate_b(t_data *data)
{
	int	temp_holder;
	int	i;

	i = data->b_len - 1;
	if (data->b_len > 1)
	{
		temp_holder = data->b[i].value;
		while (i > 0)
		{
			data->b[i].value = data->b[i - 1].value;
			i--;
		}
		data->b[0].value = temp_holder;
	}
	if (data->printing_enabled == 1)
		ft_printf("rrb\n");
	data->move_counter.rrb++;
}