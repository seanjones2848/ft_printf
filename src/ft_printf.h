/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjones <sjones@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:00:58 by sjones            #+#    #+#             */
/*   Updated: 2018/01/01 18:18:49 by sjones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>

typedef union
{
	char		c;
	char		*s;
	intmax_t	i;
	uintmax_t	u;
	void		*v;
}				t_types;

typedef struct	s_print
{
	bool		hash;
	bool		zero;
	bool		plus;
	bool		minus;
	bool		space;
	int			width;
	int			prec;
	char		type;
	char		*l_mod;
	va_list		args;
	t_types		arg;
	char		*fmt;
	char		*num;
	char		sign;
	int			spaces;
	int			zeroes;
	int			len;
	int			ret;
	int			fd;
	int			i;
}				t_print;

/*
** printf types
*/

int				ft_printf(const char *fmt, ...);
int				ft_fprintf(int fd, const char *fmt, ...);

/*
** printf meat
*/

void			init_print(t_print *p, int fd, char *fmt);
void			printf_meat(t_print *p);
void			arg_handle(t_print *p);
void			get_flags(t_print *p);
void			get_prec(t_print *p);
void			get_width(t_print *p);
void			get_length(t_print *p);
void			convert(t_print *p);
void			unconvert(t_print *p);
void			reset(t_print *p);
void			print_char(t_print *p, char c, int t);
void			print_num(t_print *p);
int				is_flag(char c);
int				is_type(char c);
int				is_length(char c);

/*
** formaters
*/

void			charify(t_print *p);
void			stringify(t_print *p);
void			octalfy(t_print *p);
void			decimalfy(t_print *p);
void			undecimalfy(t_print *p);
void			hexify(t_print *p);
void			pointerfy(t_print *p);

/*
** error
*/

int				is_error(char c);
void			get_error(t_print *p);

/*
** Debug functions
*/

void			print_all(t_print *p);

#endif
