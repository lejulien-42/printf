/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 01:04:40 by lejulien          #+#    #+#             */
/*   Updated: 2019/12/30 05:02:58 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"

static int
	ft_noflagsize(char *format)
{
	int		i;

	i = 0;
	while (*format != '%' && *format != '\0')
	{
		i++;
		format++;
	}
	return (i);
}

static int
	ft_printftwo(char **format, int *printed)
{
	int		temp;
	char	*toprint;

	temp = 0;
	temp = ft_noflagsize(*format);
	if (!(toprint = ft_substr(*format, 0, temp)))
		return (0);
	ft_putstr_fd(toprint, 1);
	free(toprint);
	*format = *format + temp;
	*printed = *printed + temp;
	return (1);
}

static int
	ft_flagadsort(t_flags *flags, va_list va, char **res, int *printed)
{
	if (!ft_flagatrib(res, va, flags))
		return (0);
	if (!ft_sorter(flags, va, printed))
		return (0);
	return (1);
}

int
	ft_printf(const char *format, ...)
{
	va_list	va;
	t_flags	flags;
	char	*res;
	int		printed;

	res = (char *)format;
	va_start(va, format);
	printed = 0;
	while (*res)
	{
		flags = ft_initialize_flags();
		if (*res == '%')
		{
			if (!(ft_flagadsort(&flags, va, &res, &printed)))
				return (-1);
		}
		else if (*res != '\0')
		{
			if (!(ft_printftwo(&res, &printed)))
				return (-1);
		}
	}
	va_end(va);
	return (printed);
}
