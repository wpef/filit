/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:31:55 by hponcet           #+#    #+#             */
/*   Updated: 2015/12/17 20:43:28 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	int				ret;
	unsigned char	*ucs1;
	unsigned char	*ucs2;

	ucs1 = (unsigned char*)s1;
	ucs2 = (unsigned char*)s2;
	i = 0;
	while (ucs1[i] == ucs2[i])
	{
		if (ucs1[i] == '\0' && ucs2[i] == '\0')
			return (0);
		i++;
	}
	ret = (int)ucs1[i] - (int)ucs2[i];
	return (ret);
}
