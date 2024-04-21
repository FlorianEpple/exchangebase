/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flepple <info@florianepple.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:58:19 by flepple           #+#    #+#             */
/*   Updated: 2024/04/21 20:48:29 by flepple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file.h"
#include "../includes/types.h"

char	*file_get_line(char *filename, unsigned long line)
{
	int				fd;
	int				i;
	char			buffer[128];
	unsigned long	l;
	ssize_t			bytes;

	if (line == 0)
		return (NULL);
	i = 0;
	l = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	bytes = read(fd, &buffer[i], 1);
	while (bytes > 0 && i + 2 < 128)
	{
		if (buffer[i] == '\n')
		{
			if (++l == line)
			{
				buffer[i] = '\0';
				close(fd);
				return (eb_strdup(buffer));
			}
			i = 0;
		}
		else
			i++;
		bytes = read(fd, &buffer[i], 1);
	}
	close(fd);
	return (NULL);
}
