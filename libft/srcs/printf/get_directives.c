/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_directives.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 19:33:47 by acarcena          #+#    #+#             */
/*   Updated: 2018/10/16 19:33:50 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	get_flags(t_ptf_env *env, t_specs *arg)
{
	while (1)
	{
		if (*(env->format) == '-')
			arg->flags |= LEFT;
		else if (*(env->format) == '+')
			arg->flags |= SIGN;
		else if (*(env->format) == ' ')
			arg->flags |= SPACE;
		else if (*(env->format) == '#')
			arg->flags |= SPECIAL;
		else if (*(env->format) == '0')
			arg->flags |= ZEROPAD;
		else if (*(env->format) == '\'')
			arg->flags |= QUOTE;
		else
			break ;
		env->format++;
	}
}

void	get_value(t_ptf_env *env, int *value)
{
	if (ft_isdigit(*(env->format)))
	{
		*value = ft_atoi(env->format);
		while (ft_isdigit(*(env->format)))
			env->format++;
	}
	if (*(env->format) == '*')
	{
		*value = va_arg(env->args, int);
		env->format++;
	}
}

void	get_precision(t_ptf_env *env, t_specs *arg)
{
	if (*(env->format) == '.')
	{
		env->format++;
		arg->precision = 0;
		get_value(env, &(arg->precision));
	}
}

void	get_length_modifier(t_ptf_env *env, t_specs *arg)
{
	if (ft_strchr(LENGTH, *(env->format)) != NULL)
	{
		if (*(env->format) == 'h')
		{
			if (*(env->format + 1) == 'h')
				arg->lenmod |= HH;
			else
				arg->lenmod |= H;
		}
		else if (*(env->format) == 'l')
		{
			if (*(env->format + 1) == 'l')
				arg->lenmod |= LL;
			else
				arg->lenmod |= L;
		}
		else if (*(env->format) == 'j')
			arg->lenmod |= J;
		else if (*(env->format) == 'z')
			arg->lenmod |= Z;
		if (arg->lenmod == HH || arg->lenmod == LL)
			env->format += 2;
		else
			env->format++;
	}
}

void	get_type(t_ptf_env *env, t_specs *arg)
{
	if (ft_strchr(TYPE, *(env->format)) != NULL || ft_isalpha(*(env->format)))
	{
		arg->type = *(env->format);
		env->format++;
	}
}
