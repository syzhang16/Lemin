/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarcena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:43:01 by acarcena          #+#    #+#             */
/*   Updated: 2017/12/05 14:06:37 by acarcena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int i;
	int words;

	if (!s)
		return (0);
	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			words++;
		i++;
	}
	if (s[0] != c)
		words++;
	return (words);
}

static int	ft_len_word(char const *s, char c)
{
	int len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*ft_sub_word(char const *s, char c, int wrd)
{
	int		i;
	int		count;
	char	*sub_word;

	if (!s)
		return (NULL);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
		{
			sub_word = ft_strsub(s, i, ft_len_word(s, c));
			count++;
		}
		else if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
		{
			if (count == wrd)
				sub_word = ft_strsub(s, (i + 1), ft_len_word((s + i + 1), c));
			count++;
		}
		i++;
	}
	return (sub_word);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		nb_words;
	char	**tab_split;

	if (!s)
		return (NULL);
	i = 0;
	nb_words = ft_count_words(s, c);
	if (!(tab_split = (char**)malloc(sizeof(char*) * (nb_words + 1))))
		return (NULL);
	while (s[i] != '\0' && i < nb_words)
	{
		tab_split[i] = ft_sub_word(s, c, i);
		i++;
	}
	tab_split[i] = NULL;
	return (tab_split);
}
