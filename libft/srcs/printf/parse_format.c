/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:53:28 by acarcena          #+#    #+#             */
/*   Updated: 2018/06/21 14:53:40 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	handle_arg(t_ptf_env *env, t_specs *arg)
{
	if (arg->type == 's' || arg->type == 'S')
		handle_string(env, arg);
	else if (arg->type == 'p')
		handle_pointer(env, arg);
	else if (arg->type == 'c' || arg->type == 'C')
		handle_char(env, arg);
	else if (arg->type == 'd' || arg->type == 'D' || arg->type == 'i')
		handle_signed(env, arg);
	else if (arg->type == 'u' || arg->type == 'U' || arg->type == 'o'
		|| arg->type == 'O' || arg->type == 'x' || arg->type == 'X')
		handle_unsigned(env, arg);
	else if (arg->type == 'n')
		handle_meter(env, arg);
	else if (arg->type == 'b')
		handle_unsigned(env, arg);
	else if (arg->type == '%')
		handle_percent(env, arg);
	else
		handle_invalid(env, arg);
}

static void	handle_conflicts(t_specs *arg)
{
	if ((arg->flags & ZEROPAD) && (arg->flags & LEFT))
		arg->flags &= ~ZEROPAD;
	if ((arg->flags & SPACE) && (arg->flags & SIGN))
		arg->flags &= ~SPACE;
	if ((arg->flags & QUOTE) && (arg->type != 'd' && arg->type != 'D'
		&& arg->type != 'i' && arg->type != 'u' && arg->type != 'U'))
		arg->flags &= ~QUOTE;
	if (arg->width < 0)
	{
		arg->flags |= LEFT;
		arg->width *= -1;
	}
	if (arg->precision < -1)
		arg->precision = -1;
}

static void	get_directives(t_ptf_env *env)
{
	t_specs		arg;

	ft_bzero(&arg, sizeof(t_specs));
	arg.precision = -1;
	while (ft_strchr(DIRECTIVES, *(env->format)) != NULL)
	{
		get_flags(env, &arg);
		get_value(env, &(arg.width));
		get_precision(env, &arg);
		get_length_modifier(env, &arg);
	}
	get_type(env, &arg);
	if (arg.type == 0)
		return ;
	handle_conflicts(&arg);
	handle_arg(env, &arg);
}

void		parse_format(t_ptf_env *env)
{
	char	*result;
	size_t	end_len;

	while (env->end != 1)
	{
		if ((result = ft_strchr(env->format, DELIMITER)) != NULL)
		{
			handle_buffer(env, env->format, (size_t)(result - env->format));
			env->format = result + 1;
			get_directives(env);
			if (env->error == -1)
			{
				ft_flush(env);
				return ;
			}
		}
		else
		{
			end_len = ft_strlen(env->format);
			handle_buffer(env, env->format, end_len);
			env->end = 1;
		}
	}
	ft_flush(env);
}
