/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asegovia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:43:32 by asegovia          #+#    #+#             */
/*   Updated: 2019/12/12 14:33:34 by asegovia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_struct
{
	int			i;
	va_list		arg;
	int			len;
	const char	*str;
	int			minusflag;
	int			oflag;
	int			dotflag;
	int			starflag;
	int			sizeflag;
	int			wideflag;
	int			xflag;
}				t_struct;

int				ft_printf(const char *str, ...);
int				ft_strlen(const char *s);
int				ft_atoi(const char *str);
char			*ft_strchr(const char *s, int c);
void			ft_putstr(char *str, t_struct *t);
void			ft_putnstr(char *str, t_struct *t);
void			ft_putsstr(char *str, t_struct *t);
void			iflags(t_struct *t);
void			printc(t_struct *t);
void			prints(t_struct *t);
void			flags(t_struct *t);
void			dflags(t_struct *t);
void			types(t_struct *t);
void			iflags(t_struct *t);
void			struct_init(const char *str, t_struct *t);
void			printp(t_struct *t);
char			*ft_itoa_base(unsigned long value, t_struct *t);
void			printp(t_struct *t);
void			printd(t_struct *t);
char			*ft_strdup(const char *s1);
void			ft_putstro(char *str, t_struct *t);
char			*ft_itoa(int n, t_struct *t);
void			printd(t_struct *t);
void			printu(t_struct *t);
void			printx(t_struct *t);
void			printper(t_struct *t);
char			*ft_itoa_x(unsigned int value, t_struct *t);
void			ft_dstr(char *str, t_struct *t);
char			*ft_strjoin(char const *s1, char const *s2);
void			star(t_struct *t);
char			*ft_itoau(unsigned int n);

#endif
