/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cases_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:04:25 by lejulien          #+#    #+#             */
/*   Updated: 2019/12/30 03:56:44 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"

static int
	ft_doptwo(char **s, t_flags *flags, int *printed)
{
	char	*border;

	if (!(border = ft_addborder(*s, flags,
					ft_abs(flags->size) - ft_strlen(*s), 0)))
		return (-1);
	free(*s);
	ft_putstr_fd(border, 1);
	*printed = *printed + ft_strlen(border);
	free(border);
	return (1);
}

char
	*ft_dopthree(t_flags *flags, va_list va, char *hextable)
{
	char	*temp3;
	char	*temp2;
	char	*temp;

	if (!(temp2 = ft_ulltox(va_arg(va, unsigned long long int), hextable)))
		return (NULL);
	if (ft_precision_int(flags, &temp, temp2) == 0)
		return (NULL);
	free(temp2);
	if (temp[0] == '0' && flags->precision_present && flags->precision == 0)
	{
		if (!(temp3 = ft_strdup("")))
			return (NULL);
	}
	else
	{
		if (!(temp3 = ft_strdup(temp)))
			return (NULL);
	}
	free(temp);
	return (temp3);
}

int
	ft_dop(t_flags *flags, va_list va, int *printed, char *hextable)
{
	char	*s;
	char	*temp3;

	if (!(temp3 = ft_dopthree(flags, va, hextable)))
		return (-1);
	if (!(s = ft_strjoin("0x", temp3)))
		return (-1);
	free(temp3);
	if (ft_abs(flags->size) > ft_strlen(s))
	{
		if (ft_doptwo(&s, flags, printed))
			return (1);
		else
			return (-1);
	}
	ft_putstr_fd(s, 1);
	*printed = *printed + ft_strlen(s);
	free(s);
	return (1);
}
