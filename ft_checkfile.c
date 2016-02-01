/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 15:10:07 by fde-monc          #+#    #+#             */
/*   Updated: 2016/01/27 15:19:20 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_block(char *buf)
{
	int	block;
	int	i;

	block = 0;
	i = 0;
    while (buf[i])
    {
        if (buf[i] == '#')
            block++;
        else if (buf[i] == '.')
            c++;
        i++;
    }	if (block == 4)
		return (1);
	return (0);
}

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
	if (touch == 6 || touch == 8)
		return (1);
	return (0);
}

int			ft_isvalid(char *buf)
{
	int		i;

	i = 0;
	while (buf[i])
	{
		while (buf[i] != '\n')
		{
			if (buf[i] == '.' || buf[i] == '#')
				i++;
			else
				return (0);
		}
		if (buf[i] == '\n' && (i % 5) == 4)
			i++;
		else
			return (0);
	}
	if (ft_touch(buf) && ft_block(buf))
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

	ttris = 0;
	fd = open(file, O_RDONLY);
	while ((read(fd, buf, 20)) > 0)
	{
		buf[20] = '\0';
		if (!ft_isvalid(buf))
			return (0);
		ret = read(fd, line, 1);
		if (ret && line[0] != '\n')
		{
			ft_putendl("NO NEW LINE");
			return (0);
		}
		ttris++;
	}
	if (ret >= 1)
		return (0);
	return (ttris);
}
