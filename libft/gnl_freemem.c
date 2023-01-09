/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:05:15 by oanttoor          #+#    #+#             */
/*   Updated: 2022/11/07 13:05:18 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

void	gnl_freemem(t_buffer *buffer, t_cache *cache)
{
	if (buffer->arr)
	{
		free(buffer->arr);
		buffer->arr = NULL;
	}
	if (cache->arr)
	{
		free(cache->arr);
		cache->arr = NULL;
	}
	if (buffer->eof == 1)
		buffer->eof = 0;
}
