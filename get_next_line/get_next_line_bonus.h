/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:12:33 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/06/14 18:37:46 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif
# include<stdlib.h>
# include<libc.h>

int		ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*read_file(int fd, char *res);
char	*ft_line(char *buffer);
char	*ft_next(char *buffer);
char	*ft_free(char *buffer, char *buf);

#endif