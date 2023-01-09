/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:03:47 by oanttoor          #+#    #+#             */
/*   Updated: 2022/10/24 16:03:49 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;
	int		found;

	found = -1;
	ptr = (char *)s;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			found = i;
			i++;
		}
		else
			i++;
	}
	if ((char)c == '\0')
		return (&ptr[i]);
	else if (found != -1)
		return (&ptr[found]);
	else
		return (NULL);
}
