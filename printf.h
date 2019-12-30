/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 22:22:04 by lejulien          #+#    #+#             */
/*   Updated: 2019/12/30 01:37:16 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_flags
{
	int		size;
	int		iszero;
	int		isneg;
	int		precision;
	int		precision_present;
	char	type;
	int		resisneg;
}				t_flags;

int				ft_printf(const char *format, ...);
int				ft_nbrsize(char *format);
char			*ft_addchar(char *str, char c, int way);
char			*ft_itox(unsigned int x, char *hextable);
char			*ft_ulltox(unsigned long long int x, char *hextable);
char			*ft_addborder(char *str, t_flags *flags, int size, int isint);
char			*ft_addbordertoc(char c, t_flags *flags, int size);
int				ft_flagatrib(char **format, va_list va, t_flags *flags);
t_flags			ft_initialize_flags(void);
int				ft_sorter(t_flags *flags, va_list va, int *printed);
unsigned int	ft_abs(int i);
int				ft_precision(t_flags *flags, char **s, char *temp);
int				ft_doi(t_flags *flags, va_list va, int *printed);
int				ft_dou(t_flags *flags, va_list va, int *printed);
int				ft_dox(t_flags *flags, va_list va, int *printed,
		char *hextable);
int				ft_dop(t_flags *flags, va_list va, int *printed,
		char *hextable);
int				ft_dopers(t_flags *flags, int *printed);
char			*ft_addborder_int(char *temp, int size);
int				ft_precision_int(t_flags *flags, char **s, char *temp);
int				ft_doi(t_flags *flags, va_list va, int *printed);
int				ft_addbordertwo(t_flags *flags, int *printed, char *s);
char			*ft_precision_checker(int unsigned *nbr, t_flags *flags);
char			*ft_dominus(t_flags *flags, char **temp, char *c);
int				ft_dou(t_flags *flags, va_list va, int *printed);
int				ft_dopers(t_flags *flags, int *printed);
#endif
