/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 02:55:26 by acarcena          #+#    #+#             */
/*   Updated: 2018/10/21 02:55:42 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	conv_wcchar(char *conv, wchar_t wchar, int size)
{
	int index;

	index = 0;
	if (size == 1)
		conv[index++] = wchar;
	else if (size == 2)
	{
		conv[index++] = (wchar >> 6) + 0xC0;
		conv[index++] = (wchar & 0x3F) + 0x80;
	}
	else if (size == 3)
	{
		conv[index++] = (wchar >> 12) + 0xE0;
		conv[index++] = ((wchar >> 6) & 0x3F) + 0x80;
		conv[index++] = (wchar & 0x3F) + 0x80;
	}
	else
	{
		conv[index++] = (wchar >> 18) + 0xF0;
		conv[index++] = ((wchar >> 12) & 0x3F) + 0x80;
		conv[index++] = ((wchar >> 6) & 0x3F) + 0x80;
		conv[index++] = (wchar & 0x3F) + 0x80;
	}
}

static void	handle_wchar_t_char(t_ptf_env *env, t_specs *arg)
{
	t_cwchar	val;

	ft_bzero(&val, sizeof(t_cwchar));
	val.c = va_arg(env->args, wchar_t);
	val.size = ft_wccharlen(val.c);
	if (val.size == -1)
	{
		env->error = -1;
		return ;
	}
	conv_wcchar(val.conv, val.c, val.size);
	if (arg->width <= val.size || (arg->flags & LEFT))
	{
		handle_buffer(env, val.conv, val.size);
		if (arg->width > val.size)
			handle_padding(env, ' ', arg->width - val.size);
	}
	else
	{
		if ((arg->flags & ZEROPAD))
			handle_padding(env, '0', arg->width - val.size);
		else
			handle_padding(env, ' ', arg->width - val.size);
		handle_buffer(env, val.conv, val.size);
	}
}

static void	handle_char_char(t_ptf_env *env, t_specs *arg)
{
	char	c;

	c = va_arg(env->args, int);
	if (arg->width <= SCHAR || (arg->flags & LEFT))
	{
		handle_buffer(env, &c, SCHAR);
		if (arg->width > SCHAR)
			handle_padding(env, ' ', arg->width - SCHAR);
	}
	else
	{
		if ((arg->flags & ZEROPAD))
			handle_padding(env, '0', arg->width - SCHAR);
		else
			handle_padding(env, ' ', arg->width - SCHAR);
		handle_buffer(env, &c, SCHAR);
	}
}

void		handle_char(t_ptf_env *env, t_specs *arg)
{
	if (arg->type == 'C' || arg->lenmod == L)
		handle_wchar_t_char(env, arg);
	else
		handle_char_char(env, arg);
}
