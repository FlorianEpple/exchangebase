/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flepple <info@florianepple.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:38:35 by flepple           #+#    #+#             */
/*   Updated: 2024/04/19 13:40:32 by flepple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/types.h"

int	main(void)
{
	char	*line;

	line = file_get_line("test.db", 1);
	if (line == NULL)
		return (1);
	while (*(line++) != '\0')
		write(1, line, 1);
	write(1, "\n", 1);
	free(line);
	return (0);
}

// int	main(void)
// {
// 	char	*hash;
// 	int		i;
// 	int		j;

// 	set_srand(UNIQID_SRAND_DEF);
// 	j = 0;
// 	while (j++ < 500)
// 	{
// 		hash = UUID_36();
// 		if (hash == NULL)
// 			return (1);
// 		i = 0;
// 		while (hash[i] != '\0')
// 			i++;
// 		write(1, hash, i);
// 		write(1, "\n", 1);
// 		free(hash);
// 	}
// 	return (0);
// }
