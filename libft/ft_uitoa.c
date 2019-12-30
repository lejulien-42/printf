/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 07:08:55 by lejulien          #+#    #+#             */
/*   Updated: 2019/12/19 05:12:08 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_itoa2(int iszero, unsigned int nu, unsigned int i)
{
	char			*res;

	if (!(res = malloc((i + 1) * sizeof(char))))
		return (0);
	res[i] = '\0';
	while (nu > 0)
	{
		i--;
		res[i] = nu % 10 + '0';
		nu = nu / 10;
	}
	i--;
	if (iszero)
	{
		res[i] = nu + '0';
		i--;
	}
	if (i == 0)
		res[i] = '-';
	return (res);
}

char		*ft_uitoa(unsigned int n)
{
	unsigned int	nu;
	unsigned int	i;
	int				iszero;

	i = 0;
	if (n <= 0)
	{
		nu = -n;
		i++;
	}
	else
		nu = n;
	iszero = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	if (nu == 0)
		iszero++;
	return (ft_itoa2(iszero, nu, i));
}
