/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabelo- <arabelo-@Student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:57:19 by arabelo-          #+#    #+#             */
/*   Updated: 2023/03/23 12:41:07 by arabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	has_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_strings(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && has_separator(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !has_separator(str[i], charset))
			i++;
	}
	return (count);
}

int	ft_strlen_sep(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !has_separator(str[i], charset))
		i++;
	return (i);
}

char	*ft_word(char *str, char *charset)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = ft_strlen_sep(str, charset);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**strings;
	int		i;

	i = 0;
	strings = (char **)malloc(sizeof(char *)
			* (count_strings(str, charset) + 1));
	while (*str)
	{
		while (*str && has_separator(*str, charset))
			str++;
		if (*str)
		{
			strings[i] = ft_word(str, charset);
			i++;
		}
		while (*str && !has_separator(*str, charset))
			str++;
	}
	strings[i] = 0;
	return (strings);
}

/*#include <stdio.h>

int main()
{
    char *str = "The quick brown fox jumps over the lazy dog";
    char *charset = " ";
    char **result = ft_split(str, charset);

    for (int i = 0; result[i]; i++) {
        printf("%s\n", result[i]);
    }

    return 0;
}*/
