/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drogue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:24:40 by drogue            #+#    #+#             */
/*   Updated: 2020/11/11 19:26:10 by drogue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	number_of_words(char const *s, char c)
{
	int i;
	int n_words;

	i = 0;
	n_words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			i++;
		if (!s[i] && s[i - 1] == c)
			break ;
		n_words++;
	}
	return (n_words);
}

static int	len_word(char **s, char c)
{
	int i;

	i = 0;
	while (**s && **s == c)
		(*s)++;
	while (**s != c && **s)
	{
		(*s)++;
		i++;
	}
	return (i);
}

static void	write_word(char *pi, char const *s, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		pi[i] = s[i];
		i++;
	}
}

static void	*free_pi(char **c)
{
	int i;

	i = 0;
	while (c[i] != NULL)
	{
		free(c[i]);
		i++;
	}
	free(c[i]);
	free(c);
	return (0);
}

char		**ft_split(char const *s, char c)
{
	char	**pi;
	char	*s_copy;
	int		n_words;
	int		n_letter;
	int		i;

	if (!s)
		return (0);
	i = 0;
	s_copy = (char*)s;
	n_words = number_of_words(s, c);
	if (!(pi = malloc(sizeof(char *) * (n_words + 1))))
		return (NULL);
	pi[n_words] = NULL;
	while (i < n_words)
	{
		n_letter = len_word(&s_copy, c);
		if (!(pi[i] = malloc(sizeof(char) * (n_letter + 1))))
			return (free_pi(pi));
		pi[i][n_letter] = '\0';
		write_word(pi[i], s_copy - n_letter, n_letter);
		i++;
	}
	return (pi);
}
