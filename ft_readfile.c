/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:39:15 by fde-monc          #+#    #+#             */
/*   Updated: 2015/12/21 21:37:53 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

// if blocks = 4
// + les pieces doivent se toucher 6 ou 8 fois (en tout)

t_tris	*ft_maketab(char *buf)
{
	t_tris	**tetrimino; // t_tris **tetrim --> tableau >> t_trim[i]
	int 	col;
	int 	line;
	int 	i;
	int		k;

	col = 0;
	line = 0;
	i = 0;
	tetrimino = (t_tris *)malloc(sizeof(t_tris));
	while (i < 20)
	{
		printf("_____________ DO WHILE 1 _________\n");
		col = 0;
		while (buf[i] == '#' || buf[i] == '.')
		{
			tetrimino->tetrim[line][col] = buf[i];
			printf("%c copied in tet[%d][%d]!\n", buf[i], line, col);
			col++;
			i++;
		}
		if (buf[i] == '\n' && i < 20)
		{
			buf[i] = '\0';
			printf("N copied in tet[%d][%d]!\n", line, col);
			if (i < 20)
			{
				line++;
				i++;
			}
		}
		printf("i = %d _______ REDO WHILE ? ________\n", i);
	}
	printf(" --> NOP, END OF CODE !!\n");
	return (tetrimino);
}

int	ft_touch(char *buf)
{
	int i;
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
			if (buf [i - 5] == '#')
				touch++;
		}
		i++;
	}
	printf("SE TOUCHENT %d FOIS\n", touch);
	return (touch);
}

int	ft_isvalid(char *buf)
{
	int	i;
	int	block;
	int	j;
	int	touch;

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

int	main(int ac, char **av)
{	
	int		fd;
	int		ret;
	char	buf[21];
	char	line[1];
	int		ret2;

	if (ac < 2)
	{
		ft_putendl("NO FILE FOUND");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	while ((ret = read(fd, buf, 20)) > 0)
	{
		buf[20] = '\0';
		if (ft_isvalid(buf))
			{
				ft_putendl("===============> BUF IS VALID <================");
				//ft_maketab(buf);
			}
		else
			ft_putendl("=/=/=/=/=/=/=> BUF IS NOT VALID <=/=/=/=/=/=/");
		ret2 = read (fd, line, 1);
		if (line[0] != '\n')
		{
			ft_putendl("NOT WELL FORMATED");
			return (0);
		}
	}
	if (ret2 == 1)
	{	
		return (0);
	}
	return (0);
}
