/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:14:32 by asegovia          #+#    #+#             */
/*   Updated: 2019/12/12 14:15:19 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_printf(const char *str, ...)
{
	t_struct	*t;

	if (!(t = malloc(sizeof(t_struct))))
		return (0);
	struct_init(str, t);
	va_start(t->arg, str);
	while (str[t->i] != '\0')
	{
		if (str[t->i] == '%')
			types(t);
		else
		{
			write(1, &str[t->i++], 1);
			t->len++;
		}
	}
	va_end(t->arg);
	free(t);
	return (t->len);
}
