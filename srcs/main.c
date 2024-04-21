/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flepple <info@florianepple.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:38:35 by flepple           #+#    #+#             */
/*   Updated: 2024/04/21 20:50:48 by flepple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/types.h"

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		j;

// 	j = 1;
// 	line = file_get_line("test.db", j);
// 	while (line != NULL)
// 	{
// 		i = 0;
// 		while (line[i] != '\0')
// 			i++;
// 		write(1, line, i);
// 		write(1, "\n", 1);
// 		free(line);
// 		line = file_get_line("test.db", ++j);
// 	}
// 	return (0);
// }

int	main(void)
{
	char	*hash;
	int		i;
	int		j;

	set_srand(UNIQID_SRAND_DEF);
	j = 0;
	while (j++ < 1)
	{
		hash = UID_HX16L();
		if (hash == NULL)
			return (1);
		i = 0;
		while (hash[i] != '\0')
			i++;
		write(1, hash, i);
		write(1, "\n", 1);
		free(hash);
	}
	return (0);
}
