/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:08:47 by oanttoor          #+#    #+#             */
/*   Updated: 2022/10/24 16:08:49 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	get_substr_size(char const *s, unsigned int start, size_t max_len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	unsigned int	src_len;
	size_t			substr_len;

	if (!s)
		return (NULL);
	substr_len = get_substr_size(s, start, len);
	src_len = (int)(ft_strlen((char *)s));
	if (substr_len > src_len)
		substr_len = src_len;
	dst = (char *)malloc((substr_len + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	if (start >= src_len)
		len = 0;
	ft_strlcpy(dst, (char *)(s + start), len + 1);
	return (dst);
}

size_t	get_substr_size(char const *s, unsigned int start, size_t max_len)
{
	size_t	sub_str_len;

	sub_str_len = ft_strlen((char *)s) - (size_t)(start);
	if (sub_str_len >= max_len)
		return (max_len);
	else
		return (sub_str_len);
}
