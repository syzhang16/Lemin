/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 02:55:26 by acarcena          #+#    #+#             */
/*   Updated: 2018/10/21 02:55:42 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		check_current_settings(wchar_t wchar)
{
	if (MB_CUR_MAX == 1 && wchar > 0xFF)
		return (-1);
	else if (MB_CUR_MAX == 2 && wchar > 0xFFFF)
		return (-1);
	else if (MB_CUR_MAX == 3 && wchar > 0xFFFFFF)
		return (-1);
	else
		return (0);
}

int		ft_wccharlen(wchar_t wchar)
{
	if (check_current_settings(wchar) == -1)
		return (-1);
	else if (wchar <= 0x7f)
		return (1);
	else if (wchar <= 0x7ff)
		return (2);
	else if (wchar <= 0xffff)
		return (3);
	else
		return (4);
}

int		ft_wclen(wchar_t *wcstr)
{
	int len;
	int value;

	len = 0;
	if (!wcstr)
		return (0);
	while (*(wcstr))
	{
		value = ft_wccharlen(*wcstr);
		if (value == -1)
			return (-1);
		len += value;
		wcstr++;
	}
	return (len);
}

void	handle_wcchar(t_swchar *wc, wchar_t wchar)
{
	if (wc->size_wc == 1)
		wc->buff[wc->id_buff++] = wchar;
	else if (wc->size_wc == 2)
	{
		wc->buff[wc->id_buff++] = (wchar >> 6) + 0xC0;
		wc->buff[wc->id_buff++] = (wchar & 0x3F) + 0x80;
	}
	else if (wc->size_wc == 3)
	{
		wc->buff[wc->id_buff++] = (wchar >> 12) + 0xE0;
		wc->buff[wc->id_buff++] = ((wchar >> 6) & 0x3F) + 0x80;
		wc->buff[wc->id_buff++] = (wchar & 0x3F) + 0x80;
	}
	else
	{
		wc->buff[wc->id_buff++] = (wchar >> 18) + 0xF0;
		wc->buff[wc->id_buff++] = ((wchar >> 12) & 0x3F) + 0x80;
		wc->buff[wc->id_buff++] = ((wchar >> 6) & 0x3F) + 0x80;
		wc->buff[wc->id_buff++] = (wchar & 0x3F) + 0x80;
	}
}

void	handle_wcstring(t_ptf_env *env, t_swchar *inf_wc)
{
	if (inf_wc->wcstr == NULL)
	{
		handle_buffer(env, ARGNULL, inf_wc->len);
		return ;
	}
	inf_wc->size_wc = ft_wccharlen(*(inf_wc->wcstr));
	while (inf_wc->id_buff + inf_wc->size_wc <= inf_wc->len)
	{
		inf_wc->size_wc = ft_wccharlen(*(inf_wc->wcstr));
		if ((inf_wc->id_buff + inf_wc->size_wc) > BUFF_SZ)
		{
			handle_buffer(env, inf_wc->buff, inf_wc->id_buff);
			ft_bzero(inf_wc->buff, inf_wc->id_buff);
			inf_wc->len -= inf_wc->id_buff;
			inf_wc->id_buff = 0;
		}
		handle_wcchar(inf_wc, *inf_wc->wcstr);
		inf_wc->wcstr++;
	}
	handle_buffer(env, inf_wc->buff, inf_wc->id_buff);
}
