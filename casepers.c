/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casepers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 01:35:38 by lejulien          #+#    #+#             */
/*   Updated: 2019/12/30 02:14:06 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "./libft/libft.h"

int
	ft_dopers(t_flags *flags, int *printed)
{
	char	c;
	char	*border;

	c = '%';
	if (ft_abs(flags->size) > 1)
	{
		if (!(border = ft_addbordertoc(c, flags, ft_abs(flags->size) - 1)))
			return (-1);
		ft_putstr_fd(border, 1);
		*printed = *printed + ft_strlen(border);
		free(border);
		return (1);
	}
	ft_putchar_fd(c, 1);
	(*printed)++;
	return (1);
}
