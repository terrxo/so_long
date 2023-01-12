/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:38:38 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/12 14:54:18 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 21
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin_t(char *s1, char *s2);
int		ft_strchr_t(const char *s, char c);
char	*cache_fd(int fd, char *buffer);
char	*read_line(char *buffer);
char	*make_temp(char *buffer, int i);
size_t	ft_strlen_t(const char *s);
void	ft_bzero_t(void *s, size_t n);

#endif
