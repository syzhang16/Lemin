/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 02:55:48 by acarcena          #+#    #+#             */
/*   Updated: 2018/10/21 02:55:59 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	print_sig_right(t_ptf_env *env, t_specs *arg, t_pref conv, int len)
{
	if (arg->width > len && (arg->flags & ZEROPAD))
	{
		handle_buffer(env, conv.pref, conv.len_pref);
		handle_padding(env, '0', arg->width - len);
	}
	else if (arg->width > len)
		handle_padding(env, ' ', arg->width - len);
	if (!(arg->flags & ZEROPAD))
		handle_buffer(env, conv.pref, conv.len_pref);
	if (arg->precision > conv.len_string)
		handle_padding(env, '0', len - conv.len_string - conv.len_pref);
	handle_buffer(env, conv.string, conv.len_string);
}

static void	print_signed(t_ptf_env *env, t_specs *arg, t_pref conv)
{
	int len;

	if (arg->precision > conv.len_string)
		len = arg->precision;
	else
		len = conv.len_string;
	if (conv.len_pref != 0)
		len += conv.len_pref;
	if (arg->width <= len || (arg->flags & LEFT))
	{
		handle_buffer(env, conv.pref, conv.len_pref);
		handle_padding(env, '0', len - conv.len_string - conv.len_pref);
		handle_buffer(env, conv.string, conv.len_string);
		if (arg->width > len)
			handle_padding(env, ' ', arg->width - len);
	}
	else
		print_sig_right(env, arg, conv, len);
}

static void	allocate_s_conv(t_specs *arg, char *value, t_pref *conv, int neg)
{
	if (!(*value == '0' && arg->precision == 0))
	{
		conv->string = value;
		conv->len_string = ft_strlen(value);
	}
	if (neg == 1)
	{
		conv->pref = "-";
		conv->len_pref = 1;
		conv->string += 1;
		conv->len_string -= 1;
	}
	else if ((arg->flags & SIGN) && neg == 0)
	{
		conv->pref = "+";
		conv->len_pref = 1;
	}
	else if ((arg->flags & SPACE) && neg == 0)
	{
		conv->pref = " ";
		conv->len_pref = 1;
	}
}

void		handle_signed(t_ptf_env *env, t_specs *arg)
{
	char	str[BUFFTOA];
	t_pref	conv;
	int		negative;

	negative = 0;
	handle_s_type(env, arg, &negative, str);
	if (arg->precision != -1 && (arg->flags & ZEROPAD))
		arg->flags &= ~(ZEROPAD);
	ft_bzero(&conv, sizeof(t_pref));
	allocate_s_conv(arg, str, &conv, negative);
	print_signed(env, arg, conv);
}
