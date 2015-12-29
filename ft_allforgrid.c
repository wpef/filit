/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allforgrid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 05:04:33 by hponcet           #+#    #+#             */
/*   Updated: 2015/12/24 12:31:45 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int			ft_rootforgrid(t_tris **ttris)
{
	int		nb;

	nb = 0;
	while (ttris[nb] != NULL)
		nb++;
	return (ft_rootsquare(nb * 4));
}
char		**ft_creategrid(int x, int y)
{
	char		**grid;
	int			i;
	int			j;

	i = 0;
	grid = ft_createtab(x, y);
	while (grid[i] != NULL)
	{
		j = 0;
		while (j < x)
		{
			grid[i][j] = '.';
			j++;
		}
		i++;
	}
	return (grid);
}

char		**ft_modifgrid(char **grid)
{
	int		i;
	int		j;
	int		count;
	char	**newtab;

	i = 0;
	j = 0;
	count = 0;
	while (grid[i][count])
		count++;
	newtab = ft_creategrid(count + 1, count + 1);
	while (j < count)
	{
		while (grid[i] && newtab[j])
		{
			newtab[j] = ft_strncpy(newtab[j], grid[i], count);
			i++;
			j++;
		}
	}
	return (newtab);
}
