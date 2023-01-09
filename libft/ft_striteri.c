/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:10:05 by oanttoor          #+#    #+#             */
/*   Updated: 2022/10/24 16:10:07 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	len;
	int	i;

	if (s && f)
	{
		i = 0;
		len = ft_strlen((char *)s);
		while (i < len)
		{
			f(i, &s[i]);
			i++;
		}
	}
}
