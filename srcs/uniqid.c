/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniqid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flepple <info@florianepple.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:11:09 by flepple           #+#    #+#             */
/*   Updated: 2024/04/23 17:25:48 by flepple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/types.h"
#include "../includes/uniqid.h"

char	rnd_c(char *charset)
{
	int	rnd;

	rnd = rand() % (eb_strlen(charset) - 1);
	return (charset[rnd]);
}

void	set_srand(unsigned int seed)
{
	srand(seed);
}

char	*uniqid(int n, char *charset)
{
	char	*res;

	if (eb_suitable(charset, CHARSET_LEGAL) == 0)
		return (NULL);
	res = (char *)malloc((n + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[n] = '\0';
	while (n-- >= 0)
		res[n] = rnd_c(charset);
	return (res);
}

char	*uid(int n)
{
	char	*res;

	res = uniqid(n, CHARSET_HEX16);
	return (res);
}

char	*uniqid_pattern(char *charset, char *pattern, char symbol)
{
	char	*res;
	int		l;
	int		i;

	if (eb_suitable(charset, CHARSET_LEGAL) == 0)
		return (NULL);
	l = 0;
	i = 0;
	while (eb_isspace(pattern[i]) == 1 && pattern[i] != '\0')
		i++;
	while (eb_isspace(pattern[i]) == 0 && pattern[i] != '\0')
	{
		l++;
		i++;
	}
	res = malloc((l + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	l = 0;
	i = 0;
	while (eb_isspace(pattern[i]) == 1 && pattern[i] != '\0')
		i++;
	while (eb_isspace(pattern[i]) == 0 && pattern[i] != '\0')
	{
		if (pattern[i] == symbol)
			res[l++] = rnd_c(charset);
		else
			res[l++] = pattern[i];
		i++;
	}
	return (res);
}

char	*uuid(char *prefix)
{
	char	*res;
	char	*pattern;
	int		i;
	int		j;

	if (prefix == NULL)
		return (uniqid_pattern(CHARSET_UUID, PATTERN_UUID,
				PATTERN_SYMBOL_UUID));
	if (eb_suitable(prefix, CHARSET_UUID) == 0)
		return (NULL);
	pattern = eb_strdup(PATTERN_UUID);
	if (pattern == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (pattern[i] != '\0' && prefix[j] != '\0')
	{
		if (pattern[i] == PATTERN_SYMBOL_UUID)
			pattern[i] = prefix[j++];
		i++;
	}
	res = uniqid_pattern(CHARSET_UUID, pattern, PATTERN_SYMBOL_UUID);
	free(pattern);
	return (res);
}
