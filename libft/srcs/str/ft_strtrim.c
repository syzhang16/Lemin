/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 03:48:38 by acarcena          #+#    #+#             */
/*   Updated: 2017/12/04 20:59:05 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_trim(char const *s)
{
	size_t	i;
	size_t	spaces;
	size_t	len;
	size_t	j;

	i = 0;
	spaces = 0;
	len = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
		spaces++;
		if (spaces == len)
			return (0);
	}
	j = len - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
	{
		j--;
		spaces++;
	}
	return (len - spaces);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len_trim;
	size_t	start;
	char	*trim;

	if (!s)
		return (0);
	i = 0;
	len_trim = ft_len_trim(s);
	if (!(trim = (char *)malloc(sizeof(char) * (len_trim + 1))))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	start = i;
	while ((i - start) < len_trim && s[i] != '\0')
	{
		trim[i - start] = s[i];
		i++;
	}
	trim[len_trim] = '\0';
	return (trim);
}
