/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flepple <info@florianepple.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:38:35 by flepple           #+#    #+#             */
/*   Updated: 2024/04/23 17:02:27 by flepple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/types.h"

int	main(void)
{
	char	*line;
	int		i;
	int		j;

	j = 1;
	line = file_get_line("test.db", j);
	while (line != NULL)
	{
		i = 0;
		while (line[i] != '\0')
			i++;
		write(1, line, i);
		write(1, "\n", 1);
		free(line);
		line = file_get_line("test.db", ++j);
	}
	return (0);
}
