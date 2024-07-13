/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:27:25 by marvin            #+#    #+#             */
/*   Updated: 2024/07/13 13:27:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

char	**map_check(char *file_name)
{
	int		fd;
	char	*line;
	int		totlen;
	int		len;
	char	**map;

	totlen = 0;
	fd = open(file_name, O_RDONLY);
	(if fd == -1)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (!totlen)
			len = ft_strlen(line);
		totlen += len;
		if (len != ft_strlen(line) || len == 0)
			return (NULL);
	}
	close(fd);
	return (map_maker(file_name, totlen));
}

char	**map_maker(char *f_n, int tlen, int len)
{
	int		fd;
	char	**map
	char	buff[tlen + 1];
	int		len;

	fd = open(f_n, O_RDONLY);
	(if fd == -1)
		return (NULL);
	len = read(fd, buff, tlen + 1);
	buff[len] = '\0';
	return (ft_split(buff, '\n'));
}