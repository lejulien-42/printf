/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addborders.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 20:05:14 by lejulien          #+#    #+#             */
/*   Updated: 2019/12/30 03:30:34 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"

char
	*ft_addborder(char *str, t_flags *flags, int size, int isint)
{
	char	filling[size];
	int		i;
	char	*res;
	char	filler;

	i = 0;
	filler = (flags->iszero && !flags->isneg) ? '0' : ' ';
	if (isint)
		filler = '0';
	while (i < size)
		filling[i++] = filler;
	filling[i] = '\0';
	if (!flags->isneg)
	{
		if (!(res = ft_strjoin(filling, str)))
			return (NULL);
		return (res);
	}
	else
	{
		if (!(res = ft_strjoin(str, filling)))
			return (NULL);
		return (res);
	}
	free(str);
}

char
	*ft_addborder_int(char *str, int size)
{
	char	filling[size];
	int		i;
	char	*res;
	char	filler;

	i = 0;
	filler = '0';
	while (i < size)
		filling[i++] = filler;
	filling[i] = '\0';
	if (!(res = ft_strjoin(filling, str)))
		return (NULL);
	return (res);
}

char
	*ft_addbordertoc(char c, t_flags *flags, int size)
{
	int		i;
	char	*str;
	char	*res;

	if (!(str = malloc(2 * sizeof(char))))
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	i = 0;
	res = ft_addborder(str, flags, size, 0);
	free(str);
	return (res);
}
