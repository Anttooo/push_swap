#include "push_swap.h"

void	organise_b(t_data *data);
void	calculate_limits(t_data *data);
void	push_split_into_b(t_data *data);
void	find_median(t_data *data);
int	count_values_to_move(t_data *data);

void	prepare_b(t_data *data)
{
	find_median(data);
	// push first lower 50% of values and then upper 50%
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
	// ft_printf("Values to push for this split: %d\n", values_to_push);
	pushed = 0;
	while (i <= data->a_len && pushed < values_to_push)
	{
		// If value at index 0 is between limits, push it to b. Else rotate
		if (data->a[0].value == data->max || data->a[0].value == data->min || data->a[0].value == data->median)
		{
			// ft_printf("test 1, i: %d, a_len: %d, at zero index: %d\n", i, data->a_len, data->a[0].value);
			rotate_a(data);
			i++;
		}
		else if (data->a[0].value <= data->upper_limit && data->a[0].value >= data->lower_limit)
		{
			// ft_printf("test 2, i: %d, a_len: %d, at zero index: %d\n", i, data->a_len, data->a[0].value);
			// print_data(data);
			pushed++;
			push_to_b(data);
		}
		else
		{
			// ft_printf("test 3, i: %d, a_len: %d, at zero index: %d\n", i, data->a_len, data->a[0].value);
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
		if (data->a[i].value == data->max || data->a[i].value == data->min || data->a[i].value == data->median);
		else if (data->a[i].value <= data->upper_limit && data->a[i].value >= data->lower_limit)
		{
			// ft_printf("value %d fits between the lower limit and upper limit\n", data->a[i].value);
			counter++;
		}
		i++;
	}
	return (counter);
}

// TODO: this could probably be optimised by finding the median rather than dividing by 2
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
	// ft_printf("lower limit: %d, upper limit: %d\n", data->lower_limit, data->upper_limit);
}

void	find_median(t_data *data)
{
	int	i;
	int	middle_value;

	i = 0;
	middle_value = data->a_len / 2 - 1;
	// ft_printf("middle value: %d\n", middle_value);
	calculate_indexes_in_A(data);
	while (i < data->a_len)
	{
		if (data->a[i].index == middle_value)
		{
			data->median = data->a[i].value;
			// ft_printf("median value: %d\n", data->median);
			break;
		}
		else
			i++;
	}
}