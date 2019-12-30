/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caseu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 01:29:47 by lejulien          #+#    #+#             */
/*   Updated: 2019/12/30 01:33:11 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "./libft/libft.h"

static char
	*ft_doutwo(t_flags *flags, va_list va)
{
	char	*temp;
	char	*temp2;
	char	*s;

	if (flags->iszero && flags->precision_present)
		flags->iszero = 0;
	if (!(temp = ft_uitoa(va_arg(va, unsigned int))))
		return (NULL);
	if (flags->precision_present && !flags->precision && atoi(temp) == 0)
		temp2 = ft_strdup("");
	else
		temp2 = ft_strdup(temp);
	free(temp);
	if (ft_precision_int(flags, &s, temp2) == 0)
		return (NULL);
	free(temp2);
	return (s);
}

int
	ft_dou(t_flags *flags, va_list va, int *printed)
{
	char	*s;
	char	*border;

	if (!(s = ft_doutwo(flags, va)))
		return (-1);
	if (ft_abs(flags->size) > ft_strlen(s))
	{
		if (!(border = ft_addborder(s, flags,
						ft_abs(flags->size) - ft_strlen(s), 0)))
			return (-1);
		free(s);
		ft_putstr_fd(border, 1);
		*printed = *printed + ft_strlen(border);
		free(border);
		return (1);
	}
	ft_putstr_fd(s, 1);
	*printed = *printed + ft_strlen(s);
	free(s);
	return (1);
}
