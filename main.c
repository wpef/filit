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

int		main(int ac, char **av)
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

	i = 0;
	while (ttris[i] != NULL)
	{
		if (ft_checkttris(grid, ttris[i], 0, 0) == 1)
		{
			ft_putendl("Check TTRIS in grid OK.");
			grid = ft_writettris(grid, ttris[i], 0, 0);
			ft_putendl("Write TTRIS in grid OK.");
		}
		else
			ft_putendl("Check TTRIS in grid FALSE.");
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
		// Delete grid
		grid = ft_deletettris(grid, ttris[i], 0, 0);
		grid = ft_modifgrid(grid);
		i++;
	}

	return (0);
}
