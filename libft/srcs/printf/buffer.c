/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 02:52:37 by acarcena          #+#    #+#             */
/*   Updated: 2018/10/25 02:52:55 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_flush(t_ptf_env *env)
{
	write(env->fd, env->buff, env->index_buff);
	ft_bzero(env->buff, BUFF_SZ);
	env->index_buff = 0;
}

void		handle_padding(t_ptf_env *env, char c, size_t len)
{
	char string[BUFF_SZ];

	if (len == 0)
		return ;
	ft_bzero(string, sizeof(char) * BUFF_SZ);
	while (len > BUFF_SZ)
	{
		ft_memset(&string, c, BUFF_SZ);
		handle_buffer(env, (const char*)&string, BUFF_SZ);
		len -= BUFF_SZ;
	}
	ft_memset(&string, c, len);
	handle_buffer(env, (const char*)&string, len);
}

static void	handle_big_string(t_ptf_env *env, const char *str, size_t len_str)
{
	ft_flush(env);
	while (len_str > BUFF_SZ)
	{
		ft_strncpy(env->buff, str, BUFF_SZ);
		str += BUFF_SZ;
		len_str -= BUFF_SZ;
		env->index_buff = BUFF_SZ;
		ft_flush(env);
	}
	ft_strcpy(env->buff, str);
	env->index_buff = len_str;
}

void		handle_buffer(t_ptf_env *env, const char *str, size_t len_str)
{
	if (len_str == 0)
		return ;
	if (len_str <= (BUFF_SZ - env->index_buff))
	{
		ft_strncat(env->buff, str, len_str);
		env->index_buff += len_str;
	}
	else if (len_str <= BUFF_SZ)
	{
		ft_flush(env);
		ft_strncpy(env->buff, str, len_str);
		env->index_buff = len_str;
	}
	else
		handle_big_string(env, str, len_str);
	if (*str == '\0' && len_str == 1)
		ft_flush(env);
	env->numb_char += len_str;
}
