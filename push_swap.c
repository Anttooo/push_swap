#include "push_swap.h"

void	read_stack(int argc, char **argv, t_data *data);
void	freemem(t_data *data);

int	main(int argc, char **argv)
{
	t_data	data;
	initialise_data(&data, argc);
	read_stack(argc, argv, &data);
	if (is_sorted(&data) != 1)
		sort_stack(&data);
	freemem(&data);
	return (0);
}

void	read_stack(int argc, char **argv, t_data *data) // TODO: restructure this function so that it's not so messy
{
	int	i;

	i = 0;
	data->max = INT32_MIN;
	data->min = INT32_MAX;
	// TODO: ADD HANDLING OF VALUES OUTSIDE OF MAX_INT AND MIN_INT
	data->a = (t_list_item *)malloc(argc * sizeof(t_list_item));
	if (data->a == NULL)
		freemem(data);
	while (i < argc - 1)
	{
		data->a[i].value = ft_atoi(argv[i + 1]);
		if (data->a[i].value == 0 && *argv[i + 1] != (char)'0') // IF THE VALUE CAN'T BE READ, ATOI RETURNS 0 SO WE NEED TO DISTINGUISH BETWEEN 0 AND '0'
		{
			ft_printf("Error\n");
			freemem(data);
			exit(1);
		}
		if (data->a[i].value > data->max)
			data->max = data->a[i].value;
		if (data->a[i].value < data->min)
			data->min = data->a[i].value;
		i++;
	}
}

void	freemem(t_data *data)
{
	if (data->a != NULL)
	{
		free(data->a);
		data->a = NULL;
	}
	if (data->b != NULL)
	{
		free(data->b);
		data->b = NULL;
	}
}
