/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:01:33 by oanttoor          #+#    #+#             */
/*   Updated: 2022/10/24 16:01:35 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;
	size_t	i;

	length = 0;
	i = 0;
	while (s[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}
