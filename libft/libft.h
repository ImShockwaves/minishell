/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:39:26 by ccharrie          #+#    #+#             */
/*   Updated: 2018/02/05 16:05:11 by ccharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define BUFF_SIZE 7

# define BLACK "\033[22;30m"
# define GREEN "\033[22;32m"
# define YELLOW "\033[01;33m"
# define BLUE "\033[22;34m"
# define MAGENTA "\033[22;35m"
# define CYAN "\033[22;36m"
# define GRAY "\033[22;37m"
# define DARK_GRAY "\033[01;30m"
# define RED "\033[01;31m"
# define LIGHT_RED "\033[01;31m"
# define LIGHT_GREEN "\033[01;32m"
# define YELLOW "\033[01;33m"
# define LIGHT_BLUE "\033[01;34m"
# define LIGHT_MAGENTA "\033[01;35m"
# define LIGHT_CYAN "\033[01;36m"
# define WHITE "\033[01;37m"
# define BG_BLACK "\033[40m"
# define BG_RED "\033[41m"
# define BG_GREEN "\033[42m"
# define BG_YELLOW "\033[43m"
# define BG_BLUE "\033[44m"
# define BG_PINK "\033[45m"
# define BG_CYAN "\033[46m"
# define BG_GRAY "\033[47m"
# define BOLD "\033[1m"
# define UNDERLINE "\033[4m"
# define BLINK "\033[5m"
# define HIGHLIGHT "\033[7m"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_del2tab(char **tab1, char **tab2);
int					ft_tablen(char **tab);
void				ft_2strdel(char **as, char **as1);
char				*ft_strjoinndels1(char *s1, char *s2);
char				**ft_resizetab(char **tab, char *str);
void				ft_puttab(char **tab);
char				**ft_splitwhitespaces(char const *s);
int					get_next_line(const int fd, char **line);
void				ft_del2tabs(char *s1, char *s2);
void				ft_del2dtab(char **tab);
char				*ft_strjoinnfree(char *s1, char *s2);
void				ft_putformat(char *str, char *color,
						char *background, char *format);
void				ft_putcformat(char str, char *color,
						char *background, char *format);
void				ft_putcolor(char *str, char *color);
int					ft_atoi(const char *str);
int					ft_isalpha(int str);
int					ft_isprint(int str);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *dest, int src, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t nb);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
int					ft_toupper(int str);
void				*ft_bzero(void *s, size_t n);
int					ft_isascii(int str);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strcpy(char *dest, const char *src);
size_t				ft_strlen(const char *str);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strstr(const char *str, const char *to_find);
int					ft_isalnum(int str);
int					ft_isdigit(int str);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strdup(const char *src);
char				*ft_strncat(char *dest, char *src, size_t nb);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
int					ft_tolower(int str);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(int c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(int c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_putnbrbase(int n, char *base);
int					ft_sqrt(int nb);
int					ft_recursive_pow(int nb, int power);
void				ft_lstaddend(t_list *lst, t_list *new);
void				ft_putlst(t_list *lst);

#endif
