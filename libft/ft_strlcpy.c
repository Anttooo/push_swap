/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:01:19 by oanttoor          #+#    #+#             */
/*   Updated: 2022/10/24 16:01:21 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	max_len;
	int		src_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen((char *)src);
	max_len = dstsize - 1;
	if (dstsize == 0)
		return (src_len);
	while (i < max_len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
