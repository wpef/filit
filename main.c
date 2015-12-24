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

	i = 0;
	if (ac > 2)
		return (0);
	ttris = ft_createttris(av[1]);
	ft_putendl("TTRIS correctly created.");

	grid = ft_creategrid(ft_rootforgrid(ttris), ft_rootforgrid(ttris));
	ft_putendl("Grid correctly created");
	while (ttris[i] != NULL)
	{
		if (ft_checkttris(grid, ttris[i], 0, 0) == 1)
		{
			ft_putendl("Check TTRIS in grid OK.");
			grid = ft_writettris(grid, ttris[0], 0, 0);
			ft_putendl("Write TTRIS in grid OK.");
		}
		else
			ft_putendl("Check TTRIS in grid FALSE.");
		i++;
	}
	return (0);
}
