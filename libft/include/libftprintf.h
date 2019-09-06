/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:33:27 by acarcena          #+#    #+#             */
/*   Updated: 2018/11/04 19:32:27 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

/*
** Libs
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "limits.h"
# include "libft.h"

/*
** Flags
*/

# define FLAGS		"-+ #0'"

# define LEFT		0x1
# define SIGN		0x2
# define SPACE		0x4
# define SPECIAL	0x8
# define ZEROPAD	0x10
# define QUOTE		0x20

/*
** Length modifiers
*/

# define LENGTH		"hljz"

# define H			0x1
# define HH			0x2
# define L			0x4
# define LL			0x8
# define J			0x10
# define Z			0x20

/*
** Conversion specifier
*/

# define TYPE		"sSpdDioOuUxXcCnb%"

/*
** Size of the buffer
*/

# define BUFF_SZ	100
# define WDCHAR		4

/*
** Various define
*/

# define BUFFTOA	0x20

# define DIRECTIVES	"hljz-+ #'.0123456789*"

# define DELIMITER	'%'

# define STDOUT		1

# define FT_ERROR	-1

# define SCHAR		1

# define ARGNULL	"(null)"
# define SARGNULL	6

# define PREFBIN	"0b"
# define SPREFBIN	2

# define PREFOCT	"0"
# define SPREFOCT	1

# define PREFHEXMN	"0x"
# define PREFHEXMJ	"0X"
# define SPREFHEX	2

/*
** Structures
*/

typedef struct	s_cwchar
{
	wchar_t		c;
	int			size;
	char		conv[WDCHAR];
}				t_cwchar;

typedef struct	s_swchar
{
	wchar_t		*wcstr;
	char		buff[BUFF_SZ];
	int			size_wc;
	int			len;
	int			id_buff;
}				t_swchar;

typedef struct	s_pref
{
	char		*string;
	int			len_string;
	char		*pref;
	int			len_pref;
}				t_pref;

typedef	struct	s_specs
{
	char		flags;
	int			width;
	int			precision;
	char		lenmod;
	char		type;
}				t_specs;

typedef struct	s_ptf_env
{
	int			fd;
	const char	*format;
	char		buff[BUFF_SZ];
	size_t		index_buff;
	va_list		args;
	size_t		numb_char;
	int			end;
	int			error;
}				t_ptf_env;

/*
** Fonctions
*/

int				check_current_settings(wchar_t wchar);

char			*handle_s_type(t_ptf_env *e, t_specs *ag, int *neg, char *str);
void			handle_unsigned_type(t_ptf_env *env, t_specs *arg, char *str);

void			print_uns(t_ptf_env *env, t_specs *arg, t_pref *conv);
void			allocate_uns_conv(t_specs *arg, char *value, t_pref *conv);

int				ft_wccharlen(wchar_t wchar);
void			handle_wcstring(t_ptf_env *env, t_swchar *inf_wc);
void			handle_wcchar(t_swchar *wc, wchar_t wchar);
int				ft_wclen(wchar_t *wcstr);

void			handle_wchar(t_ptf_env *env, t_specs *arg);

void			handle_percent(t_ptf_env *env, t_specs *arg);
void			handle_string(t_ptf_env *env, t_specs *arg);
void			handle_meter(t_ptf_env *env, t_specs *arg);
void			handle_pointer(t_ptf_env *env, t_specs *arg);
void			handle_char(t_ptf_env *env, t_specs *arg);
void			handle_signed(t_ptf_env *env, t_specs *arg);
void			handle_unsigned(t_ptf_env *env, t_specs *arg);
void			handle_invalid(t_ptf_env *env, t_specs *arg);

void			get_flags(t_ptf_env *utils, t_specs *arg);
void			get_value(t_ptf_env *utils, int *value);
void			get_precision(t_ptf_env *utils, t_specs *arg);
void			get_length_modifier(t_ptf_env *utils, t_specs *arg);
void			get_type(t_ptf_env *utils, t_specs *arg);

void			parse_format(t_ptf_env *utils);

void			ft_flush(t_ptf_env *utils);
void			handle_padding(t_ptf_env *env, char c, size_t len);
void			handle_buffer(t_ptf_env *utl, const char *str, size_t len_str);

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);

#endif
