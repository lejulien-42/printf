/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:49:16 by lejulien          #+#    #+#             */
/*   Updated: 2019/12/30 04:35:27 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"

int
	ft_nbrsize(char *format)
{
	int i;

	i = 0;
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}

static void
	ft_dostar(t_flags *flags, va_list va)
{
	int	temp;

	temp = va_arg(va, int);
	if (flags->precision_present == 0)
	{
		if (temp < 0)
			flags->isneg = 1;
		flags->size = temp;
	}
	else
	{
		if (temp < 0)
			flags->precision_present = 0;
		flags->precision = temp;
	}
}

static int
	ft_flagatribtwo(t_flags *flags, char **format, va_list va)
{
	char *size;

	if (**format == '-')
		if (!(flags->isneg))
			flags->isneg = 1;
	if (**format == '0')
		if (!(flags->iszero))
			flags->iszero = 1;
	if (**format != '\0' && **format == '.')
		flags->precision_present = 1;
	if (**format != '\0' && **format == '*')
		ft_dostar(flags, va);
	if (ft_isdigit(**format) && **format != '0')
	{
		if (!(size = ft_substr(*format, 0, ft_nbrsize(*format))))
			return (0);
		if (!flags->size && flags->precision_present == 0)
			flags->size = ft_atoi(size);
		if (!flags->precision && flags->precision_present == 1)
			flags->precision = ft_atoi(size);
		*format = *format + ft_nbrsize(*format) - 1;
		free(size);
	}
	(*format)++;
	return (1);
}

int
	ft_flagatrib(char **format, va_list va, t_flags *flags)
{
	t_flags *tmp;

	(*format)++;
	tmp = flags;
	while (!(ft_isalpha(**format)) && **format != '%' && **format != '\0')
	{
		if (ft_flagatribtwo(flags, format, va) == 0)
			return (0);
	}
	if (**format == '\0' || flags == NULL)
	{
		free(tmp);
		return (0);
	}
	if (ft_isalpha(**format) || **format == '%')
		flags->type = **format;
	(*format)++;
	return (1);
}
