/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:49:56 by asegovia          #+#    #+#             */
/*   Updated: 2019/12/12 14:26:53 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		printper(t_struct *t)
{
	char	c;
	int		i;

	if (t->oflag != 1 || t->minusflag == 1)
	{
		printc(t);
		return ;
	}
	t->i++;
	c = '%';
	t->len++;
	i = t->sizeflag - 1;
	while (i-- > 0)
	{
		write(1, "0", 1);
		t->len++;
	}
	write(1, &c, 1);
}

void		printu(t_struct *t)
{
	unsigned int	n;
	char			*str;

	t->i++;
	n = va_arg(t->arg, unsigned int);
	str = ft_itoau(n);
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

static int	ft_ulen(unsigned int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoau(unsigned int n)
{
	long unsigned int	nb;
	int					i;
	char				*str;

	nb = n;
	i = ft_ulen(nb);
	if (nb == 0)
		return (ft_strdup((const char*)"0"));
	if (!(str = malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i] = '\0';
	while (nb >= 10)
	{
		str[--i] = (nb % 10 + 48);
		nb /= 10;
	}
	str[--i] = (nb / 10 + 48);
	str[i] = (nb % 10 + 48);
	return (str);
}

void		star(t_struct *t)
{
	t->sizeflag = va_arg(t->arg, int);
	if (t->sizeflag < 0 && (t->minusflag = 1))
	{
		t->oflag = 0;
		t->sizeflag *= -1;
	}
	t->i++;
}
