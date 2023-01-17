#include "push_swap.h"

void	organise_b(t_data *data);
void	calculate_limits(t_data *data);
void	push_split_into_b(t_data *data);
void	find_median(t_data *data);
int	count_values_to_move(t_data *data);

void	prepare_b(t_data *data)
{
	find_median(data);
	while (data->split < 2 && data->a_len > 3)
		push_split_into_b(data);
}

void	push_split_into_b(t_data *data)
{
	int	i;
	int	values_to_push;
	int	pushed;

	i = 0;
	calculate_limits(data);
	values_to_push = count_values_to_move(data);
	pushed = 0;
	while (i <= data->a_len && pushed < values_to_push)
	{
		if (data->a[0].value == data->max || data->a[0].value == data->min || data->a[0].value == data->median) // TODO: line too long
		{
			rotate_a(data);
			i++;
		}
		else if (data->a[0].value <= data->upper_limit && data->a[0].value >= data->lower_limit) // TODO: line too long
		{
			pushed++;
			push_to_b(data);
		}
		else
		{
			rotate_a(data);
			i++;
		}
	}
	data->split++;
}

int	count_values_to_move(t_data *data)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i <= data->a_len)
	{
		if (data->a[i].value == data->max || data->a[i].value == data->min || data->a[i].value == data->median); // TODO: line too long
		else if (data->a[i].value <= data->upper_limit && data->a[i].value >= data->lower_limit) // TODO: line too long
			counter++;
		i++;
	}
	return (counter);
}

void	calculate_limits(t_data *data)
{
	if (data->split == 0)
	{
		data->lower_limit = data->min;
		data->upper_limit = data->median;
	}
	else
	{
		data->lower_limit = data->median + 1;
		data->upper_limit = data->max;
	}
}

void	find_median(t_data *data)
{
	int	i;
	int	middle_value;

	i = 0;
	middle_value = data->a_len / 2 - 1;
	calculate_indexes_in_A(data);
	while (i < data->a_len)
	{
		if (data->a[i].index == middle_value)
		{
			data->median = data->a[i].value;
			break; // TODO: check if it's ok to use break
		}
		else
			i++;
	}
}