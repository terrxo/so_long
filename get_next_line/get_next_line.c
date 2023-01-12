/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:05:21 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/12 14:54:20 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cache_fd(int fd, char *buffer)
{
	char	*swap;
	int		bytes_read;

	bytes_read = 1;
	swap = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!swap)
		return (0);
	ft_bzero_t(swap, BUFFER_SIZE + 1);
	while (ft_strchr_t(swap, '\n') == 0 && bytes_read > 0)
	{
		bytes_read = read(fd, swap, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(swap);
			free(buffer);
			return (0);
		}
		swap[bytes_read] = '\0';
		buffer = ft_strjoin_t(buffer, swap);
	}
	free(swap);
	return (buffer);
}

char	*read_line(char *buffer)
{
	int		i;
	char	*out;

	i = 0;
	if (!buffer[0])
		return (0);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	out = malloc(sizeof(char) * (i + 1));
	if (!out)
		return (0);
	out[i] = '\0';
	while (i--)
		out[i] = buffer[i];
	return (out);
}

char	*make_temp(char *buffer, int i)
{
	char			*temp;
	unsigned int	x;

	x = 0;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	if (buffer[i] == '\n')
		i++;
	while (buffer[i + x])
		x++;
	temp = malloc(sizeof(char) * (x + 1));
	if (!temp)
		return (0);
	temp[x] = '\0';
	while (x--)
		temp[x] = buffer[i + x];
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;
	unsigned int	i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = cache_fd(fd, buffer);
	if (!buffer)
		return (0);
	line = read_line(buffer);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	buffer = make_temp(buffer, i);
	return (line);
}
