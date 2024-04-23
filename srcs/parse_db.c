/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_db.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flepple <info@florianepple.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:03:10 by flepple           #+#    #+#             */
/*   Updated: 2024/04/23 19:49:22 by flepple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/types.h"

bool_t	db_line_is_descriptor(char *line)
{
	int	i;

	i = 0;
	while (eb_isspace(line[i]) && line[i] != '\0')
		i++;
	if (line[i] != '[')
		return (FALSE);
	while (!eb_isspace(line[i]) && line[i] != '\0' && line[i] != ']')
		i++;
	if (line[i] == ']')
		return (TRUE);
	return (FALSE);
}

bool_t	db_line_is_assigner(char *line)
{
	int	i;

	i = 0;
	while (eb_isspace(line[i]) && line[i] != '\0')
		i++;
	while (eb_isalpha(line[i]))
		i++;
	while (eb_isspace(line[i]) && line[i] != '\0')
		i++;
	if (line[i] != '=')
		return (FALSE);
	while (eb_isspace(line[i]) && line[i] != '\0')
		i++;
	while (eb_isprintable(line[i]))
		i++;
	while (eb_isspace(line[i]) && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (TRUE);
	return (FALSE);
}

line_t	db_check_syntax(char *filename)
{
	char	*line;
	int		i;

	i = 1;
	line = file_get_line(filename, i);
	while (line != NULL)
	{
		if (!(db_line_is_descriptor(line) || db_line_is_assigner(line)))
		{
			free(line);
			return (i);
		}
		free(line);
		line = file_get_line(filename, ++i);
	}
	return (0);
}

void	db_print_syntax_error(char *filename)
{
	int		err;
	char	*line;

	err = db_check_syntax(filename);
	eb_putstr("Syntax: There was an Error in test.db on line ");
	eb_putnbr(err);
	eb_putstr(".\n");
	line = file_get_line(filename, err);
	eb_putc('(');
	eb_putnbr(err);
	eb_putstr(")--> ");
	eb_putstr(line);
	eb_putstr("\n\n");
	free(line);
}
