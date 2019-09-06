/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 02:54:56 by acarcena          #+#    #+#             */
/*   Updated: 2018/10/25 02:54:58 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		handle_invalid(t_ptf_env *env, t_specs *arg)
{
	int	len;

	len = 1;
	if (arg->width <= len || (arg->flags & LEFT))
	{
		handle_buffer(env, &arg->type, len);
		if (arg->width > len)
			handle_padding(env, ' ', arg->width - len);
	}
	else
	{
		if (arg->width > len && (arg->flags & ZEROPAD))
			handle_padding(env, '0', arg->width - len);
		else if (arg->width > len)
			handle_padding(env, ' ', arg->width - len);
		handle_buffer(env, &arg->type, len);
	}
}

static void	handle_null_ptr(t_ptf_env *env, t_specs *arg)
{
	int len;

	if (arg->precision != -1)
		len = arg->precision + SPREFHEX;
	else if ((arg->flags & ZEROPAD) && arg->width > SPREFHEX + 1)
		len = arg->width;
	else
		len = 1 + SPREFHEX;
	if (arg->width <= len || (arg->flags & LEFT))
	{
		handle_buffer(env, PREFHEXMN, SPREFHEX);
		handle_padding(env, '0', len - SPREFHEX);
		if (arg->width > len)
			handle_padding(env, ' ', arg->width - len);
	}
	else
	{
		handle_padding(env, ' ', arg->width - len);
		handle_buffer(env, PREFHEXMN, SPREFHEX);
		handle_padding(env, '0', len - SPREFHEX);
	}
}

void		handle_pointer(t_ptf_env *env, t_specs *arg)
{
	void	*pointer;
	char	address[BUFFTOA];
	t_pref	conv;

	pointer = va_arg(env->args, void*);
	ft_ultoa_base_buff((unsigned long)pointer, 16, address);
	if (arg->precision != -1 && (arg->flags & ZEROPAD))
		arg->flags &= ~(ZEROPAD);
	if (pointer != NULL)
	{
		arg->flags |= SPECIAL;
		arg->type = 'x';
		ft_bzero(&conv, sizeof(t_pref));
		allocate_uns_conv(arg, address, &conv);
		print_uns(env, arg, &conv);
	}
	else
		handle_null_ptr(env, arg);
}

void		handle_percent(t_ptf_env *env, t_specs *arg)
{
	if (arg->width <= 1 || (arg->flags & LEFT))
	{
		handle_buffer(env, "%", 1);
		if (arg->width > 1)
			handle_padding(env, ' ', arg->width - 1);
	}
	else
	{
		if ((arg->flags & ZEROPAD))
			handle_padding(env, '0', arg->width - 1);
		else
			handle_padding(env, ' ', arg->width - 1);
		handle_buffer(env, "%", 1);
	}
}

void		handle_meter(t_ptf_env *env, t_specs *arg)
{
	int		*int_meter;
	size_t	*long_meter;

	int_meter = 0;
	long_meter = 0;
	if (arg->lenmod == 'z')
	{
		long_meter = va_arg(env->args, size_t*);
		*long_meter = (size_t)env->numb_char;
	}
	else
	{
		int_meter = va_arg(env->args, int*);
		*int_meter = (int)env->numb_char;
	}
}
