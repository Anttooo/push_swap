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
int		count_numbers(char **argv, int argc);
void	store_into_stack(t_data *data, int *index_for_stack, char *arg);

// The driver function which controls the overal flow of the program.
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 1)
	{
		initialise_data(&data);
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
	int	index_for_stack;

	i = 0;
	index_for_stack = 0;
	data->org_len = count_numbers(argv, argc);
	data->a_len = data->org_len;
	data->max = INT32_MIN;
	data->min = INT32_MAX;
	data->a = (t_list_item *)malloc((data->a_len + 1) * sizeof(t_list_item));
	if (data->a == NULL)
		freemem(data);
	while (i < argc - 1)
	{
		store_into_stack(data, &index_for_stack, argv[i + 1]);
		i++;
	}
}

int	count_numbers(char **argv, int argc)
{
	int		i;
	int		j;
	char	**arg_split;
	int		number_count;

	i = 1;
	number_count = 0;
	while (i <= argc - 1)
	{
		j = 0;
		arg_split = ft_split(argv[i], ' ');
		while (arg_split[j])
		{
			number_count++;
			free(arg_split[j]);
			j++;
		}
		free(arg_split);
		i++;
	}
	return (number_count);
}

void	store_into_stack(t_data *data, int *index_for_stack, char *arg)
{
	char	**arg_split;
	int		i;

	i = 0;
	arg_split = ft_split(arg, ' ');
	while (arg_split[i])
	{
		data->a[*index_for_stack].value = ft_atoi(arg_split[i]);
		check_input_validity(arg_split[i], data, *index_for_stack);
		if (data->a[*index_for_stack].value > data->max)
			data->max = data->a[*index_for_stack].value;
		if (data->a[*index_for_stack].value < data->min)
			data->min = data->a[*index_for_stack].value;
		free(arg_split[i]);
		(*index_for_stack)++;
		i++;
	}
	free(arg_split);
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
