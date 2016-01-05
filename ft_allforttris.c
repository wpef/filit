/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allforttris.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 00:24:45 by hponcet           #+#    #+#             */
/*   Updated: 2015/12/24 12:31:39 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int			ft_checkttris(char **grid, t_tris *ttris, int gx, int gy)
{
	int			y;
	int			bx;
	int			by;
	int			i;
	
	y = 0;
	i = 0;
	while (i < 4)
	{
		bx = gx + ttris->coord[y][0];
		by = gy + ttris->coord[y][1];
		if (bx > ft_checkgridlen(grid))
			return (2);
		if (grid[bx][by] != '.' || bx > ft_checkgridlen(grid)
				|| by > ft_checkgridlen(grid))
			return (0);
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
		n0 = ttris->coord[j][0];
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

int		*ft_whereisttris(char **grid, t_tris **ttris)
{
		int	ret[2];
		int	x;
		int	y;
		int	*retour;

		retour = ret;
		x = 0;
		y = 0;
		ret[0] = 0;
		ret[1] = 0;
		while (grid[x] != NULL)
		{
			while (grid[x][y] != '\0')
			{
				if (grid[x][y] == ttris[0]->ltr)
				{
					if (x > ret[0])
				 		ret[0] = x;
					if (y > ret[1])
						ret[1] = y;
				}
				y++;
			}
			x++;
		}
		return (retour);
}
