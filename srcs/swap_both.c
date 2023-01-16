#include "../push_swap.h"

void	swap_both(t_data *data)
{
	int	print_switched;

	if (data->printing_enabled == 1)
	{
		print_switched = 1;
		data->printing_enabled = 0;
	}
	else
		print_switched = 0;
	swap_a(data);
	swap_b(data);
	if (print_switched == 1)
	{
		ft_printf("ss\n");
		data->printing_enabled = 1;
	}
	data->move_counter.swap_both++;
	data->move_counter.swap_a--;
	data->move_counter.swap_b--;
}