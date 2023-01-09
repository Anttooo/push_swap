/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:01:08 by oanttoor          #+#    #+#             */
/*   Updated: 2022/10/24 16:01:09 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static size_t	get_dst_len(char *dst, size_t dstsize);
static size_t	chars_to_copy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	cpy_len;
	size_t	start_index;
	size_t	total_len;
	size_t	dst_len;

	if (dstsize == 0 && !dst)
		return (dstsize + ft_strlen((char *)src));
	dst_len = get_dst_len(dst, dstsize);
	cpy_len = chars_to_copy(dst, src, dstsize);
	total_len = dst_len + ft_strlen((char *)src);
	if (dstsize == 0)
		return (ft_strlen((char *)src));
	if (cpy_len == 0)
		return (ft_strlen((char *)src) + dst_len);
	else
	{
		start_index = ft_strlen(dst);
		ft_memcpy((char *)(dst + start_index), (char *)src, cpy_len);
		*(dst + start_index + cpy_len) = '\0';
	}
	return (total_len);
}

static size_t	chars_to_copy(char *dst, const char *src, size_t dstsize)
{
	size_t	max_len_that_fits;
	size_t	chars_to_copy;

	max_len_that_fits = dstsize - ft_strlen(dst) - 1;
	if (ft_strlen(dst) >= dstsize || dstsize == 0)
		return (0);
	if (max_len_that_fits >= ft_strlen((char *)src))
		chars_to_copy = ft_strlen((char *)src);
	else if (max_len_that_fits > 0)
		chars_to_copy = max_len_that_fits;
	else
		chars_to_copy = 0;
	return (chars_to_copy);
}

static size_t	get_dst_len(char *dst, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize && dst[i] != '\0')
		i++;
	return (i);
}
