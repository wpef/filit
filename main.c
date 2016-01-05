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
	while (ft_fillit(grid, ttris, 0, 0) == 0)
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

int			ft_fillit(char **grid, t_tris **ttris, int x, int y)
{
	int	k;
	int	l;
	int	*orig;

	orig = NULL;
	while (grid[x] != NULL)
	{
		y = 0;
		while (grid[x][y] != '\0')
		{
			grid = ft_deletettris(grid, ttris[0]);
			if (ft_checkttris(grid, ttris[0], x, y) == 2)
					return (0);
			if (ft_checkttris(grid, ttris[0], x, y) == 1) // If ttris VALID
			{
				grid = ft_writettris(grid, ttris[0], x, y);
	////////////////////////////////////// DEBUG
	ft_putendl("");
	ft_putendl("--------------");
	ft_putendl("Initialisation");
	ft_putstr("Le ttris ");
	ft_putchar(ttris[0]->ltr);
	ft_putendl("");
	ft_putstr("Ecrit en ");
	ft_putnbr(x), ft_putchar('/'), ft_putnbr(y);
	ft_putendl("");
	ft_putendl("--------------");

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

				ft_fillit(grid, ttris + 1, 0, 0);
			}
<<<<<<< HEAD
			ft_putnbr(x), ft_putnbr(y);
=======
			ft_putnbr(x), ft_putnbr(y), ft_putchar(' ');
>>>>>>> 8e4fb89ec59a18df1609d6109e828170c4a57dee
			y++;
		}
		x++;
	}
	return (0);
}
