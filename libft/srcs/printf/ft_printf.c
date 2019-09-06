/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:33:39 by acarcena          #+#    #+#             */
/*   Updated: 2018/06/18 14:33:41 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_dprintf(int fd, const char *format, ...)
{
	t_ptf_env	env;

	if (format == NULL)
		return (-1);
	ft_bzero((t_ptf_env*)&env, sizeof(t_ptf_env));
	va_start(env.args, format);
	env.format = format;
	env.fd = fd;
	parse_format(&env);
	va_end(env.args);
	if (env.error == -1)
		return (-1);
	else
		return (env.numb_char);
}

int			ft_printf(const char *format, ...)
{
	t_ptf_env	env;

	if (format == NULL)
		return (-1);
	ft_bzero((t_ptf_env*)&env, sizeof(t_ptf_env));
	va_start(env.args, format);
	env.format = format;
	env.fd = STDOUT;
	parse_format(&env);
	va_end(env.args);
	if (env.error == -1)
		return (-1);
	else
		return (env.numb_char);
}
