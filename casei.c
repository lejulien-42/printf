/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casei.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 01:18:57 by lejulien          #+#    #+#             */
/*   Updated: 2019/12/30 03:34:39 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "./libft/libft.h"

static char
	*ft_doitwo(t_flags *flags, va_list va)
{
	char			*s;
	char			*temp2;
	unsigned int	nbr;

	if (flags->precision_present && flags->iszero)
		flags->iszero = 0;
	nbr = va_arg(va, int);
	if (!(temp2 = ft_precision_checker(&nbr, flags)))
		return (NULL);
	if (flags->resisneg && !flags->iszero)
	{
		if (!(s = ft_dominus(flags, &temp2, "-")))
			return (NULL);
	}
	else
	{
		if (!(s = ft_strdup(temp2)))
			return (NULL);
		free(temp2);
	}
	return (s);
}

int
	ft_doi(t_flags *flags, va_list va, int *printed)
{
	char			*s;
	char			*final_char;

	if (!(s = ft_doitwo(flags, va)))
		return (-1);
	if (ft_abs(flags->size) > ft_strlen(s))
	{
		if (ft_addbordertwo(flags, printed, s))
			return (1);
		else
			return (-1);
	}
	if (!(final_char = ft_dominus(flags, &s, "-")))
		return (-1);
	ft_putstr_fd(final_char, 1);
	*printed = *printed + ft_strlen(final_char);
	free(final_char);
	return (1);
}
