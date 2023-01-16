#include "../push_swap.h"

// Shift up all elements of stack a by 1. The first element becomes the last one.

void	rotate_b(t_data *data)
{
	int	temp_holder;
	int	i;

	i = 0;
	if (data->b_len > 1)
	{
		temp_holder = data->b[0].value;
		while (i < data->b_len - 1)
		{
			data->b[i].value = data->b[i + 1].value;
			i++;
		}
		data->b[data->b_len - 1].value = temp_holder;
	}
	if (data->printing_enabled == 1)
		ft_printf("rb\n");
	data->move_counter.rb++;
}