/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:05:41 by asegovia          #+#    #+#             */
/*   Updated: 2019/12/12 14:22:58 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr(char *str, t_struct *t)
{
	if (t->wideflag >= 0)
	{
		while (*str != '\0' && t->wideflag > 0)
		{
			write(1, &*str, 1);
			str++;
			t->wideflag--;
			t->len++;
		}
	}
	else
	{
		while (*str != '\0')
		{
			write(1, &*str, 1);
			str++;
			t->len++;
		}
	}
}

void	ft_putnstr(char *str, t_struct *t)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && i < t->sizeflag)
	{
		write(1, &str[i], 1);
		i++;
		t->len++;
	}
}

void	ft_putsstr(char *str, t_struct *t)
{
	int		i;
	char	c;

	c = ' ';
	if (t->minusflag == 0 && t->oflag == 1)
		c = '0';
	i = t->sizeflag - ft_strlen(str);
	if (t->dotflag == 1 && ft_strlen(str) > t->wideflag)
		i = t->sizeflag - t->wideflag;
	if (i > 0)
		t->len += i;
	if (t->minusflag == 1)
	{
		ft_putstr(str, t);
		while (i-- > 0)
			write(1, &c, 1);
	}
	else
	{
		while (i-- > 0)
			write(1, &c, 1);
		ft_putstr(str, t);
	}
}

void	printc(t_struct *t)
{
	char	c;
	int		i;

	t->i++;
	if (t->xflag == -1)
		c = '%';
	else
		c = va_arg(t->arg, int);
	t->len++;
	i = t->sizeflag - 1;
	if (i > 0)
		t->len += i;
	if (t->minusflag == 1)
	{
		write(1, &c, 1);
		while (i-- > 0)
			write(1, " ", 1);
	}
	else
	{
		while (i-- > 0)
			write(1, " ", 1);
		write(1, &c, 1);
	}
}

void	prints(t_struct *t)
{
	char	*str;

	t->i++;
	if (!(str = va_arg(t->arg, char *)))
		str = "(null)";
	if (t->sizeflag > ft_strlen(str) || t->dotflag == 1)
		ft_putsstr(str, t);
	else
		ft_putstr(str, t);
}
