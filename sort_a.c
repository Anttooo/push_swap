/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:22:22 by oanttoor          #+#    #+#             */
/*   Updated: 2023/01/17 10:22:24 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sorts the first three elements of stack 'a'
void	sort_a(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->a[0].value;
	b = data->a[1].value;
	if (data->a_len == 2)
	{
		if (b < a)
			swap_a(data);
	}
	if (data->a_len == 3)
	{
		c = data->a[2].value;
		if (is_acb(a, b, c) == 1)
		{
			reverse_rotate_a(data);
			swap_a(data);
		}
		else if (is_bca(a, b, c))
			reverse_rotate_a(data);
		else if (is_cab(a, b, c))
			rotate_a(data);
		else if (is_bac(a, b, c))
			swap_a(data);
		else if (is_cba(a, b, c))
		{
			rotate_a(data);
			swap_a(data);
		}
	}
}
