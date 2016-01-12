/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 15:10:07 by fde-monc          #+#    #+#             */
/*   Updated: 2016/01/12 19:40:46 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_touch(char *buf)
{
	int	i;
	int	touch;

	i = 0;
	touch = 0;
	while (buf[i])
	{
		while (buf[i] == '.' || buf[i] == '\n')
			i++;
		if (buf[i] == '#')
		{
			if (buf[i + 1] == '#')
				touch++;
			if (buf[i - 1] == '#')
				touch++;
			if (buf[i + 5] == '#')
				touch++;
			if (buf[i - 5] == '#')
				touch++;
		}
		i++;
	}
	return (touch);
}

int			ft_isvalid(char *buf)
{
	int		i;
	int		block;
	int		j;
	int		touch;

	i = 0;
	block = 0;
	while (buf[i])
	{
		j = 0;
		while (buf[i] != '\n')
		{
			if (buf[i] == '.' || buf[i] == '#')
			{
				if (buf[i] == '#')
					block++;
				i++;
				j++;
			}
			else
				return (0);
		}
		if (buf[i] == '\n' && j == 4)
			i++;
		else
			return (0);
	}
	touch = ft_touch(buf);
	if (block == 4 && (touch == 6 || touch == 8))
		return (1);
	return (0);
}

int			ft_readfile(char *file)
{
	int		fd;
	int		ret;
	int		ttris;
	char	buf[21];
	char	line[1];
	int		ret2;

	ttris = 0;
	fd = open(file, O_RDONLY);
	while ((ret = read(fd, buf, 20)) > 0)
	{
		buf[20] = '\0';
		if (!ft_isvalid(buf))
			return (0);
		ret2 = read(fd, line, 1);
		if (line[0] != '\n')
			return (0);
		ttris++;
	}
	return (ttris);
}
