/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:08:16 by oanttoor          #+#    #+#             */
/*   Updated: 2023/01/17 11:08:17 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_acb(int a, int b, int c)
{
	if (a <= b && c <= b && a <= c)
		return (1);
	else
		return (0);
}

int	is_bca(int a, int b, int c)
{
	if (a <= b && c <= b)
		return (1);
	else
		return (0);
}

int	is_cab(int a, int b, int c)
{
	if (b <= a && c <= a && b <= c)
		return (1);
	else
		return (0);
}

int	is_bac(int a, int b, int c)
{
	if (b <= a && a <= c)
		return (1);
	else
		return (0);
}

int	is_cba(int a, int b, int c)
{
	if (c <= b && b <= a)
		return (1);
	else
		return (0);
}
