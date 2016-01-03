/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 23:13:38 by hponcet           #+#    #+#             */
/*   Updated: 2015/12/24 12:31:36 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int			main(int ac, char **av)
{
	t_tris		**ttris;
	char		**grid;
	int			i;
	int			k;
	int			l;

	i = 0;
	if (ac > 2)
		return (0);
	ttris = ft_createttris(av[1]);
	grid = ft_creategrid(ft_rootforgrid(ttris), ft_rootforgrid(ttris));
	while (ft_fillit(grid, ttris, 0, 0, 0) == 0)
			grid = ft_modifgrid(grid);
	// Print writed grid
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
	return (0);
}

int			ft_fillit(char **grid, t_tris **ttris, int x, int y, int t)
{
	int	*orig;
	int	k;
	int	l;

	ft_putendl("Initialisation");
	////////////////////////////////////// DEBUG
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
	/////////////////////////////////////// DEBUG
	while (grid[x])
	{
		while (grid[x][y])
		{
			if (ttris[t] == NULL) // If all VALID
				return (1);
			grid = ft_deletettris(grid, ttris[t]);
			if (grid[x + 1] == '\0' && grid[x][y + 1] == '\0' && ttris[t]->ltr == 'A') // If end and not valid
				return (0);
			if (ft_checkttris(grid, ttris[t], y, x) == 1) // If ttris VALID
			{
				grid = ft_writettris(grid, ttris[t], x, y);
				ft_fillit(grid, &(ttris[t]), 0, 0, t + 1);
			}
			if (grid[x + 1] == '\0' && grid[x][y + 1] == '\0') // If end and not valid
			{
				orig = ft_whereisttris(grid, ttris[t - 1]);
				ft_fillit(grid, &(ttris[t]), orig[0], orig[1], t - 1);
			}
			y++;
		}
		x++;
	}
	return (0);
}
