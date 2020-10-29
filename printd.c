/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:13:29 by asegovia          #+#    #+#             */
/*   Updated: 2019/12/12 14:41:53 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putstro(char *str, t_struct *t)
{
	int		n;
	int		i;
	char	*str2;

	n = 0;
	i = t->wideflag - ft_strlen(str);
	if (!(str2 = malloc(sizeof(char) * (i + ft_strlen(str) + t->xflag))))
		return ;
	if (t->xflag == 1 && (n = 1))
		str2[0] = '-';
	t->xflag = 0;
	while (i-- != 0)
		str2[n++] = '0';
	i = 0;
	while (str[i] != '\0')
		str2[n++] = str[i++];
	str2[n] = '\0';
	t->wideflag = -1;
	if (t->sizeflag < ft_strlen(str2))
		ft_putstr(str2, t);
	else
		ft_dstr(str2, t);
	free(str2);
}

void		ft_dstr(char *str, t_struct *t)
{
	int i;

	i = t->sizeflag - ft_strlen(str);
	if (t->minusflag == 1)
	{
		ft_putstr(str, t);
		t->len += i;
		while (i-- > 0)
			write(1, " ", 1);
	}
	else
	{
		t->len += i;
		while (i-- > 0)
			write(1, " ", 1);
		ft_putstr(str, t);
	}
}

static int	ft_intlen(int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n, t_struct *t)
{
	long int	nb;
	int			i;
	char		*str;

	nb = n;
	if (n < 0 && (t->xflag = 1))
		nb = -nb;
	i = ft_intlen(nb);
	if (nb == 0)
		return (ft_strdup((const char*)"0"));
	if (!(str = malloc(sizeof(char) * ft_intlen(nb) + 1)))
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

void		printd(t_struct *t)
{
	int		n;
	char	*str;

	t->i++;
	n = va_arg(t->arg, int);
	str = ft_itoa(n, t);
	if (t->dotflag == 1 && *str == '0')
		str = ft_strdup("");
	if (t->wideflag < ft_strlen(str))
		t->wideflag = ft_strlen(str);
	if ((t->oflag == 0 || t->sizeflag < ft_strlen(str)) && t->wideflag == -1)
	{
		if (t->xflag == 1)
			str = ft_strjoin("-", str);
		ft_dstr(str, t);
		free(str);
		return ;
	}
	if (t->oflag == 1 && t->dotflag == 1)
		t->dotflag = 0;
	else if (t->oflag == 1 && t->sizeflag > t->wideflag
			&& t->sizeflag > ft_strlen(str))
		t->wideflag = t->sizeflag - t->xflag;
	ft_putstro(str, t);
	free(str);
}
