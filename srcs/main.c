/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flepple <info@florianepple.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:38:35 by flepple           #+#    #+#             */
/*   Updated: 2024/04/23 19:46:58 by flepple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/types.h"

int	main(void)
{
	int		syntax_err;
	char	filename[] = "test.db";

	syntax_err = db_check_syntax(filename);
	eb_putstr(filename);
	eb_putc('\n');
	if (syntax_err)
		db_print_syntax_error(filename);
	else
		eb_putstr("Success: File syntax is correct.\n");
	return (0);
}
