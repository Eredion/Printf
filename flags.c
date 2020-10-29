/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:45:14 by asegovia          #+#    #+#             */
/*   Updated: 2019/12/11 17:46:39 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	dflag(t_struct *t)
{
	t->dotflag = 1;
	t->i++;
	t->wideflag = 0;
	if (t->str[t->i] == '*')
	{
		t->wideflag = va_arg(t->arg, int);
		if (t->wideflag < 0 && (t->dotflag = 0))
			t->wideflag = -1;
		t->i++;
	}
	if (t->str[t->i] >= '0' && t->str[t->i] <= '9')
	{
		t->wideflag = ft_atoi(&t->str[t->i]);
		while (t->str[t->i] >= '0' && t->str[t->i] <= '9')
			t->i++;
	}
	if (t->str[t->i] == '%' && (t->xflag = -1))
		printper(t);
}

void	flags(t_struct *t)
{
	t->i++;
	while (t->str[t->i] == '0' && (t->oflag = 1))
		t->i++;
	while (t->str[t->i] == '-' && (t->minusflag = 1))
		t->i++;
	while (t->str[t->i] == '0' && (t->oflag = 1))
		t->i++;
	if (t->str[t->i] == '*')
		star(t);
	if (t->str[t->i] >= '0' && t->str[t->i] <= '9')
	{
		t->sizeflag = ft_atoi(&t->str[t->i]);
		while (t->str[t->i] >= '0' && t->str[t->i] <= '9')
			t->i++;
	}
	if (t->str[t->i] == '.')
		dflag(t);
	else if (t->str[t->i] == '%' && (t->xflag = -1))
		printper(t);
}

void	types(t_struct *t)
{
	iflags(t);
	flags(t);
	if (t->xflag == -1)
		return ;
	if (t->str[t->i] == 'c')
		printc(t);
	if (t->str[t->i] == 's')
		prints(t);
	if (t->str[t->i] == 'p')
		printp(t);
	if (t->str[t->i] == 'd' || t->str[t->i] == 'i')
		printd(t);
	if (t->str[t->i] == 'u')
		printu(t);
	if (t->str[t->i] == 'X')
		t->xflag = 1;
	if (t->str[t->i] == 'x' || t->str[t->i] == 'X')
		printx(t);
}

void	iflags(t_struct *t)
{
	t->minusflag = 0;
	t->wideflag = 0;
	t->dotflag = 0;
	t->starflag = 0;
	t->sizeflag = 0;
	t->wideflag = -1;
	t->oflag = 0;
	t->xflag = 0;
}

void	struct_init(const char *str, t_struct *t)
{
	t->str = str;
	t->i = 0;
	t->len = 0;
}
