#include "push_swap.h"

void	use_both_directions(t_data *data, int i)
{
	if (data->b[i].required_moves.rra < data->b[i].required_moves.ra)
		data->b[i].required_moves.ra = 0;
	else
		data->b[i].required_moves.rra = 0;
	if (data->b[i].required_moves.rrb < data->b[i].required_moves.rb)
		data->b[i].required_moves.rb = 0;
	else
		data->b[i].required_moves.rrb = 0;
}

void	use_reverse_rotate(t_data *data, int i)
{	
	data->b[i].required_moves.rb = 0;
	data->b[i].required_moves.ra = 0;
	if (data->b[i].required_moves.rrb >= data->b[i].required_moves.rra)
	{
		data->b[i].required_moves.rrb = data->b[i].required_moves.rrb - data->b[i].required_moves.rra; // TODO: line too long
		data->b[i].required_moves.rrr = data->b[i].required_moves.rra;
		data->b[i].required_moves.rra = 0;
	}
	else
	{
		data->b[i].required_moves.rra = data->b[i].required_moves.rra - data->b[i].required_moves.rrb; // TODO: line too long
		data->b[i].required_moves.rrr = data->b[i].required_moves.rrb;
		data->b[i].required_moves.rrb = 0;
	}
}

void	use_rotate(t_data *data, int i)
{
	data->b[i].required_moves.rrb = 0;
	data->b[i].required_moves.rra = 0;
	if (data->b[i].required_moves.rb >= data->b[i].required_moves.ra)
	{
		data->b[i].required_moves.rb = data->b[i].required_moves.rb - data->b[i].required_moves.ra; // TODO: line too long
		data->b[i].required_moves.rr = data->b[i].required_moves.ra;
		data->b[i].required_moves.ra = 0;
	}
	else
	{
		data->b[i].required_moves.ra = data->b[i].required_moves.ra - data->b[i].required_moves.rb; // TODO: line too long
		data->b[i].required_moves.rr = data->b[i].required_moves.rb;
		data->b[i].required_moves.rb = 0;
	}
}