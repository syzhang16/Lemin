/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 01:03:28 by acarcena          #+#    #+#             */
/*   Updated: 2018/10/26 01:03:30 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	print_uns_right(t_ptf_env *env, t_specs *arg, t_pref *conv, int len)
{
	if (arg->width > len && (arg->flags & ZEROPAD) && (arg->flags & SPECIAL))
		handle_buffer(env, conv->pref, conv->len_pref);
	if (arg->width > len && (arg->flags & ZEROPAD))
		handle_padding(env, '0', arg->width - len);
	else if (arg->width > len)
		handle_padding(env, ' ', arg->width - len);
	if ((arg->flags & SPECIAL) && !(arg->flags & ZEROPAD))
		handle_buffer(env, conv->pref, conv->len_pref);
	if (arg->precision > conv->len_string && (arg->flags & SPECIAL))
		handle_padding(env, '0', len - conv->len_string - conv->len_pref);
	else if (arg->precision > conv->len_string)
		handle_padding(env, '0', len - conv->len_string);
	handle_buffer(env, conv->string, conv->len_string);
}

void		print_uns(t_ptf_env *env, t_specs *arg, t_pref *conv)
{
	int len;

	if (arg->precision > conv->len_string)
		len = arg->precision;
	else
		len = conv->len_string;
	if (arg->flags & SPECIAL)
		len += conv->len_pref;
	if (arg->width <= len || (arg->flags & LEFT))
	{
		if ((arg->flags & SPECIAL))
			handle_buffer(env, conv->pref, conv->len_pref);
		if (arg->precision > conv->len_string && (arg->flags & SPECIAL))
			handle_padding(env, '0', len - conv->len_string - conv->len_pref);
		else if (arg->precision > conv->len_string)
			handle_padding(env, '0', len - conv->len_string);
		handle_buffer(env, conv->string, conv->len_string);
		if (arg->width > len)
			handle_padding(env, ' ', arg->width - len);
	}
	else
		print_uns_right(env, arg, conv, len);
}

static void	print_uns_zero(t_ptf_env *env, t_specs *arg)
{
	int len;

	len = 0;
	if (arg->precision > 0)
		len = arg->precision;
	else if (arg->precision == -1 || (len == 0 && (arg->flags & SPECIAL)
		&& (arg->type == 'o' || arg->type == 'O')))
		len = 1;
	else
		len = 0;
	if (arg->width <= len || (arg->flags & LEFT))
	{
		handle_padding(env, '0', len);
		if (arg->width > len)
			handle_padding(env, ' ', arg->width - len);
	}
	else
	{
		if (arg->width > len && (arg->flags & ZEROPAD))
			handle_padding(env, '0', arg->width - len);
		else if (arg->width > len)
			handle_padding(env, ' ', arg->width - len);
		handle_padding(env, '0', len);
	}
}

void		allocate_uns_conv(t_specs *arg, char *value, t_pref *conv)
{
	conv->string = value;
	conv->len_string = ft_strlen(value);
	if (arg->type == 'X')
		ft_strtoupper(conv->string);
	if (arg->type == 'o' || arg->type == 'O')
	{
		conv->pref = PREFOCT;
		conv->len_pref = SPREFOCT;
	}
	else if (arg->type == 'x' || arg->type == 'X' || arg->type == 'b'
		|| arg->type == 'p')
	{
		if (arg->type == 'x' || arg->type == 'p')
			conv->pref = PREFHEXMN;
		else if (arg->type == 'X')
			conv->pref = PREFHEXMJ;
		else
			conv->pref = PREFBIN;
		conv->len_pref = SPREFHEX;
	}
}

void		handle_unsigned(t_ptf_env *env, t_specs *arg)
{
	int		len_s;
	t_pref	conv;
	char	str[BUFFTOA];

	handle_unsigned_type(env, arg, str);
	len_s = ft_strlen(str);
	if (arg->precision != -1 && (arg->flags & ZEROPAD))
		arg->flags &= ~(ZEROPAD);
	if ((arg->type == 'o' || arg->type == 'O') && (arg->flags & SPECIAL)
		&& ((arg->precision >= len_s + SPREFOCT) || (arg->flags & ZEROPAD)))
		arg->flags &= ~(SPECIAL);
	if (*str == '0')
	{
		print_uns_zero(env, arg);
		return ;
	}
	ft_bzero(&conv, sizeof(t_pref));
	allocate_uns_conv(arg, str, &conv);
	print_uns(env, arg, &conv);
}
