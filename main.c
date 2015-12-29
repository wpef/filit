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
	while (ft_fillit(grid, ttris[0]) == 0)
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
}

int			ft_fillit(char **grid, t_tris *ttris, int x, int y)
{
	ft_putendl("Initialisation");
	while (grid[x])
	{
		while (grid[x][y])
			{
				if (ft_checkttris(grid, ttris, x, y) == 1)
				{
					grid = ft_writettris(grid, ttris, x, y);			
					ft_fillit(grid, ttris + 1, 0, 0);
				}
				else
					ft_fillit(grid, ttris, x, y + 1);
			}
		ft_fillit(grid, ttris, x + 1, 0);
	}
	if (grid[x] == '\0' && grid[x][y] == '\0' && ttris + 1 != NULL)

}

char		*ft_whereisttris(char **grid, t_tris *trtis)
{
		char	ret[2];
