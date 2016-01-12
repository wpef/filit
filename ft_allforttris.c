/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allforttris.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 00:24:45 by hponcet           #+#    #+#             */
/*   Updated: 2016/01/12 17:58:08 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define DEBUG printf("%s %d %c\n", __func__, __LINE__, ttris->ltr)
int			ft_checkttris(char **grid, t_tris *ttris, int gx, int gy)
{
	int			y;
	int			bx;
	int			by;
	int			i;

	y = 0;
	i = 0;
	DEBUG;
	while (i < 4)
	{
	DEBUG;
		bx = gx + ttris->coord[y][0];
		by = gy + ttris->coord[y][1];
	DEBUG;
		if (bx >= ft_checkgridlen(grid)
				|| by >= ft_checkgridlen(grid) || grid[bx][by] != '.')
			return (0);
	DEBUG;
		y++;
		i++;
	}
	return (1);
}

char		**ft_writettris(char **grid, t_tris *ttris, int gx, int gy)
{
	int			y;
	int			bx;
	int			by;
	int			i;

	i = 0;
	y = 0;
	while (i < 4)
	{
		bx = gx + ttris->coord[y][0];
		by = gy + ttris->coord[y][1];
		grid[bx][by] = ttris->ltr;
		y++;
		i++;
	}
	return (grid);
}

char		**ft_deletettris(char **grid, t_tris *ttris)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	while (grid[x])
	{
		y = 0;
		while (grid[x][y])
		{
			if (grid[x][y] == ttris->ltr)
				grid[x][y] = '.';
			y++;
		}
		x++;
	}
	return (grid);
}

t_tris		*ft_replacettris(t_tris *ttris)
{
	int		n0;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 2)
	{
		n0 = ttris->coord[j][i];
		while (j < 4)
		{
			if (ttris->coord[j][i] < n0)
				n0 = ttris->coord[j][i];
			j++;
		}
		j = 0;
		while (j < 4)
		{
			ttris->coord[j][i] = ttris->coord[j][i] - n0;
			j++;
		}
		j = 0;
		i++;
	}
	return (ttris);
}

void		ft_printgrid(char **grid)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	while (grid[k])
	{
		l = 0;
		while (grid[k][l])
		{
			ft_putchar(grid[k][l]);
			l++;
		}
		ft_putendl("");
		k++;
	}
}
