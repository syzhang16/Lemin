/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 02:52:51 by acarcena          #+#    #+#             */
/*   Updated: 2018/10/21 02:54:31 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	handle_nb_wchar_len(t_swchar *inf_wc, wchar_t *wcstr)
{
	int len;
	int value;

	len = 0;
	if (!wcstr)
		return ;
	while (*wcstr)
	{
		value = ft_wccharlen(*wcstr);
		if (len + value <= inf_wc->len)
			len += value;
		else
			break ;
		wcstr++;
	}
	inf_wc->len = len;
}

static void	print_wchar_t_string(t_ptf_env *env, t_specs *arg, t_swchar inf_wc)
{
	if (arg->width <= inf_wc.len || (arg->flags & LEFT))
	{
		handle_wcstring(env, &inf_wc);
		if (arg->width > inf_wc.len)
			handle_padding(env, ' ', arg->width - inf_wc.len);
	}
	else
	{
		if (arg->flags & ZEROPAD)
			handle_padding(env, '0', arg->width - inf_wc.len);
		else
			handle_padding(env, ' ', arg->width - inf_wc.len);
		handle_wcstring(env, &inf_wc);
	}
}

static void	handle_wchar_t_string(t_ptf_env *env, t_specs *arg)
{
	t_swchar	inf_wc;

	ft_bzero(&inf_wc, sizeof(t_swchar));
	inf_wc.wcstr = va_arg(env->args, wchar_t*);
	if (inf_wc.wcstr == NULL)
		inf_wc.len = SARGNULL;
	else
		inf_wc.len = ft_wclen(inf_wc.wcstr);
	if (inf_wc.len == -1)
	{
		env->error = -1;
		return ;
	}
	if (arg->precision < inf_wc.len && arg->precision >= 0)
		inf_wc.len = arg->precision;
	handle_nb_wchar_len(&inf_wc, inf_wc.wcstr);
	print_wchar_t_string(env, arg, inf_wc);
}

static void	handle_char_string(t_ptf_env *env, t_specs *arg)
{
	char	*string;
	int		len;

	string = va_arg(env->args, char*);
	if (string == NULL)
		string = ARGNULL;
	len = ft_strlen(string);
	if (arg->precision < len && arg->precision >= 0)
		len = arg->precision;
	if (arg->width <= len || (arg->flags & LEFT))
	{
		handle_buffer(env, string, len);
		if (arg->width > len)
			handle_padding(env, ' ', arg->width - len);
	}
	else
	{
		if (arg->flags & ZEROPAD)
			handle_padding(env, '0', arg->width - len);
		else
			handle_padding(env, ' ', arg->width - len);
		handle_buffer(env, string, len);
	}
}

void		handle_string(t_ptf_env *env, t_specs *arg)
{
	if (arg->type == 'S' || arg->lenmod == L)
		handle_wchar_t_string(env, arg);
	else
		handle_char_string(env, arg);
}
