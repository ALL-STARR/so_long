/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:27:25 by marvin            #+#    #+#             */
/*   Updated: 2024/07/23 20:27:17 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "so_long.h"

char	**map_check(char *file_name)
{
	int		fd;
	char	*line;
	int		totlen;
	int		len;
	char	**map;

	totlen = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!totlen)
			len = ft_strlen(line);
		totlen += ft_strlen(line) + 1;
		if (len != ft_strlen(line) || len == 0)
		{
			ft_printf("Error : map is not rectangular\n");
			return (NULL);
		}
	}
	return (close(fd), map_maker(file_name, totlen));
}

char	**map_maker(char *f_n, int tlen)
{
	int		fd;
	char	**map;
	char	*buff;
	int		len;

	buff = malloc(sizeof(char) * (tlen + 1));
	fd = open(f_n, O_RDONLY);
	if (fd == -1)
		return (NULL);
	len = read(fd, buff, tlen);
	buff[len] = '\0';
	if (!counter(buff))
	{
		ft_printf("Error : wrong number of assets\n");
		free(buff);
		return (NULL);
	}
	map = ft_split(buff, '\n');
	if (!is_enclosed(map))
	{
		ft_printf("Error : the map is not enclosed");
		free(buff);
		return (NULL);
	}
	return (free(buff), map);
}

int	counter(char *buf)
{
	int	ep;
	int	c;
	int	i;

	ep = 0;
	c = 0;
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == 'E' || buf[i] == 'P')
			ep++;
		if (buf[i] == 'C')
			c++;
		i++;
	}
	if (ep != 2 || c == 0)
		return (0);
	return (c);
}

int	is_enclosed(char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 1;
	while (map[i])
		i++;
	while (map[0][j])
		if (map[0][j++] != '1')
			return (0);
	while (map[k] && k < i - 1)
	{
		if (map[k][0] != '1' || map[k][j - 1] != '1')
			return (0);
		k++;
	}
	j = 0;
	while (map[i - 1][j])
		if (map[i - 1][j++] != '1')
			return (0);
	return (1);
}

int	**map_cpy(char **map)
{
	int	i;
	int	j;
	int	**mcpy;
	int	len;

	i = 0;
	j = 0;
	while (map[0][j])
		j++;
	while (map[i])
		i++;
	mcpy = malloc(sizeof(int *) * (i + 1));
	if (!mcpy)
		return (NULL);
	len = i;
	i = 0;
	while (i < len)
	{
		mcpy[i] = calloc((j + 1), sizeof(int));
		if (!mcpy[i])
			return (NULL);
		mcpy[i][j] = '\0';
		i++;
	}
	return (mcpy);
}
