/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasnimo <tasnimo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 13:28:22 by username          #+#    #+#             */
/*   Updated: 2026/08/13 14:18:35 by tasnimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
		{
			i++;
		}
	}
	return (words);
}

static char	*ft_word_splitter(const char *s, char c)
{
	char	*word;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	word = (char *) malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < i)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_free_split(char **words, int j)
{
	while (j >= 0)
		free(words[j--]);
	free(words);
	return (NULL);
}

static int	ft_fill_words(char const *s, char c, char **words)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words[j] = ft_word_splitter(&s[i], c);
			if (!words[j])
			{
				ft_free_split(words, j - 1);
				return (-1);
			}
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
		else
			i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		word_count;

	if (!s)
		return (NULL);
	words = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!words)
		return (NULL);
	word_count = ft_fill_words(s, c, words);
	if (word_count == -1)
		return (NULL);
	words[word_count] = NULL;
	return (words);
}
