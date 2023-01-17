/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_b_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:03:44 by oanttoor          #+#    #+#             */
/*   Updated: 2023/01/17 13:03:46 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
Finds the median value in the array 'a' and 
assigns it to 'median' in the t_data struct 
*/
void	find_median(t_data *data)
{
	int	i;
	int	middle_value;

	i = 0;
	middle_value = data->a_len / 2 - 1;
	calculate_indexes_in_a(data);
	while (i < data->a_len)
	{
		if (data->a[i].index == middle_value)
		{
			data->median = data->a[i].value;
			i = data->a_len;
		}
		else
			i++;
	}
}
