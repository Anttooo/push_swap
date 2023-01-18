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

// The driver function which controls the overal flow of the program.
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 1)
	{
		initialise_data(&data, argc);
		read_stack(argc, argv, &data);
		if (is_sorted(&data) != 1)
			sort_stack(&data);
		freemem(&data);
	}
	return (0);
}

// Reads the input and checks its validity, assigns max and min values
void	read_stack(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	data->max = INT32_MIN;
	data->min = INT32_MAX;
	data->a = (t_list_item *)malloc(argc * sizeof(t_list_item));
	if (data->a == NULL)
		freemem(data);
	ft_printf("argc has value: %d\n", argc);
	ft_printf("argv[1] has value: %s\n", argv[1]);
	ft_printf("argv[2] has value: %s\n", argv[2]);
	while (i < argc - 1)
	{
		data->a[i].value = ft_atoi(argv[i + 1]);
		ft_printf("test: %d\n", data->a[i].value);
		check_input_validity(argv, data, &i);
		if (data->a[i].value > data->max)
			data->max = data->a[i].value;
		if (data->a[i].value < data->min)
			data->min = data->a[i].value;
		i++;
	}
}

// Frees the allocated memory
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
