/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:39:15 by fde-monc          #+#    #+#             */
/*   Updated: 2016/01/08 17:34:07 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tris		**ft_createttris(char *file)
{
	int		fd;
	int		ret;
	int		ttris;
	t_tris	**tab;

	ttris = ft_readfile(file);
	fd = open(file, O_RDONLY);
	tab = (t_tris **)malloc(sizeof(t_tris *) * ttris + 1);
	tab[ttris] = NULL;
	if (ttris <= 0)
	{
		close(fd);
		ft_putendl("error");
		return(NULL);
	}
	else if (!tab)
	{
		close(fd);
		ft_putendl("error");
		return(NULL);
	}
	tab = ft_filltab(fd);
	close(fd);
	return (tab);
}

t_tris	**ft_filltab(int fd)
{
	t_tris	**tab;
	char	buf[21];
	int		i;

	i = 0;
	while ((ret = read (fd, buf, 21)) > 0)
	{
		buf[20] = '\0';
		tab[i] = ft_makettris(buf);
		tab[i]->ltr = 'A' + i;
		i++;
	}
	close(fd);
	return (tab);
}

t_tris		*ft_makettris(char *buf)
{
	t_tris	*ttris;
	int 	col;
	int 	line;
	int 	i;
	int		j;

	col = 0;
	line = 0;
	i = 0;
	j = 0;
	ttris = (t_tris *)malloc(sizeof(t_tris));
	while (buf[i] != '\0' && line < 4)
	{
		if (buf[i] == '#')
		{
			ttris->coord[j][1] = col;
			ttris->coord[j][0] = line;
			j++;
			i++;
			col++;
		}
		while (buf[i] == '.')
		{
			i++;
			col++;
		}
		if (buf[i] == '\n')
		{
			col = 0;
			line++;
			i++;
		}
	}
	return (ft_replacettris(ttris));
}

int			ft_touch(char *buf)
{
	int 	i;
	int		touch;

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
			if (buf [i - 5] == '#')
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
			{
				ft_putendl("error : WRONG CHAR");
				return (0);
			}
		}
		if (buf[i] == '\n' && j == 4)
			i++;
		else
		{
			ft_putendl("error : LINE TOO LONG");
			return (0);
		}
	}
	touch = ft_touch(buf);
	if (block == 4 && (touch == 6 || touch == 8))
		return (1);
	ft_putendl ("error : SHAPE IS NOT VALID");
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
		ft_checkchar(buf);
			if (!ft_isvalid(buf))
				return (0);
			ret2 = read (fd, line, 1);
			if (line[0] != '\n')
			{
				ft_putendl("error");
				return (0);
			}
		ttris++;
	}
	return (ttris);
}
