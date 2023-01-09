/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:57:27 by oanttoor          #+#    #+#             */
/*   Updated: 2022/10/24 15:57:29 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = 0;
	while (i < (int)n)
	{
		*(ptr + i) = '\0';
		i++;
	}
}
