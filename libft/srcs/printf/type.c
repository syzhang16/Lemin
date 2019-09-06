/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 01:03:28 by acarcena          #+#    #+#             */
/*   Updated: 2018/10/26 01:03:30 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_unsigned_type(t_ptf_env *env, t_specs *arg, char *str)
{
	unsigned long	value;

	if (arg->lenmod == L || arg->type == 'O' || arg->type == 'U')
		value = (unsigned long)va_arg(env->args, unsigned long);
	else if (arg->lenmod == HH)
		value = (unsigned char)va_arg(env->args, int);
	else if (arg->lenmod == H)
		value = (unsigned short)va_arg(env->args, int);
	else if (arg->lenmod == LL)
		value = (unsigned long long)va_arg(env->args, unsigned long long);
	else if (arg->lenmod == J)
		value = (uintmax_t)va_arg(env->args, uintmax_t);
	else if (arg->lenmod == Z)
		value = (size_t)va_arg(env->args, size_t);
	else
		value = (unsigned int)va_arg(env->args, unsigned int);
	if (arg->type == 'o' || arg->type == 'O')
		ft_ultoa_base_buff(value, 8, str);
	else if (arg->type == 'x' || arg->type == 'X')
		ft_ultoa_base_buff(value, 16, str);
	else if (arg->type == 'u' || arg->type == 'U')
		ft_ultoa_base_buff(value, 10, str);
	else
		ft_ultoa_base_buff(value, 2, str);
}

char	*handle_s_type(t_ptf_env *env, t_specs *arg, int *neg, char *str)
{
	long	value;

	if (arg->lenmod == Z)
		value = (long)va_arg(env->args, long);
	else if (arg->lenmod == J)
		value = (intmax_t)va_arg(env->args, uintmax_t);
	else if (arg->lenmod == LL)
		value = (long long)va_arg(env->args, unsigned long long);
	else if (arg->lenmod == L || arg->type == 'D')
		value = (long)va_arg(env->args, unsigned long);
	else if (arg->lenmod == H)
		value = (short)va_arg(env->args, int);
	else if (arg->lenmod == HH)
		value = (char)va_arg(env->args, int);
	else
		value = (int)va_arg(env->args, int);
	if (value < 0)
		*neg = 1;
	ft_ltoa_base_buff(value, 10, str);
	return (str);
}
