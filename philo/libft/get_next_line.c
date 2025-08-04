/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:02:39 by lmiguel-          #+#    #+#             */
/*   Updated: 2024/03/06 15:01:20 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*set_result(char *buffer)
{
	int		n;
	int		len;
	char	*result;
	char	*newline;

	n = -1;
	newline = ft_strchr_gnl(buffer, '\n');
	len = ft_strlen_gnl(buffer) - ft_strlen_gnl(newline) + 1;
	result = (char *)malloc (sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	while (++n < len)
		result[n] = (buffer)[n];
	result[n] = '\0';
	n = -1;
	while (++n < (int)ft_strlen_gnl(newline) - 1)
		buffer[n] = newline[n + 1];
	while (n < BUFFER_SIZE)
		buffer[n++] = 0;
	return (result);
}

char	*get_next_line(int fd)
{
	static char		buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char			*result;
	int				bytes;

	if (fd > FOPEN_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = NULL;
	if (buffer[fd][0])
		result = ft_strjoin_gnl(result, set_result(buffer[fd]));
	while (!ft_strchr_gnl(result, '\n'))
	{
		bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes < 0)
		{
			if (result)
				free (result);
			return (NULL);
		}
		if (bytes == 0)
			return (result);
		result = ft_strjoin_gnl(result, set_result(buffer[fd]));
	}
	return (result);
}

/* int main(void)
{
	int fd = open ("test.txt", O_RDWR | O_CREAT);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close (fd);
	return (0);
} */