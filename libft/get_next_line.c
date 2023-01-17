/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oanttoor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:04:49 by oanttoor          #+#    #+#             */
/*   Updated: 2022/11/07 13:04:53 by oanttoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int		get_eol(t_buffer *buf);
int		update_cache(t_buffer *buf, t_cache *cache);
int		expand_cache(t_cache *cache, int arr_len, int i);
int		get_next_buffer(t_buffer *buf, t_cache *cache, int fd);

char	*get_next_line(int fd)
{
	static t_buffer	buf;
	t_cache			cache;

	cache.arr = (char *)malloc(1 * sizeof(char));
	cache.arr[0] = '\0';
	while (buf.eol_found != 1 && !(buf.eof == 1 && buf.eol >= buf.read_len))
	{
		if (!buf.arr && buf.eof != 1)
		{
			if (get_next_buffer(&buf, &cache, fd) == 0)
				return (NULL);
		}
		if (update_cache(&buf, &cache) == 0)
			return (NULL);
	}
	buf.eol_found = 0;
	buf.index = buf.eol;
	if (cache.arr[0] == '\0')
		gnl_freemem(&buf, &cache);
	return (cache.arr);
}

int	get_next_buffer(t_buffer *buf, t_cache *cache, int fd)
{
	buf->index = 0;
	buf->arr = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf->arr)
	{
		gnl_freemem(buf, cache);
		return (0);
	}
	buf->read_len = read(fd, buf->arr, BUFFER_SIZE);
	if (buf->read_len == -1)
	{
		gnl_freemem(buf, cache);
		return (0);
	}
	buf->arr[buf->read_len] = '\0';
	if (buf->read_len < BUFFER_SIZE || buf->read_len == 0)
		buf->eof = 1;
	return (1);
}

int	update_cache(t_buffer *buf, t_cache *cache)
{
	int	arr_len;
	int	i;

	i = -1;
	if (buf->read_len == 0 && ft_strlen(cache->arr) == 0)
	{
		gnl_freemem(buf, cache);
		return (0);
	}
	buf->eol = get_eol(buf);
	arr_len = ft_strlen(cache->arr) + (buf->eol - buf->index) + 1;
	if (expand_cache(cache, arr_len, i) == 0)
	{
		gnl_freemem(buf, cache);
		return (0);
	}
	ft_strlcat(cache->arr, (buf->arr + buf->index), arr_len);
	if (buf->eol == BUFFER_SIZE)
	{
		free(buf->arr);
		buf->arr = NULL;
	}
	return (1);
}

int	get_eol(t_buffer *buf)
{
	int		i;

	i = buf->index;
	while (i < BUFFER_SIZE)
	{
		if (buf->arr[i] == '\n' || buf->arr[i] == '\0')
		{
			buf->eol_found = 1;
			if (buf->arr[i] == '\0')
				buf->eof = 1;
			return (++i);
		}
		i++;
	}
	return (BUFFER_SIZE);
}

int	expand_cache(t_cache *cache, int arr_len, int i)
{
	int	temp_size;

	cache->temp_cache = NULL;
	temp_size = ft_strlen(cache->arr);
	if (temp_size > 0)
	{
		cache->temp_cache = (char *)malloc((temp_size + 1) * sizeof(char));
		if (cache->temp_cache == NULL)
			return (0);
		while (++i < temp_size)
			cache->temp_cache[i] = cache->arr[i];
		cache->temp_cache[i] = '\0';
	}
	free(cache->arr);
	cache->arr = (char *)malloc((arr_len) * sizeof(char));
	if (cache->arr == NULL)
		return (0);
	if (cache->temp_cache)
	{
		ft_strlcpy(cache->arr, cache->temp_cache, arr_len);
		free(cache->temp_cache);
	}
	else
		cache->arr[0] = '\0';
	return (1);
}
