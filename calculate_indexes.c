#include "push_swap.h"

void	calculate_indexes_in_A(t_data *data)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (i < data->a_len)
	{
		data->a[i].index = 0;
		i++;
	}
	i = 0;
	while (i < data->a_len)
	{
		j = 0;
		index = 0;
		while (j < data->a_len)
		{
			if (data->a[j].value < data->a[i].value)
				index++;
			j++;
		}
		data->a[i].index = index;
		// ft_printf("number %d of A gets index %d\n", data->a[i].value, index);
		i++;
	}
}

void	compute_indexes_in_a_for_b_values(t_data *data)
{
	update_index_of_smallest_value_in_a(data);
	reset_stack_b_indexes(data);
	compute_index_for_each(data);
}

void	update_index_of_smallest_value_in_a(t_data *data)
{
	int	i;

	i = 0;	
	data->zero_index = 0;
	calculate_indexes_in_A(data);
	while (i < data->a_len)
	{
		if (data->a[i].index == 0)
			data->zero_index = i;
		i++;
	}
}

void	reset_stack_b_indexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->b_len)
	{
		data->b[i].index = 0;
		i++;
	}
}

void	compute_index_for_each(t_data *data)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (i < data->b_len)
	{
		j = 0;
		index = 0;
		while (j < data->a_len)
		{
			if (j + data->zero_index < data->a_len)
			{
				if (data->b[i].value > data->a[j + data->zero_index].value) // TODO: line too long
					index++;
			}
			else
			{
				if (data->b[i].value > data->a[(j + data->zero_index) - data->a_len].value) // TODO: line too long
					index++;				
			}
			j++;
		}
		data->b[i].index = index;
		i++;
	}
}