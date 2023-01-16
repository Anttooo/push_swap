#include "../push_swap.h"

// Shift down all elements of stack a by 1. The last element becomes the first one.

void	reverse_rotate_a(t_data *data)
{
	int	temp_holder;
	int	i;

	i = data->a_len - 1;
	if (data->a_len > 1)
	{
		temp_holder = data->a[i].value;
		while (i > 0)
		{
			data->a[i].value = data->a[i - 1].value;
			i--;
		}
		data->a[0].value = temp_holder;
	}
	if (data->printing_enabled == 1)
		ft_printf("rra\n");
	data->move_counter.rra++;
}