/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcaborde <tcaborde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:12:28 by tcaborde          #+#    #+#             */
/*   Updated: 2022/12/09 15:11:39 by tcaborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	count_words(char const *s, char c, int w_to_find)
{
	int	i;
	int	word;
	int	toggle;

	i = 0;
	word = 0;
	toggle = 1;
	while (s[i])
	{
		if (s[i] == c)
			toggle = 1;
		if (s[i] != c && toggle == 1)
		{
			toggle = 0;
			word++;
			if (word == w_to_find)
				return (i);
		}
		i++;
	}
	return (word);
}

static char	*assign_words(char const *s, char c, int word)
{
	char	*str;
	int		i;
	int		start_pos;

	start_pos = count_words(s, c, word);
	i = start_pos;
	while (s[i] && s[i] != c)
		i++;
	str = malloc(sizeof(char) * (i - start_pos + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start_pos, i - start_pos + 1);
	return (str);
}

static void	free_tab(char ***tab, int word_number)
{
	int	i;

	i = 0;
	while (i < word_number)
		free(*tab[i++]);
	free(*tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words(s, c, -1) + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < count_words(s, c, -1))
	{
		tab[i] = assign_words(s, c, i + 1);
		if (tab[i] == NULL)
		{
			free_tab(&tab, i);
			return (NULL);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
