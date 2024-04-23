/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flepple <info@florianepple.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:34:14 by flepple           #+#    #+#             */
/*   Updated: 2024/04/23 19:07:57 by flepple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stds.h"

int	eb_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l] != '\0')
		l++;
	return (l);
}

char	*eb_strdup(char *str)
{
	char	*dup;
	int		i;

	dup = (char *)malloc((eb_strlen(str) + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = -1;
	while (str[++i] != '\0')
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}

int	eb_suitable(char *str, char *charset)
{
	int	i;
	int	j;
	int	f;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		f = 0;
		while (charset[j] != '\0')
			if (str[i] == charset[j++])
			{
				f = 1;
				break ;
			}
		if (f == 0)
			return (0);
		i++;
	}
	return (1);
}

int	eb_isspace(char c)
{
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int	eb_isalpha(char c)
{
	if (c >= 'a' && 'z' >= c)
		return (1);
	if (c >= 'A' && 'Z' >= c)
		return (1);
	return (0);
}

int	eb_isprintable(char c)
{
	if (c >= ' ' && '~' >= c)
		return (1);
	return (0);
}

void	eb_putc(char c)
{
	write(1, &c, 1);
}

void	eb_putstr(char *str)
{
	while (*str != '\0')
		eb_putc(*(str++));
}

void	eb_putnbr(int n)
{
	if (n < 0)
	{
		eb_putc('-');
		n = -n;
	}
	if (n / 10 != 0)
	{
		eb_putnbr(n / 10);
	}
	eb_putc(n % 10 + '0');
}
