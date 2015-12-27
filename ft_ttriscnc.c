/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ttriscnc.c                                      :+:      :+:    :+:   */
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

	y = 0;
	while (ttris->coord[y])
	{
		bx = gx + ttris->coord[y][0];
		by = gy + ttris->coord[y][1];
		ft_putnbr(bx);
		ft_putchar(',');
		ft_putnbr(by);
		ft_putendl("");
		if (grid[bx][by] == '#' || bx > ft_rootforgrid(&(ttris))
				|| by > ft_rootforgrid(&(ttris)))
			return (0);
		else
			y++;
	}
	return (1);
}

char		**ft_writettris(char **grid, t_tris *ttris, int gx, int gy)
{
	int			y;
	int			bx;
	int			by;

	y = 0;
	while (ttris->coord[y])
	{
		bx = gx + ttris->coord[y][0];
		by = gy + ttris->coord[y][1];
		grid[bx][by] = ttris->ltr;
		y++;
	}
	return (grid);
}

char		**ft_deletettris(char **grid, t_tris *ttris, int gx, int gy)
{
	int		y;
	int		bx;
	int		by;

	y = 0;
	while (ttris->coord[y])
	{
		bx = gx + ttris->coord[y][0];
		by = gy + ttris->coord[y][1];
		grid[bx][by] = '.';
		y++;
	}
	return (grid);
}
