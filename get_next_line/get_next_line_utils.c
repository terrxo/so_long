/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:51:31 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/12 14:54:35 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_t(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_t(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*temp;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1 || !s2)
			return (0);
		s1[0] = '\0';
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen_t(s1) + ft_strlen_t(s2)
				+ 1));
	if (!temp)
		return (0);
	while (s1[++i])
		temp[i] = s1[i];
	while (s2[j])
		temp[i++] = s2[j++];
	temp[i] = '\0';
	free(s1);
	return (temp);
}

int	ft_strchr_t(const char *s, char c)
{
	if (!s)
		return (1);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

void	ft_bzero_t(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}
