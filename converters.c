/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:31:29 by lejulien          #+#    #+#             */
/*   Updated: 2019/12/30 03:42:27 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char
	*ft_addchar(char *str, char c, int way)
{
	char	*tmp;
	char	*tosend;

	if (!(tmp = malloc(2 * sizeof(char))))
		return (NULL);
	tmp[0] = c;
	tmp[1] = '\0';
	if (!str)
		return (tmp);
	if (way == 1)
		tosend = ft_strjoin(str, tmp);
	else
		tosend = ft_strjoin(tmp, str);
	free(tmp);
	free(str);
	return (tosend);
}

char
	*ft_itox(unsigned int x, char *hextable)
{
	char	*res;

	res = malloc(sizeof(int));
	*res = '\0';
	if (x == 0)
		res = ft_addchar(res, '0', 0);
	while (x > 0)
	{
		res = ft_addchar(res, hextable[x % 16], 0);
		x = x / 16;
	}
	return (res);
}

char
	*ft_ulltox(unsigned long long int x, char *hextable)
{
	char	*res;

	res = malloc(sizeof(int));
	*res = '\0';
	if (x == 0)
		res = ft_addchar(res, '0', 0);
	while (x > 0)
	{
		res = ft_addchar(res, hextable[x % 16], 0);
		x = x / 16;
	}
	return (res);
}
