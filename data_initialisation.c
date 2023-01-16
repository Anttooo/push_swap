#include "push_swap.h"

void	initialise_move_counter(t_data *data);

void	initialise_data(t_data *data, int argc)
{
	data->b = NULL;
	data->a = NULL;
	data->a_len = argc - 1;
	data->b_len = 0;
	data->org_len = argc - 1;
	data->lower_limit = INT32_MAX;
	data->upper_limit = INT32_MIN;
	data->nr_of_splits = 2;
	data->split = 0;
	data->median = 0;
	data->zero_index = 0;
	data->printing_enabled = 0;
	initialise_move_counter(data);
}

void	initialise_move_counter(t_data *data)
{
	data->move_counter.push_a = 0;
	data->move_counter.push_b = 0;
	data->move_counter.rra = 0;
	data->move_counter.rrb = 0;
	data->move_counter.rrr = 0;
	data->move_counter.ra = 0;
	data->move_counter.rb = 0;
	data->move_counter.rr = 0;
	data->move_counter.swap_a = 0;
	data->move_counter.swap_b = 0;
	data->move_counter.swap_both = 0;
}