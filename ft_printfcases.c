/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfcases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 06:04:13 by lejulien          #+#    #+#             */
/*   Updated: 2019/12/30 01:36:36 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"

char
	*ft_dominus(t_flags *flags, char **temp, char *c)
{
	char	*s;

	if (flags->resisneg == 1)
	{
		if (!(s = ft_strjoin(c, *temp)))
			return (NULL);
		free(*temp);
		flags->resisneg = 0;
		return (s);
	}
	else
	{
		if (!(s = ft_strdup(*temp)))
			return (NULL);
		free(*temp);
		return (s);
	}
	return (s);
}

void
	ft_isnegchecker(int nbr, t_flags *flags)
{
	if (nbr < 0)
		flags->resisneg = 1;
	else
		flags->resisneg = 0;
}

char
	*ft_precision_checker(int unsigned *nbr, t_flags *flags)
{
	char	*temp2;
	char	*temp;
	char	*zerocase;

	ft_isnegchecker((int)*nbr, flags);
	*nbr = ft_abs(*nbr);
	if (!(temp = ft_uitoa(*nbr)))
		return (NULL);
	if (flags->precision_present && !flags->precision && *nbr == 0)
	{
		if (!(zerocase = ft_strdup("")))
			return (NULL);
	}
	else
	{
		if (!(zerocase = ft_strdup(temp)))
			return (NULL);
	}
	free(temp);
	if (ft_precision_int(flags, &temp2, zerocase) == 0)
		return (NULL);
	free(zerocase);
	return (temp2);
}

int
	ft_addbordertwo(t_flags *flags, int *printed, char *s)
{
	char *sizeplusneg;
	char *border;

	if (flags->resisneg)
	{
		if (!(sizeplusneg = ft_addborder(s, flags,
					ft_abs(flags->size) - ft_strlen(s) - 1, 0)))
			return (-1);
		free(s);
		if (!(border = ft_dominus(flags, &sizeplusneg, "-")))
			return (-1);
	}
	else
	{
		if (!(border = ft_addborder(s, flags,
						ft_abs(flags->size) - ft_strlen(s), 0)))
			return (-1);
		free(s);
	}
	ft_putstr_fd(border, 1);
	*printed = *printed + ft_strlen(border);
	free(border);
	return (1);
}
