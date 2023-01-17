/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:21:00 by oanttoor          #+#    #+#             */
/*   Updated: 2023/01/17 10:21:02 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	check_input_validity(char **argv, t_data *data, int *i)
{
	int	invalid_input;
	int	e;

	e = 0;
	invalid_input = 0;
	if (data->a[*i].value == 0 && *argv[*i + 1] != (char) '0')
		invalid_input = 1;
	if (data->a[*i].value == -1 && ft_strncmp(argv[*i + 1], "-1", 2) != 0)
		invalid_input = 1;
	while (e < *i)
	{
		if (data->a[*i].value == data->a[e].value)
		{
			invalid_input = 1;
			e++;
		}
		else
			e++;
	}
	if (invalid_input == 1)
	{
		ft_printf("Error\n");
		freemem(data);
		exit(1);
	}
}

void	read_stack(int argc, char **argv, t_data *data)
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
		check_input_validity(argv, data, &i);
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
