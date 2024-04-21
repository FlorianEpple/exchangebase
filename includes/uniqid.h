/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uniqid.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flepple <info@florianepple.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:34:26 by flepple           #+#    #+#             */
/*   Updated: 2024/04/21 20:50:42 by flepple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#ifndef UNIQID_H
# define UNIQID_H

// def rand seed

# define UNIQID_SRAND_DEF time(NULL)

// charset lib

# define CHARSET_LEGAL "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz$%_-"
# define CHARSET_HEX16 "0123456789ABCDEF"
# define CHARSET_HEX16_LOWER "0123456789abcdef"
# define CHARSET_PASSWORD_LOW "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define CHARSET_PASSWORD_MIDDLE "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
# define CHARSET_PASSWORD_HIGH "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz$%_-"
# define CHARSET_UUID "0123456789abcdef"

// pattern lib

# define PATTERN_UUID "********-****-****-****-************"

// pattern symbol lib

# define PATTERN_SYMBOL_UUID '*'
# define PATTERN_SYMBOL_DEF '*'

// functions

void	set_srand(unsigned int);
char	*uniqid(int, char *);
char	*uid(int);
char	*uniqid_pattern(char *, char *, char);
char	*uuid(char *);

// uniqid macros

# define UID_HX16() uniqid(16, CHARSET_HEX16)
# define UID_HX16L() uniqid(16, CHARSET_HEX16_LOWER)
# define UUID_36() uuid(NULL)

#endif // UNIQID_H
