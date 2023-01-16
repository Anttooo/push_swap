#include "push_swap.h"

int		is_sorted(t_data *data);
void	initialise_stack_b(t_data *data);

void	sort_stack(t_data *data)
{
	initialise_stack_b(data);
	prepare_b(data);
	sort_a(data);
	while (is_sorted(data) != 1)
		complete_next_move(data);
	update_total_move_count(&data->move_counter);
	print_result(data); // TODO: remove this before submitting
}

void	initialise_stack_b(t_data *data)
{
	data->b = (t_list_item *)malloc(data->org_len * sizeof(t_list_item));
	if (data->b == NULL)
	{
		freemem(data);
		exit(1);
	}
}

int	is_sorted(t_data *data)
{
	int	i;

	i = 0;
	if (data->a_len < data->org_len)
		return (0);
	while (i < data->a_len - 1)
	{
		if (data->a[i].value < data->a[i + 1].value)
			i++;
		else
			return(0);
	}
	return (1);
}

void	update_total_move_count(t_moves *move_counter)
{
	move_counter->total = 0;
	move_counter->total = move_counter->total + move_counter->push_a;
	move_counter->total = move_counter->total + move_counter->push_b;
	move_counter->total = move_counter->total + move_counter->rra;
	move_counter->total = move_counter->total + move_counter->rrb;
	move_counter->total = move_counter->total + move_counter->rrr;
	move_counter->total = move_counter->total + move_counter->ra;
	move_counter->total = move_counter->total + move_counter->rb;
	move_counter->total = move_counter->total + move_counter->rr;
	move_counter->total = move_counter->total + move_counter->swap_a;
	move_counter->total = move_counter->total + move_counter->swap_b;
	move_counter->total = move_counter->total + move_counter->swap_both;
}

void	update_total_move_count_for_index(t_data *data, int i)
{
	data->b[i].required_moves.total = 0;
	data->b[i].required_moves.total = data->b[i].required_moves.total + data->b[i].required_moves.push_a;
	data->b[i].required_moves.total = data->b[i].required_moves.total + data->b[i].required_moves.push_b;
	data->b[i].required_moves.total = data->b[i].required_moves.total + data->b[i].required_moves.rra;
	data->b[i].required_moves.total = data->b[i].required_moves.total + data->b[i].required_moves.rrb;
	data->b[i].required_moves.total = data->b[i].required_moves.total + data->b[i].required_moves.rrr;
	data->b[i].required_moves.total = data->b[i].required_moves.total + data->b[i].required_moves.ra;
	data->b[i].required_moves.total = data->b[i].required_moves.total + data->b[i].required_moves.rb;
	data->b[i].required_moves.total = data->b[i].required_moves.total + data->b[i].required_moves.rr;
	data->b[i].required_moves.total = data->b[i].required_moves.total + data->b[i].required_moves.swap_a;
	data->b[i].required_moves.total = data->b[i].required_moves.total + data->b[i].required_moves.swap_b;
	data->b[i].required_moves.total = data->b[i].required_moves.total + data->b[i].required_moves.swap_both;
}

