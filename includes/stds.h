/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stds.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flepple <info@florianepple.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:46:32 by flepple           #+#    #+#             */
/*   Updated: 2024/04/23 19:29:23 by flepple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#ifndef STDS_H
# define STDS_H

// bool

typedef unsigned char	bool_t;

# define FALSE 0x0
# define TRUE 0x1

// line types

typedef unsigned long	line_t;

// functions

int						eb_strlen(char *);
char					*eb_strdup(char *);
int						eb_suitable(char *, char *);
int						eb_isspace(char);
void					eb_putc(char);
void					eb_putstr(char *);
void					eb_putnbr(int);
int						eb_isalpha(char);
int						eb_isprintable(char);

#endif // STDS_H
