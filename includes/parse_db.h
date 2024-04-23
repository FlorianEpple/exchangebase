/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_db.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flepple <info@florianepple.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:03:14 by flepple           #+#    #+#             */
/*   Updated: 2024/04/23 19:35:39 by flepple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_DB_H
# define PARSE_DB_H

# include "types.h"

// functions

line_t	db_check_syntax(char *);
void	db_print_syntax_error(char *);

#endif // PARSE_DB_H
