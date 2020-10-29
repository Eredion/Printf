/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:15:41 by asegovia          #+#    #+#             */
/*   Updated: 2019/12/12 14:52:14 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	printx(t_struct *t)
{
	unsigned int	n;
	char			*str;

	t->i++;
	n = va_arg(t->arg, unsigned int);
	str = ft_itoa_x(n, t);
	t->xflag = 0;
	if (t->dotflag == 1 && *str == '0')
		str = ft_strdup("");
	if (t->wideflag < ft_strlen(str))
		t->wideflag = ft_strlen(str);
	if (t->oflag == 1 && t->dotflag == 1)
		t->dotflag = 0;
	else if (t->oflag == 1 && t->sizeflag > t->wideflag
			&& t->sizeflag > ft_strlen(str))
		t->wideflag = t->sizeflag - t->xflag;
	ft_putstro(str, t);
	free(str);
}

char	*ft_itoa_x(unsigned int value, t_struct *t)
{
	char			*str;
	int				size;
	char			*tab;
	unsigned int	tmp;

	size = 0;
	if (t->xflag == 1)
		tab = "0123456789ABCDEF";
	else
		tab = "0123456789abcdef";
	tmp = value;
	while (tmp /= 16)
		size++;
	size = size + 1;
	str = malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[value % 16];
		size--;
		value /= 16;
	}
	return (str);
}
