/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 23:13:38 by hponcet           #+#    #+#             */
/*   Updated: 2016/01/12 16:10:07 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	t_tris		**ttris;
	char		**grid;
	int			i;

	i = 0;
	if (ac > 2)
		return (0);
	ttris = ft_createttris(av[1]);
	if (ttris <= 0)
	{
		ft_putendl("error");
		return (0);
	}
	grid = ft_creategrid(ft_rootforgrid(ttris), ft_rootforgrid(ttris));
	while (ft_fillit(grid, ttris, 0, 0) == 0)
	{
		grid = ft_modifgrid(grid);
		ft_putendl("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
	}
	ft_printgrid(grid);
	return (0);
}

int			ft_fillit(char **grid, t_tris **ttris, int x, int y)
{
	while (grid[x + 1] != NULL)
	{
		y = 0;
		while (grid[x][y] != '\0')
		{
			if (ttris[1] != NULL)
				ft_deletettris(grid, ttris[0]);
			if (ft_checkttris(grid, ttris[0], x, y) == 1 && ttris[1] != NULL)
			{
				grid = ft_writettris(grid, ttris[0], x, y);
				ft_putendl("---------");
				ft_printgrid(grid);
				ft_putendl("---------");
				ft_fillit(grid, ttris + 1, 0, 0);
			}
			if (ft_checkttris(grid, ttris[0], x, y) == 1 && ttris[1] == NULL)
				ttris[0] = NULL;
			y++;
		}
		x++;
	}
	if (ft_checkttris(grid, ttris[0], x, y) == 1 && ttris[1] == NULL)
		return (1);
	else
		return (0);
}
