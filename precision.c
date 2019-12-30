/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 04:11:02 by lejulien          #+#    #+#             */
/*   Updated: 2019/12/30 04:15:41 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"

int
	ft_precision(t_flags *flags, char **s, char *temp)
{
	if (flags->precision_present &&
			ft_abs(flags->precision) < ft_strlen(temp))
	{
		if (!(*s = ft_substr(temp, 0, ft_abs(flags->precision))))
			return (0);
	}
	else
	{
		if (!(*s = ft_strdup(temp)))
			return (0);
	}
	return (1);
}

int
	ft_precision_int(t_flags *flags, char **s, char *temp)
{
	if (flags->precision_present &&
			ft_abs(flags->precision) > (unsigned int)ft_strlen(temp))
	{
		if (!(*s = ft_addborder_int(temp,
						flags->precision - (unsigned int)ft_strlen(temp))))
			return (0);
	}
	else
	{
		if (!(*s = ft_strdup(temp)))
			return (0);
	}
	return (1);
}
