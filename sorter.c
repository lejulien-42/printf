/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 20:55:22 by lejulien          #+#    #+#             */
/*   Updated: 2019/12/30 00:31:41 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"

t_flags
	ft_initialize_flags(void)
{
	t_flags flags;

	flags.size = 0;
	flags.iszero = 0;
	flags.isneg = 0;
	flags.precision = 0;
	flags.precision_present = 0;
	flags.type = '\0';
	flags.resisneg = 0;
	return (flags);
}

static int
	ft_doc(t_flags *flags, va_list va, int *printed)
{
	char	c;
	char	*border;
	char	none;

	none = '\0';
	c = va_arg(va, int);
	if (ft_abs(flags->size) > 1)
	{
		if (!(border = ft_addbordertoc(none, flags, ft_abs(flags->size) - 1)))
			return (-1);
		if (!flags->isneg)
			ft_putstr_fd(border, 1);
		ft_putchar_fd(c, 1);
		if (flags->isneg)
			ft_putstr_fd(border, 1);
		*printed = *printed + ft_strlen(border);
		(*printed)++;
		free(border);
		return (1);
	}
	ft_putchar_fd(c, 1);
	(*printed)++;
	return (1);
}

static int
	ft_dos(t_flags *flags, va_list va, int *printed)
{
	char	*s;
	char	*border;
	char	*temp;

	if (!(temp = va_arg(va, char *)))
		temp = "(null)";
	if (ft_precision(flags, &s, temp) == 0)
		return (-1);
	if (ft_abs(flags->size) > (unsigned int)ft_strlen(s) && !flags->iszero)
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

int
	ft_sorter(t_flags *flags, va_list va, int *printed)
{
	if (flags->type == 'c')
		return (ft_doc(flags, va, printed));
	if (flags->type == 's')
		return (ft_dos(flags, va, printed));
	if (flags->type == 'i')
		return (ft_doi(flags, va, printed));
	if (flags->type == 'd')
		return (ft_doi(flags, va, printed));
	if (flags->type == '%')
		return (ft_dopers(flags, printed));
	if (flags->type == 'u')
		return (ft_dou(flags, va, printed));
	if (flags->type == 'x')
		return (ft_dox(flags, va, printed, "0123456789abcdef"));
	if (flags->type == 'X')
		return (ft_dox(flags, va, printed, "0123456789ABCDEF"));
	if (flags->type == 'p')
		return (ft_dop(flags, va, printed, "0123456789abcdef"));
	return (1);
}
