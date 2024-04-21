/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flepple <info@florianepple.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:34:14 by flepple           #+#    #+#             */
/*   Updated: 2024/04/19 13:36:41 by flepple          ###   ########.fr       */
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
