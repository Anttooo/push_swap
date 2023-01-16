#include "../push_swap.h"

// Shift up all elements of stack a by 1. The first element becomes the last one.

void	rotate_a(t_data *data)
{
	int	temp_holder;
	int	i;

	i = 0;
	if (data->a_len > 1)
	{
		temp_holder = data->a[0].value;
		while (i < data->a_len - 1)
		{
			data->a[i].value = data->a[i + 1].value;
			i++;
		}
		data->a[data->a_len - 1].value = temp_holder;
	}
	if (data->printing_enabled == 1)
		ft_printf("ra\n");
	data->move_counter.ra++;
}