/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:41:13 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/06/01 15:14:02 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*ans;
	char			*buf;
	char			*temp;

	ans = NULL;
	temp = malloc(sizeof(char) * 1);
	temp[0] = '\0';
	buf = malloc(sizeof(char) * 2);
	if (buf == 0)
		return (free(temp), free(buf), NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(temp), free(buf), ans = NULL, NULL);
	while ((read(fd, buf, 1) > 0))
	{
		free(ans);
		ans = ft_strjoin(temp, buf);
		free(temp);
		if (buf[0] == '\n')
			return (free(buf), ans);
		temp = ft_strdup(ans);
		if (temp == NULL)
			return (free(temp), free(buf), free(ans), ans = NULL, NULL);
	}
	return (free(buf), free(temp), ans);
}
int main(void)
{
    int fd1;
    int fd2;

    char *str1;
    char *str2;
    char *str3;

	fd1 = open("test1", O_RDONLY);
	fd2 = open("test2", O_RDONLY);

	char *test1_str1 = get_next_line(fd1);
	char *test2_str1 = get_next_line(fd2);
	char *test1_str2 = get_next_line(fd1);
	char *test2_str2 = get_next_line(fd2);
	char *test1_str3 = get_next_line(fd1);
	char *test2_str3 = get_next_line(fd2);

	printf("%s", test1_str1);
	printf("%s", test1_str2);
	printf("%s", test1_str3);

	printf("%s", test2_str1);
	printf("%s", test2_str2);
	printf("%s", test2_str3);
    return 0;
}