#include "push_swap.h"

void	print_data(t_data *data)
{
	int	i;

	i = 0;
	ft_printf("STACK A: ");
	while (i < data->a_len)
	{
		ft_printf("%d ", data->a[i].value);
		i++;
	}
	ft_printf("\n");
	i = 0;
	ft_printf("STACK B: ");
	while (i < data->b_len)
	{
		ft_printf("%d ", data->b[i].value);
		i++;
	}
	ft_printf("\n");
}

void	print_result(t_data *data)
{
	update_total_move_count(&data->move_counter);
	if (is_sorted(data) == 1 && data->a_len == data->org_len)
		ft_printf("\nSORTED in %d moves!\n", data->move_counter.total);
	else
		ft_printf("NOT SORTED in %d moves!\n", data->move_counter.total);
}